#include "CSupplyFromPVStrategy.hpp"

void CSupplyFromPVStrategy::manageEnergy(std::shared_ptr<IEnergyContext> context) {
    std::cout << "manage energy by supplying from pv" << std::endl;
    double house_load = context->getHouseConsumption();
    double pv_power = context->getPVPower();
    double surplus = pv_power - house_load;
    double max_power = context->getMaxCharge();

    double charge_power = std::min(surplus, max_power);

    if (charge_power > 0 && !context->isBatteryFull()) {
        context->requestCharge(charge_power);
        context->sellToGrid(surplus - charge_power);
    } else {
        context->sellToGrid(surplus);
    }
    context->buyFromGrid(0.0);
}