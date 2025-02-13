#pragma once

#include "IEnergyStrategy.hpp"

class CSupplyFromStorageStrategy : public IEnergyStrategy
{
public:
    void manageEnergy(std::shared_ptr<IEnergyContext> context) override;
};