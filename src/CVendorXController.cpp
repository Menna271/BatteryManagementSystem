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