/** Copyright (c) 2012 GENIVI Alliance
 *  Copyright (c) 2012 BMW
 *
 *  \author Christian Mueller, BMW
 *
 *  \section license
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction,
 *  including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 *  subject to the following conditions:
 *  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
 *  THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef SOCKETHANDLER_H_
#define SOCKETHANDLER_H_

#include "audiomanagertypes.h"
#include <sys/socket.h>
#include <sys/time.h>
#include <stdint.h>
#include <sys/poll.h>
#include <list>
#include <map>
#include <signal.h>

namespace am
{

static volatile sig_atomic_t gDispatchDone = 0; //this global is used to stop the mainloop

typedef uint16_t sh_timerHandle_t; //!<this is a handle for a timer to be used with the SocketHandler
typedef uint16_t sh_pollHandle_t; //!<this is a handle for a filedescriptor to be used with the SocketHandler

class CAmShPollPrepare;
class CAmShPollCheck;
class CAmShPollFired;
class CAmShPollDispatch;
class CAmShTimerCallBack;

class CAmSocketHandler
{
public:
    CAmSocketHandler();
    virtual ~CAmSocketHandler();

    am_Error_e addFDPoll(const int fd, const short event, CAmShPollPrepare *prepare, CAmShPollFired *fired, CAmShPollCheck *check, CAmShPollDispatch *dispatch, void* userData, sh_pollHandle_t& handle);
    am_Error_e removeFDPoll(const sh_pollHandle_t handle);
    am_Error_e updateEventFlags(const sh_pollHandle_t handle, const short events);
    am_Error_e addTimer(const timespec timeouts, CAmShTimerCallBack*& callback, sh_timerHandle_t& handle, void* userData);
    am_Error_e removeTimer(const sh_timerHandle_t handle);
    am_Error_e restartTimer(const sh_timerHandle_t handle, const timespec timeouts);
    am_Error_e stopTimer(const sh_timerHandle_t handle);
    void start_listenting();
    void stop_listening();
private:
    struct sh_timer_s //!<struct that holds information of timers
    {
        sh_timerHandle_t handle; //!<the handle of the timer
        timespec countdown; //!<the countdown, this value is decreased every time the timer is up
        timespec timeout; //!<the original timer value
        CAmShTimerCallBack* callback; //!<the callbackfunction
        void * userData; //!<saves a void pointer together with the rest.
    };

    class CAmShSubstractTime //!<functor to easy substract from each countdown value
    {
    private:
        timespec param;
    public:
        CAmShSubstractTime(timespec param) :
                param(param){}
        void operator()(sh_timer_s& t) const;
    };

    struct sh_poll_s //!<struct that holds information about polls
    {
        sh_pollHandle_t handle; //!<handle to uniquely adress a filedesriptor
        CAmShPollPrepare *prepareCB;
        CAmShPollFired *firedCB;
        CAmShPollCheck *checkCB;
        CAmShPollDispatch *dispatchCB;
        pollfd pollfdValue; //!<the array for polling the filedescriptors
        void *userData; //!<userdata saved together with the callback.
    };

    typedef std::vector<pollfd> mListPollfd_t; //!<vector of filedescriptors
    typedef std::vector<sh_poll_s> mListPoll_t; //!<list for the callbacks

    class CAmShCopyPollfd
    {
    private:
        mListPollfd_t& mArray;
    public:
        CAmShCopyPollfd(mListPollfd_t& dest) :
                mArray(dest){}
        void operator()(const sh_poll_s& row);
    };

    bool fdIsValid(const int fd) const;
    void initTimer();
    void timerUp();
    int timespec2ms(const timespec& time);
    timespec* insertTime(timespec& buffertime);
    static bool compareCountdown(const sh_timer_s& a, const sh_timer_s& b)
    {
        return (a.countdown.tv_sec == b.countdown.tv_sec) ? (a.countdown.tv_nsec < b.countdown.tv_nsec) : (a.countdown.tv_sec < b.countdown.tv_sec);
    }

    static bool onlyFiredEvents(const pollfd& a)
    {
        return a.revents == 0 ? false : true;
    }

    //todo: maybe we could simplify mListActiveTimer to hold only the handle and the countdown ....
    mListPollfd_t mfdPollingArray;
    mListPoll_t mListPoll;
    std::list<sh_timer_s> mListTimer; //!<list of all timers
    std::list<sh_timer_s> mListActiveTimer; //!<list of all currently active timers
    sh_timerHandle_t mNextTimer;
    sh_timerHandle_t mLastInsertedHandle;
    sh_pollHandle_t mLastInsertedPollHandle;
    bool mRecreatePollfds;
    timespec mTimeout;
};

/**
 * classic functor for the BasicTimerCallback
 */
