#include "CVendorXController.hpp"

void CVendorXController::setEnergySource() {
    double houseConsumption = m_Context->getHouseConsumption();
    double pvPower = m_Context->getPVPower();
    std::cout << "PV power: " << pvPower << " house consumption: " << houseConsumption << std::endl;
    if (pvPower > houseConsumption) {
        m_Strategy = std::make_unique<CSupplyFromPVStrategy>();
        std::cout << "Supply from PV" << std::endl;
    } else {
        m_Strategy = std::make_unique<CSupplyFromStorageStrategy>();
        std::cout << "Supply from Storage" << std::endl;
    }
    applyControlLogic();
}

void CVendorXController::applyControlLogic() {
    if(m_Strategy) {
        m_Strategy->manageEnergy(m_Context);
    }
}