/**
 * Copyright (C) 2011, BMW AG
 *
 * GeniviAudioMananger AudioManagerDaemon
 *
 * \file DLTWrapper.h
 *
 * \date 20-Oct-2011 3:42:04 PM
 * \author Christian Mueller (christian.ei.mueller@bmw.de)
 *
 * \section License
 * GNU Lesser General Public License, version 2.1, with special exception (GENIVI clause)
 * Copyright (C) 2011, BMW AG Christian Mueller  Christian.ei.mueller@bmw.de
 *
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License, version 2.1, as published by the Free Software Foundation.
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License, version 2.1, for more details.
 * You should have received a copy of the GNU Lesser General Public License, version 2.1, along with this program; if not, see <http://www.gnu.org/licenses/lgpl-2.1.html>.
 * Note that the copyright holders assume that the GNU Lesser General Public License, version 2.1, may also be applicable to programs even in cases in which the program is not a library in the technical sense.
 * Linking AudioManager statically or dynamically with other modules is making a combined work based on AudioManager. You may license such other modules under the GNU Lesser General Public License, version 2.1. If you do not want to license your linked modules under the GNU Lesser General Public License, version 2.1, you may use the program under the following exception.
 * As a special exception, the copyright holders of AudioManager give you permission to combine AudioManager with software programs or libraries that are released under any license unless such a combination is not permitted by the license of such a software program or library. You may copy and distribute such a system following the terms of the GNU Lesser General Public License, version 2.1, including this special exception, for AudioManager and the licenses of the other code concerned.
 * Note that people who make modified versions of AudioManager are not obligated to grant this special exception for their modified versions; it is their choice whether to do so. The GNU Lesser General Public License, version 2.1, gives permission to release a modified version without this exception; this exception also makes it possible to release a modified version which carries forward this exception.
 *
 */

#ifndef DLTWRAPPER_H_
#define DLTWRAPPER_H_

#include <dlt/dlt.h>
#include <string>

class DLTWrapper
{
public:
    static DLTWrapper* instance();
    void registerApp(const char *appid, const char * description);
    void registerContext(DltContext& handle, const char *contextid, const char * description);
    void unregisterContext(DltContext& handle);
    void init(DltLogLevelType loglevel, DltContext* context = NULL);
    void send();
    void append(const int8_t value);
    void append(const uint8_t value);
    void append(const int16_t value);
    void append(const uint16_t value);
    void append(const int32_t value);
    void append(const uint32_t value);
    void append(const char*& value);
    void append(const std::string& value);
    void append(const bool value);
    ~DLTWrapper();
private:
    DLTWrapper(); //is private because of singleton pattern
    DltContext mDltContext;
    DltContextData mDltContextData;
    static DLTWrapper* mDLTWrapper;

};

inline DLTWrapper* getWrapper()
{
    return DLTWrapper::instance();
}

template<typename T> void logInfo(T value)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_INFO);
    inst->append(value);
    inst->send();
}

template<typename T, typename T1> void logInfo(T value, T1 value1)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_INFO);
    inst->append(value);
    inst->append(value1);
    inst->send();
}

template<typename T, typename T1, typename T2> void logInfo(T value, T1 value1, T2 value2)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_INFO);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3> void logInfo(T value, T1 value1, T2 value2, T3 value3)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_INFO);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4> void logInfo(T value, T1 value1, T2 value2, T3 value3, T4 value4)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_INFO);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5> void logInfo(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_INFO);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> void logInfo(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_INFO);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> void logInfo(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_INFO);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->append(value7);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> void logInfo(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7, T8 value8)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_INFO);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->append(value7);
    inst->append(value8);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> void logInfo(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7, T8 value8, T9 value9)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->append(value7);
    inst->append(value8);
    inst->append(value9);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10> void logInfo(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7, T8 value8, T9 value9, T10 value10)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->append(value7);
    inst->append(value8);
    inst->append(value9);
    inst->append(value10);
    inst->send();
}

template<typename T> void logError(T value)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->send();
}

template<typename T, typename T1> void logError(T value, T1 value1)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->send();
}

template<typename T, typename T1, typename T2> void logError(T value, T1 value1, T2 value2)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3> void logError(T value, T1 value1, T2 value2, T3 value3)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4> void logError(T value, T1 value1, T2 value2, T3 value3, T4 value4)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5> void logError(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> void logError(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> void logError(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->append(value7);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> void logError(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7, T8 value8)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->append(value7);
    inst->append(value8);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> void logError(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7, T8 value8, T9 value9)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->append(value7);
    inst->append(value8);
    inst->append(value9);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10> void logError(T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7, T8 value8, T9 value9, T10 value10)
{
    DLTWrapper* inst(getWrapper());
    inst->init(DLT_LOG_ERROR);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->append(value7);
    inst->append(value8);
    inst->append(value9);
    inst->append(value10);
    inst->send();
}

template<typename T> void log(DltContext* const context, DltLogLevelType loglevel, T value)
{
    DLTWrapper* inst(getWrapper());
    inst->init(loglevel, context);
    inst->append(value);
    inst->send();
}

template<typename T, typename T1> void log(DltContext* const context, DltLogLevelType loglevel, T value, T1 value1)
{
    DLTWrapper* inst(getWrapper());
    inst->init(loglevel, context);
    inst->append(value);
    inst->append(value1);
    inst->send();
}

template<typename T, typename T1, typename T2> void log(DltContext* const context, DltLogLevelType loglevel, T value, T1 value1, T2 value2)
{
    DLTWrapper* inst(getWrapper());
    inst->init(loglevel, context);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3> void log(DltContext* const context, DltLogLevelType loglevel, T value, T1 value1, T2 value2, T3 value3)
{
    DLTWrapper* inst(getWrapper());
    inst->init(loglevel, context);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4> void log(DltContext* const context, DltLogLevelType loglevel, T value, T1 value1, T2 value2, T3 value3, T4 value4)
{
    DLTWrapper* inst(getWrapper());
    inst->init(loglevel, context);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5> void log(DltContext* const context, DltLogLevelType loglevel, T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5)
{
    DLTWrapper* inst(getWrapper());
    inst->init(loglevel, context);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> void log(DltContext* const context, DltLogLevelType loglevel, T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6)
{
    DLTWrapper* inst(getWrapper());
    inst->init(loglevel, context);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> void log(DltContext* const context, DltLogLevelType loglevel, T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7)
{
    DLTWrapper* inst(getWrapper());
    inst->init(loglevel, context);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->append(value7);
    inst->send();
}

template<typename T, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> void log(DltContext* const context, DltLogLevelType loglevel, T value, T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6, T7 value7, T8 value8)
{
    DLTWrapper* inst(getWrapper());
    inst->init(loglevel, context);
    inst->append(value);
    inst->append(value1);
    inst->append(value2);
    inst->append(value3);
    inst->append(value4);
    inst->append(value5);
    inst->append(value6);
    inst->append(value7);
    inst->append(value8);
    inst->send();
}

#endif /* DLTWRAPPER_H_ */