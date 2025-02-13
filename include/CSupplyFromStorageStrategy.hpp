#pragma once

#include "IEnergyStrategy.hpp"

class CSupplyFromStorageStrategy : public IEnergyStrategy
{
public:
    void manageEnergy(IEnergyContext* context) override;
};