#pragma once

#include "IEnergyStrategy.hpp"

class CSupplyFromPVStrategy : public IEnergyStrategy
{
public:
    void manageEnergy(IEnergyContext* context) override;
};