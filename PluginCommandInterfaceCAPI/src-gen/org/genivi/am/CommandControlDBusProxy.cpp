/*
* This file was generated by the CommonAPI Generators. 
* Used org.genivi.commonapi.core 2.1.2.201309301424.
* Used org.franca.core 0.8.9.201308271211.
*
*  Copyright (c) 2012 BMW
*  
*   \author Aleksandar Donchev, aleksander.donchev@partner.bmw.de BMW 2013
*  
*   \copyright
*   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction,
*   including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
*   subject to the following conditions:
*   The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
*   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
*   IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR
*   THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*    For further information see http://www.genivi.org/.
*  
*/
/**
 * The interface towards the Controlling Instance (e.g HMI). It handles the
 *  communication towards the HMI and other system components who need to interact
 *  with the audiomanagement.
There are two rules that have to be kept in mind
 *  when implementing against this interface:
 * @author Christian Mueller
 */
#include "CommandControlDBusProxy.h"

namespace org {
namespace genivi {
namespace am {

std::shared_ptr<CommonAPI::DBus::DBusProxy> createCommandControlDBusProxy(
                    const std::shared_ptr<CommonAPI::DBus::DBusFactory>& factory,
                    const std::string& commonApiAddress,
                    const std::string& interfaceName,
                    const std::string& busName,
                    const std::string& objectPath,
                    const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusProxyConnection) {
    return std::make_shared<CommandControlDBusProxy>(factory, commonApiAddress, interfaceName, busName, objectPath, dbusProxyConnection);
}

__attribute__((constructor)) void registerCommandControlDBusProxy(void) {
    CommonAPI::DBus::DBusFactory::registerProxyFactoryMethod(CommandControl::getInterfaceId(),
       &createCommandControlDBusProxy);
}

CommandControlDBusProxy::CommandControlDBusProxy(
                    const std::shared_ptr<CommonAPI::DBus::DBusFactory>& factory,
                    const std::string& commonApiAddress,
                    const std::string& interfaceName,
                    const std::string& busName,
                    const std::string& objectPath,
                    const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusProxyconnection):
        CommonAPI::DBus::DBusProxy(factory, commonApiAddress, interfaceName, busName, objectPath, dbusProxyconnection)
,        newMainConnection_(*this, "newMainConnection", "(qqqni)"),
        removedMainConnection_(*this, "removedMainConnection", "q"),
        newSink_(*this, "newSink", "(qs(iq)niq)"),
        removedSink_(*this, "removedSink", "q"),
        newSource_(*this, "newSource", "(qs(iq)q)"),
        removedSource_(*this, "removedSource", "q"),
        numberOfSinkClassesChanged_(*this, "numberOfSinkClassesChanged", ""),
        numberOfSourceClassesChanged_(*this, "numberOfSourceClassesChanged", ""),
        mainConnectionStateChanged_(*this, "mainConnectionStateChanged", "qi"),
        mainSinkSoundPropertyChanged_(*this, "mainSinkSoundPropertyChanged", "q(qn)"),
        mainSourceSoundPropertyChanged_(*this, "mainSourceSoundPropertyChanged", "q(qn)"),
        sinkAvailabilityChanged_(*this, "sinkAvailabilityChanged", "q(iq)"),
        sourceAvailabilityChanged_(*this, "sourceAvailabilityChanged", "q(iq)"),
        volumeChanged_(*this, "volumeChanged", "qn"),
        sinkMuteStateChanged_(*this, "sinkMuteStateChanged", "qi"),
        systemPropertyChanged_(*this, "systemPropertyChanged", "(qn)"),
        timingInformationChanged_(*this, "timingInformationChanged", "qn"),
        sinkUpdated_(*this, "sinkUpdated", "qqa(qn)"),
        sourceUpdated_(*this, "sourceUpdated", "qqa(qn)"),
        sinkNotification_(*this, "sinkNotification", "q(qn)"),
        sourceNotification_(*this, "sourceNotification", "q(qn)"),
        mainSinkNotificationConfigurationChanged_(*this, "mainSinkNotificationConfigurationChanged", "q(qin)"),
        mainSourceNotificationConfigurationChanged_(*this, "mainSourceNotificationConfigurationChanged", "q(qin)")
    {
    }


CommandControlDBusProxy::NewMainConnectionEvent& CommandControlDBusProxy::getNewMainConnectionEvent() {
    return newMainConnection_;
}
CommandControlDBusProxy::RemovedMainConnectionEvent& CommandControlDBusProxy::getRemovedMainConnectionEvent() {
    return removedMainConnection_;
}
CommandControlDBusProxy::NewSinkEvent& CommandControlDBusProxy::getNewSinkEvent() {
    return newSink_;
}
CommandControlDBusProxy::RemovedSinkEvent& CommandControlDBusProxy::getRemovedSinkEvent() {
    return removedSink_;
}
CommandControlDBusProxy::NewSourceEvent& CommandControlDBusProxy::getNewSourceEvent() {
    return newSource_;
}
CommandControlDBusProxy::RemovedSourceEvent& CommandControlDBusProxy::getRemovedSourceEvent() {
    return removedSource_;
}
CommandControlDBusProxy::NumberOfSinkClassesChangedEvent& CommandControlDBusProxy::getNumberOfSinkClassesChangedEvent() {
    return numberOfSinkClassesChanged_;
}
CommandControlDBusProxy::NumberOfSourceClassesChangedEvent& CommandControlDBusProxy::getNumberOfSourceClassesChangedEvent() {
    return numberOfSourceClassesChanged_;
}
CommandControlDBusProxy::MainConnectionStateChangedEvent& CommandControlDBusProxy::getMainConnectionStateChangedEvent() {
    return mainConnectionStateChanged_;
}
CommandControlDBusProxy::MainSinkSoundPropertyChangedEvent& CommandControlDBusProxy::getMainSinkSoundPropertyChangedEvent() {
    return mainSinkSoundPropertyChanged_;
}
CommandControlDBusProxy::MainSourceSoundPropertyChangedEvent& CommandControlDBusProxy::getMainSourceSoundPropertyChangedEvent() {
    return mainSourceSoundPropertyChanged_;
}
CommandControlDBusProxy::SinkAvailabilityChangedEvent& CommandControlDBusProxy::getSinkAvailabilityChangedEvent() {
    return sinkAvailabilityChanged_;
}
CommandControlDBusProxy::SourceAvailabilityChangedEvent& CommandControlDBusProxy::getSourceAvailabilityChangedEvent() {
    return sourceAvailabilityChanged_;
}
CommandControlDBusProxy::VolumeChangedEvent& CommandControlDBusProxy::getVolumeChangedEvent() {
    return volumeChanged_;
}
CommandControlDBusProxy::SinkMuteStateChangedEvent& CommandControlDBusProxy::getSinkMuteStateChangedEvent() {
    return sinkMuteStateChanged_;
}
CommandControlDBusProxy::SystemPropertyChangedEvent& CommandControlDBusProxy::getSystemPropertyChangedEvent() {
    return systemPropertyChanged_;
}
CommandControlDBusProxy::TimingInformationChangedEvent& CommandControlDBusProxy::getTimingInformationChangedEvent() {
    return timingInformationChanged_;
}
CommandControlDBusProxy::SinkUpdatedEvent& CommandControlDBusProxy::getSinkUpdatedEvent() {
    return sinkUpdated_;
}
CommandControlDBusProxy::SourceUpdatedEvent& CommandControlDBusProxy::getSourceUpdatedEvent() {
    return sourceUpdated_;
}
CommandControlDBusProxy::SinkNotificationEvent& CommandControlDBusProxy::getSinkNotificationEvent() {
    return sinkNotification_;
}
CommandControlDBusProxy::SourceNotificationEvent& CommandControlDBusProxy::getSourceNotificationEvent() {
    return sourceNotification_;
}
CommandControlDBusProxy::MainSinkNotificationConfigurationChangedEvent& CommandControlDBusProxy::getMainSinkNotificationConfigurationChangedEvent() {
    return mainSinkNotificationConfigurationChanged_;
}
CommandControlDBusProxy::MainSourceNotificationConfigurationChangedEvent& CommandControlDBusProxy::getMainSourceNotificationConfigurationChangedEvent() {
    return mainSourceNotificationConfigurationChanged_;
}

/**
 * connects a source to sink
(at)return E_OK on success, E_NOT_POSSIBLE on
 *  failure, E_ALREADY_EXISTS if the connection does already exists
 */
void CommandControlDBusProxy::connect(const am_sourceID_t& sourceID, const am_sinkID_t& sinkID, CommonAPI::CallStatus& callStatus, am_mainConnectionID_t& mainConnectionID, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sourceID_t, am_sinkID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_mainConnectionID_t, am_Error_e> >::callMethodWithReply(
        *this,
        "connect",
        "qq",
        sourceID, sinkID, 
        callStatus
        , mainConnectionID, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::connectAsync(const am_sourceID_t& sourceID, const am_sinkID_t& sinkID, ConnectAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sourceID_t, am_sinkID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_mainConnectionID_t, am_Error_e> >::callMethodAsync(
        *this,
        "connect",
        "qq",
        sourceID, sinkID, 
        std::move(callback));
}
/**
 * disconnects a mainConnection
(at)return E_OK on successes, E_NON_EXISTENT if
 *  the connection does not exist, E_NOT_POSSIBLE on error.
 */
void CommandControlDBusProxy::disconnect(const am_mainConnectionID_t& mainConnectionID, CommonAPI::CallStatus& callStatus, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_mainConnectionID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodWithReply(
        *this,
        "disconnect",
        "q",
        mainConnectionID, 
        callStatus
        , error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::disconnectAsync(const am_mainConnectionID_t& mainConnectionID, DisconnectAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_mainConnectionID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodAsync(
        *this,
        "disconnect",
        "q",
        mainConnectionID, 
        std::move(callback));
}
/**
 * sets the volume for a sink
(at)return E_OK on success, E_UNKOWN on error,
 *  E_OUT_OF_RANGE in case the value is out of range
 */
void CommandControlDBusProxy::setVolume(const am_sinkID_t& sinkID, const am_mainVolume_t& volume, CommonAPI::CallStatus& callStatus, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t, am_mainVolume_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodWithReply(
        *this,
        "setVolume",
        "qn",
        sinkID, volume, 
        callStatus
        , error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::setVolumeAsync(const am_sinkID_t& sinkID, const am_mainVolume_t& volume, SetVolumeAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t, am_mainVolume_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodAsync(
        *this,
        "setVolume",
        "qn",
        sinkID, volume, 
        std::move(callback));
}
/**
 * This function is used to increment or decrement the current volume for a
 *  sink.
(at)return E_OK on success, E_UNKNOWN on error and E_OUT_OF_RANGE if
 *  the value is not in the given volume range.
 */
void CommandControlDBusProxy::volumeStep(const am_sinkID_t& sinkID, const int16_t& volumeStep_, CommonAPI::CallStatus& callStatus, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t, int16_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodWithReply(
        *this,
        "volumeStep",
        "qn",
        sinkID, volumeStep_, 
        callStatus
        , error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::volumeStepAsync(const am_sinkID_t& sinkID, const int16_t& volumeStep_, VolumeStepAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t, int16_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodAsync(
        *this,
        "volumeStep",
        "qn",
        sinkID, volumeStep_, 
        std::move(callback));
}
/**
 * sets the mute state of a sink
(at)return E_OK on success, E_UNKNOWN on error.
 *  If the mute state is already the desired one, the Daemon will return E_OK.
 */
void CommandControlDBusProxy::setSinkMuteState(const am_sinkID_t& sinkID, const am_MuteState_e& muteState, CommonAPI::CallStatus& callStatus, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t, am_MuteState_e>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodWithReply(
        *this,
        "setSinkMuteState",
        "qi",
        sinkID, muteState, 
        callStatus
        , error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::setSinkMuteStateAsync(const am_sinkID_t& sinkID, const am_MuteState_e& muteState, SetSinkMuteStateAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t, am_MuteState_e>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodAsync(
        *this,
        "setSinkMuteState",
        "qi",
        sinkID, muteState, 
        std::move(callback));
}
/**
 * This method is used to set sound properties, e.g. Equalizer Values. Since the
 *  capabilities of the system can differ, the exact key value pairs can be
 *  extended in each product
(at)return E_OK on success, E_OUT_OF_RANGE if value
 *  exceeds range, E_UNKNOWN in case of an error
 */
void CommandControlDBusProxy::setMainSinkSoundProperty(const am_sinkID_t& sinkID, const am_MainSoundProperty_s& soundProperty, CommonAPI::CallStatus& callStatus, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t, am_MainSoundProperty_s>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodWithReply(
        *this,
        "setMainSinkSoundProperty",
        "q(qn)",
        sinkID, soundProperty, 
        callStatus
        , error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::setMainSinkSoundPropertyAsync(const am_sinkID_t& sinkID, const am_MainSoundProperty_s& soundProperty, SetMainSinkSoundPropertyAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t, am_MainSoundProperty_s>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodAsync(
        *this,
        "setMainSinkSoundProperty",
        "q(qn)",
        sinkID, soundProperty, 
        std::move(callback));
}
/**
 * This method is used to set sound properties, e.g. Equalizer Values. Since the
 *  capabilities of the system can differ, the exact key value pairs can be
 *  extended in each product
(at)return E_OK on success, E_OUT_OF_RANGE if value
 *  exceeds range, E_UNKNOWN in case of an error
 */
void CommandControlDBusProxy::setMainSourceSoundProperty(const am_sourceID_t& sourceID, const am_MainSoundProperty_s& soundProperty, CommonAPI::CallStatus& callStatus, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sourceID_t, am_MainSoundProperty_s>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodWithReply(
        *this,
        "setMainSourceSoundProperty",
        "q(qn)",
        sourceID, soundProperty, 
        callStatus
        , error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::setMainSourceSoundPropertyAsync(const am_sourceID_t& sourceID, const am_MainSoundProperty_s& soundProperty, SetMainSourceSoundPropertyAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sourceID_t, am_MainSoundProperty_s>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodAsync(
        *this,
        "setMainSourceSoundProperty",
        "q(qn)",
        sourceID, soundProperty, 
        std::move(callback));
}
/**
 * is used to set a specific system property.
(at)return E_OK on success,
 *  E_OUT_OF_RANGE if value exceeds range, E_UNKNOWN in case of an error
 */
void CommandControlDBusProxy::setSystemProperty(const am_SystemProperty_s& property, CommonAPI::CallStatus& callStatus, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_SystemProperty_s>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodWithReply(
        *this,
        "setSystemProperty",
        "(qn)",
        property, 
        callStatus
        , error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::setSystemPropertyAsync(const am_SystemProperty_s& property, SetSystemPropertyAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_SystemProperty_s>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodAsync(
        *this,
        "setSystemProperty",
        "(qn)",
        property, 
        std::move(callback));
}
/**
 * returns the actual list of MainConnections
(at)return E_OK on success,
 *  E_DATABASE_ERROR on error
 */
void CommandControlDBusProxy::getListMainConnections(CommonAPI::CallStatus& callStatus, am_MainConnection_L& listConnections, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_MainConnection_L, am_Error_e> >::callMethodWithReply(
        *this,
        "getListMainConnections",
        "",
        callStatus
        , listConnections, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::getListMainConnectionsAsync(GetListMainConnectionsAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_MainConnection_L, am_Error_e> >::callMethodAsync(
        *this,
        "getListMainConnections",
        "",
        std::move(callback));
}
/**
 * returns the actual list of Sinks
(at)return E_OK on success, E_DATABASE_ERROR
 *  on error
 */
void CommandControlDBusProxy::getListMainSinks(CommonAPI::CallStatus& callStatus, am_SinkType_L& listMainSinks, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_SinkType_L, am_Error_e> >::callMethodWithReply(
        *this,
        "getListMainSinks",
        "",
        callStatus
        , listMainSinks, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::getListMainSinksAsync(GetListMainSinksAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_SinkType_L, am_Error_e> >::callMethodAsync(
        *this,
        "getListMainSinks",
        "",
        std::move(callback));
}
/**
 * returns the actual list of Sources
(at)return E_OK on success,
 *  E_DATABASE_ERROR on error
 */
void CommandControlDBusProxy::getListMainSources(CommonAPI::CallStatus& callStatus, am_SourceType_L& listMainSources, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_SourceType_L, am_Error_e> >::callMethodWithReply(
        *this,
        "getListMainSources",
        "",
        callStatus
        , listMainSources, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::getListMainSourcesAsync(GetListMainSourcesAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_SourceType_L, am_Error_e> >::callMethodAsync(
        *this,
        "getListMainSources",
        "",
        std::move(callback));
}
/**
 * This is used to retrieve all source sound properties related to a source.
 *  Returns a vector of the sound properties and values as pair
(at)return E_OK
 *  on success, E_DATABASE_ERROR on error
 */
void CommandControlDBusProxy::getListMainSinkSoundProperties(const am_sinkID_t& sinkID, CommonAPI::CallStatus& callStatus, am_MainSoundProperty_L& listSoundProperties, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_MainSoundProperty_L, am_Error_e> >::callMethodWithReply(
        *this,
        "getListMainSinkSoundProperties",
        "q",
        sinkID, 
        callStatus
        , listSoundProperties, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::getListMainSinkSoundPropertiesAsync(const am_sinkID_t& sinkID, GetListMainSinkSoundPropertiesAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_MainSoundProperty_L, am_Error_e> >::callMethodAsync(
        *this,
        "getListMainSinkSoundProperties",
        "q",
        sinkID, 
        std::move(callback));
}
/**
 * This is used to retrieve all source sound properties related to a
 *  source.
(at)return E_OK on success, E_DATABASE_ERROR on error
 */
void CommandControlDBusProxy::getListMainSourceSoundProperties(const am_sourceID_t& sourceID, CommonAPI::CallStatus& callStatus, am_MainSoundProperty_L& listSourceProperties, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sourceID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_MainSoundProperty_L, am_Error_e> >::callMethodWithReply(
        *this,
        "getListMainSourceSoundProperties",
        "q",
        sourceID, 
        callStatus
        , listSourceProperties, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::getListMainSourceSoundPropertiesAsync(const am_sourceID_t& sourceID, GetListMainSourceSoundPropertiesAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sourceID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_MainSoundProperty_L, am_Error_e> >::callMethodAsync(
        *this,
        "getListMainSourceSoundProperties",
        "q",
        sourceID, 
        std::move(callback));
}
/**
 * This is used to retrieve SourceClass Information of all source classes
 *  
(at)return E_OK on success, E_DATABASE_ERROR on error
 */
void CommandControlDBusProxy::getListSourceClasses(CommonAPI::CallStatus& callStatus, am_SourceClass_L& listSourceClasses, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_SourceClass_L, am_Error_e> >::callMethodWithReply(
        *this,
        "getListSourceClasses",
        "",
        callStatus
        , listSourceClasses, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::getListSourceClassesAsync(GetListSourceClassesAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_SourceClass_L, am_Error_e> >::callMethodAsync(
        *this,
        "getListSourceClasses",
        "",
        std::move(callback));
}
/**
 * This is used to retrieve SinkClass Information of all sink classes 
(at)return
 *  E_OK on success, E_DATABASE_ERROR on error
 */
void CommandControlDBusProxy::getListSinkClasses(CommonAPI::CallStatus& callStatus, am_SinkClass_L& listSinkClasses, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_SinkClass_L, am_Error_e> >::callMethodWithReply(
        *this,
        "getListSinkClasses",
        "",
        callStatus
        , listSinkClasses, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::getListSinkClassesAsync(GetListSinkClassesAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_SinkClass_L, am_Error_e> >::callMethodAsync(
        *this,
        "getListSinkClasses",
        "",
        std::move(callback));
}
/**
 * Retrieves a complete list of all systemProperties.
(at)return E_OK on success,
 *  E_DATABASE_ERROR on error
 */
void CommandControlDBusProxy::getListSystemProperties(CommonAPI::CallStatus& callStatus, am_SystemProperty_L& listSystemProperties, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_SystemProperty_L, am_Error_e> >::callMethodWithReply(
        *this,
        "getListSystemProperties",
        "",
        callStatus
        , listSystemProperties, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::getListSystemPropertiesAsync(GetListSystemPropertiesAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_SystemProperty_L, am_Error_e> >::callMethodAsync(
        *this,
        "getListSystemProperties",
        "",
        std::move(callback));
}
/**
 * returns the delay in ms that the audiopath for the given mainConnection
 *  has
(at)return E_OK on success, E_NOT_POSSIBLE if timing information is not
 *  yet retrieved, E_DATABASE_ERROR on read error on the database
 */
void CommandControlDBusProxy::getTimingInformation(const am_mainConnectionID_t& mainConnectionID, CommonAPI::CallStatus& callStatus, am_timeSync_t& delay, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_mainConnectionID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_timeSync_t, am_Error_e> >::callMethodWithReply(
        *this,
        "getTimingInformation",
        "q",
        mainConnectionID, 
        callStatus
        , delay, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::getTimingInformationAsync(const am_mainConnectionID_t& mainConnectionID, GetTimingInformationAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_mainConnectionID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_timeSync_t, am_Error_e> >::callMethodAsync(
        *this,
        "getTimingInformation",
        "q",
        mainConnectionID, 
        std::move(callback));
}
/**
 * Retrieves the list of MainNotifications for a sink. Does not return the
 *  possible ones.
 */
void CommandControlDBusProxy::getListMainSinkNotificationConfigurations(const am_sinkID_t& sinkID, CommonAPI::CallStatus& callStatus, am_NotificationConfiguration_L& listMainNotificationConfigurations, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_NotificationConfiguration_L, am_Error_e> >::callMethodWithReply(
        *this,
        "getListMainSinkNotificationConfigurations",
        "q",
        sinkID, 
        callStatus
        , listMainNotificationConfigurations, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::getListMainSinkNotificationConfigurationsAsync(const am_sinkID_t& sinkID, GetListMainSinkNotificationConfigurationsAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_NotificationConfiguration_L, am_Error_e> >::callMethodAsync(
        *this,
        "getListMainSinkNotificationConfigurations",
        "q",
        sinkID, 
        std::move(callback));
}
/**
 * Retrieves the list of MainNotifications for a source. Does not return the
 *  possible ones.
 */
void CommandControlDBusProxy::getListMainSourceNotificationConfigurations(const am_sourceID_t& sourceID, CommonAPI::CallStatus& callStatus, am_NotificationConfiguration_L& listMainNotificationConfigurations, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sourceID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_NotificationConfiguration_L, am_Error_e> >::callMethodWithReply(
        *this,
        "getListMainSourceNotificationConfigurations",
        "q",
        sourceID, 
        callStatus
        , listMainNotificationConfigurations, error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::getListMainSourceNotificationConfigurationsAsync(const am_sourceID_t& sourceID, GetListMainSourceNotificationConfigurationsAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sourceID_t>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_NotificationConfiguration_L, am_Error_e> >::callMethodAsync(
        *this,
        "getListMainSourceNotificationConfigurations",
        "q",
        sourceID, 
        std::move(callback));
}
/**
 * sets a MainNotificationConfiuration. This can be used to turn on an off
 *  notifications an to change the mode of the configuration.
(at)return E_OK on
 *  success, E_NON_EXISTENT if sinkID does not exists, E_DATABASE_ERROR on error
 */
void CommandControlDBusProxy::setMainSinkNotificationConfiguration(const am_sinkID_t& sinkID, const am_NotificationConfiguration_s& mainNotificationConfiguration, CommonAPI::CallStatus& callStatus, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t, am_NotificationConfiguration_s>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodWithReply(
        *this,
        "setMainSinkNotificationConfiguration",
        "q(qin)",
        sinkID, mainNotificationConfiguration, 
        callStatus
        , error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::setMainSinkNotificationConfigurationAsync(const am_sinkID_t& sinkID, const am_NotificationConfiguration_s& mainNotificationConfiguration, SetMainSinkNotificationConfigurationAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sinkID_t, am_NotificationConfiguration_s>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodAsync(
        *this,
        "setMainSinkNotificationConfiguration",
        "q(qin)",
        sinkID, mainNotificationConfiguration, 
        std::move(callback));
}
/**
 * sets a MainNotificationConfiuration. This can be used to turn on an off
 *  notifications an to change the mode of the configuration.
(at)return E_OK on
 *  success, E_NON_EXISTENT if sourceID does not exists, E_DATABASE_ERROR on error
 */
void CommandControlDBusProxy::setMainSourceNotificationConfiguration(const am_sourceID_t& sourceID, const am_NotificationConfiguration_s& mainNotificationConfiguration, CommonAPI::CallStatus& callStatus, am_Error_e& error) {
    CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sourceID_t, am_NotificationConfiguration_s>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodWithReply(
        *this,
        "setMainSourceNotificationConfiguration",
        "q(qin)",
        sourceID, mainNotificationConfiguration, 
        callStatus
        , error);
}
std::future<CommonAPI::CallStatus> CommandControlDBusProxy::setMainSourceNotificationConfigurationAsync(const am_sourceID_t& sourceID, const am_NotificationConfiguration_s& mainNotificationConfiguration, SetMainSourceNotificationConfigurationAsyncCallback callback) {
    return CommonAPI::DBus::DBusProxyHelper<CommonAPI::DBus::DBusSerializableArguments<am_sourceID_t, am_NotificationConfiguration_s>,
                                     CommonAPI::DBus::DBusSerializableArguments<am_Error_e> >::callMethodAsync(
        *this,
        "setMainSourceNotificationConfiguration",
        "q(qin)",
        sourceID, mainNotificationConfiguration, 
        std::move(callback));
}



void CommandControlDBusProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

} // namespace am
} // namespace genivi
} // namespace org