class CAmShTimerCallBack
{
public:
    virtual void Call(const sh_timerHandle_t handle, void* userData)=0;
    virtual ~CAmShTimerCallBack(){};
};

class CAmShPollPrepare
{
public:
    virtual void Call(const sh_pollHandle_t handle, void* userData)=0;
    virtual ~CAmShPollPrepare(){};
};

class CAmShPollFired
{
public:
    virtual void Call(const pollfd pollfd, const sh_pollHandle_t handle, void* userData)=0;
    virtual ~ CAmShPollFired(){};
};

class CAmShPollCheck
{
public:
    virtual bool Call(const sh_pollHandle_t handle, void* userData)=0;
    virtual ~ CAmShPollCheck(){};
};

class CAmShPollDispatch
{
public:
    virtual bool Call(const sh_pollHandle_t handle, void* userData)=0;
    virtual ~ CAmShPollDispatch() {};
};

/**
 * template to create the functor for a class
 */
template<class TClass> class TAmShTimerCallBack: public CAmShTimerCallBack
{
private:
    TClass* mInstance;
    void (TClass::*mFunction)(sh_timerHandle_t handle, void* userData);

public:
    TAmShTimerCallBack(TClass* instance, void(TClass::*function)(sh_timerHandle_t handle, void* userData)) :
            mInstance(instance),//
            mFunction(function) {};

    virtual void Call(sh_timerHandle_t handle, void* userData)
    {
        (*mInstance.*mFunction)(handle, userData);
    }
};

/**
 * template to create the functor for a class
 */
template<class TClass> class TAmShPollPrepare: public CAmShPollPrepare
{
private:
    TClass* mInstance;
    void (TClass::*mFunction)(const sh_timerHandle_t handle, void* userData);

public:
    TAmShPollPrepare(TClass* instance, void(TClass::*function)(const sh_timerHandle_t handle, void* userData)) :
            mInstance(instance), //
            mFunction(function){};

    virtual void Call(const sh_timerHandle_t handle, void* userData)
    {
        (*mInstance.*mFunction)(handle, userData);
    };
};

template<class TClass> class TAmShPollFired: public CAmShPollFired
{
private:
    TClass* mInstance;
    void (TClass::*mFunction)(const pollfd pollfd, const sh_pollHandle_t handle, void* userData);

public:
    TAmShPollFired(TClass* instance, void(TClass::*function)(const pollfd pollfd, const sh_pollHandle_t handle, void* userData)) :
            mInstance(instance), //
            mFunction(function){};

    virtual void Call(const pollfd pollfd, const sh_pollHandle_t handle, void* userData)
    {
        (*mInstance.*mFunction)(pollfd, handle, userData);
    };
};

template<class TClass> class TAmShPollCheck: public CAmShPollCheck
{
private:
    TClass* mInstance;
    bool (TClass::*mFunction)(const sh_pollHandle_t handle, void* userData);

public:
    TAmShPollCheck(TClass* instance, bool(TClass::*function)(const sh_pollHandle_t handle, void* userData)) :
            mInstance(instance), //
            mFunction(function){};

    virtual bool Call(const sh_pollHandle_t handle, void* userData)
    {
        return (*mInstance.*mFunction)(handle, userData);
    };
};

template<class TClass> class TAmShPollDispatch: public CAmShPollDispatch
{
private:
    TClass* mInstance;
    bool (TClass::*mFunction)(const sh_pollHandle_t handle, void* userData);

public:
    TAmShPollDispatch(TClass* instance, bool(TClass::*function)(const sh_pollHandle_t handle, void* userData)) :
            mInstance(instance), //
            mFunction(function) {};

    virtual bool Call(const sh_pollHandle_t handle, void* userData)
    {
        return (*mInstance.*mFunction)(handle, userData);
    };
};
} /* namespace am */
#endif /* SOCKETHANDLER_H_ */