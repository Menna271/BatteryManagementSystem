#pragma once

#include <iostream>
#include "IEnergyContext.hpp"

class IEnergyStrategy
{
public:
    virtual void manageEnergy(std::shared_ptr<IEnergyContext> context) = 0;
    virtual ~IEnergyStrategy() {}
};