#include "CSupplyFromStorageStrategy.hpp"

void CSupplyFromStorageStrategy::manageEnergy(std::shared_ptr<IEnergyContext> context) {
    std::cout << "manage energy by supplying from storage" << std::endl;
    double house_load = context->getHouseConsumption();
    double pv_power = context->getPVPower();
    double deficit = house_load - pv_power;
    double max_discharge = context->getMaxDischarge();

    double discharge_power = std::min(deficit, max_discharge);

    if (discharge_power > 0 && !context->isBatteryLow()) {
        context->requestDischarge(discharge_power);
        context->buyFromGrid(deficit - discharge_power);
    } else {
        context->buyFromGrid(deficit);
    }
    context->sellToGrid(0.0);
}