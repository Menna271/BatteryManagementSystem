#include "CVendorXControllerAdapter.hpp"

void CVendorXControllerAdapter::determineStrategy(IEnergyContext* context) {
    m_ControllerX.setEnergySource(context);
    executeStrategy(context);
}

void CVendorXControllerAdapter::executeStrategy(IEnergyContext* context) {
    m_ControllerX.applyControlLogic(context);
}

void CVendorXControllerAdapter::onUpdate(IObservable* source, const std::string& field, double value) {
    if(field == "pv.power" || field == "house.power") {
        IEnergyContext* context = dynamic_cast<IEnergyContext*>(source);
        if(context) {
            determineStrategy(context);
        }
    } else if(field == "batt.temp") {
        determineCoolerState();
    }

}

void CVendorXControllerAdapter::determineCoolerState() {
    if(m_ControllerX.getCoolerState()) {
        deactivateCooler();
    } else {
        activateCooler();
    }
}
 
void CVendorXControllerAdapter::activateCooler() {
    m_ControllerX.turn_cooler_on();
}

void CVendorXControllerAdapter::deactivateCooler() {
    m_ControllerX.turn_cooler_off();
}

void CVendorXControllerAdapter::setFirmwareVersion(const std::string& ver) {
    m_ControllerX.write_firmware_version(ver);
}

std::string CVendorXControllerAdapter::getFirmwareVersion() const {
    return m_ControllerX.read_firmware_version();
}