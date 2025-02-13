#pragma once

#include <iostream>
#include "IEnergyContext.hpp"

class IEnergyStrategy
{
public:
    virtual void manageEnergy(IEnergyContext* context) = 0;
    virtual ~IEnergyStrategy() {}
};