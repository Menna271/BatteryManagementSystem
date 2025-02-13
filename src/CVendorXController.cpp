#include "CVendorXController.hpp"

void CVendorXController::setEnergySource(IEnergyContext* context) {
    double houseConsumption = context->getHouseConsumption();
    double pvPower = context->getPVPower();
    std::cout << "pv power: " << pvPower << " house consumption: " << houseConsumption << std::endl;
    if (pvPower > houseConsumption) {
        m_Strategy = std::make_unique<CSupplyFromPVStrategy>();
    } else {
        m_Strategy = std::make_unique<CSupplyFromStorageStrategy>();
    }
}

void CVendorXController::applyControlLogic(IEnergyContext* context) {
    if(m_Strategy) {
        m_Strategy->manageEnergy(context);
    }
}

void CVendorXController::turn_cooler_on() {
    std::cout << "Activating cooler" << std::endl;
    m_isCoolerOn = true;
}

void CVendorXController::turn_cooler_off() {
    std::cout << "Deactivating cooler" << std::endl;
    m_isCoolerOn = false;
}

void CVendorXController::write_firmware_version(const std::string& ver) {
    m_FirmwareVersion = ver;
}

std::string CVendorXController::read_firmware_version() const {
    return m_FirmwareVersion;
}

bool CVendorXController::getCoolerState() {
    return m_isCoolerOn;
}