/**
 * Copyright (C) 2011, BMW AG
 *
 * GeniviAudioMananger AudioManagerDaemon
 *
 * \file CAmDatabaseObserver.h
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

#ifndef DATABASEOBSERVER_H_
#define DATABASEOBSERVER_H_

#include <audiomanagertypes.h>
#include <queue>
#include "shared/CAmSerializer.h"

namespace am
{

class CAmTelnetServer;
class CAmCommandSender;
class CAmRoutingSender;
class CAmSocketHandler;

/**
 * This class observes the Database and notifies other classes about important events, mainly the CommandSender.
 */

class CAmDatabaseObserver
{
public:
    CAmDatabaseObserver(CAmCommandSender *iCommandSender, CAmRoutingSender *iRoutingSender, CAmSocketHandler *iSocketHandler);
    CAmDatabaseObserver(CAmCommandSender *iCommandSender, CAmRoutingSender *iRoutingSender, CAmSocketHandler *iSocketHandler, CAmTelnetServer *iTelnetServer);
    ~CAmDatabaseObserver();
    void numberOfSinkClassesChanged();
    void numberOfSourceClassesChanged();
    void newSink(const am_Sink_s& sink);
    void newSource(const am_Source_s& source);
    void newDomain(const am_Domain_s& domain);
    void newGateway(const am_Gateway_s& gateway);
    void newCrossfader(const am_Crossfader_s& crossfader);
    void newMainConnection(const am_MainConnectionType_s& mainConnection);
    void removedMainConnection(const am_mainConnectionID_t mainConnection);
    void removedSink(const am_sinkID_t sinkID, const bool visible);
    void removedSource(const am_sourceID_t sourceID, const bool visible);
    void removeDomain(const am_domainID_t domainID);
    void removeGateway(const am_gatewayID_t gatewayID);
    void removeCrossfader(const am_crossfaderID_t crossfaderID);
    void mainConnectionStateChanged(const am_mainConnectionID_t connectionID, const am_ConnectionState_e connectionState);
    void mainSinkSoundPropertyChanged(const am_sinkID_t sinkID, const am_MainSoundProperty_s& SoundProperty);
    void mainSourceSoundPropertyChanged(const am_sourceID_t sourceID, const am_MainSoundProperty_s& SoundProperty);
    void sinkAvailabilityChanged(const am_sinkID_t sinkID, const am_Availability_s& availability);
    void sourceAvailabilityChanged(const am_sourceID_t sourceID, const am_Availability_s& availability);
    void volumeChanged(const am_sinkID_t sinkID, const am_mainVolume_t volume);
    void sinkMuteStateChanged(const am_sinkID_t sinkID, const am_MuteState_e muteState);
    void systemPropertyChanged(const am_SystemProperty_s& SystemProperty);
    void timingInformationChanged(const am_mainConnectionID_t mainConnection, const am_timeSync_t time);

private:
    CAmCommandSender *mCommandSender; //!< pointer to the comandSender
    CAmRoutingSender* mRoutingSender; //!< pointer to the routingSender
    CAmTelnetServer* mTelnetServer; //!< pointer to the telnetserver
    CAmSerializer mSerializer;
};

}

#endif /* DATABASEOBSERVER_H_ */