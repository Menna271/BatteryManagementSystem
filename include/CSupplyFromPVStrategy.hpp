#pragma once

#include "IEnergyStrategy.hpp"

class CSupplyFromPVStrategy : public IEnergyStrategy
{
public:
    void manageEnergy(std::shared_ptr<IEnergyContext> context) override;
};