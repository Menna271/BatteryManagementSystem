#pragma once

#include <string>
#include "CSupplyFromPVStrategy.hpp"
#include "CSupplyFromStorageStrategy.hpp"

class CVendorXController 
{
public:
    CVendorXController(std::shared_ptr<IEnergyContext> energyContext) 
    : m_Context(energyContext), m_Strategy(nullptr) {}

    void setEnergySource();
    void applyControlLogic();

private:
    std::shared_ptr<IEnergyContext> m_Context;
    std::unique_ptr<IEnergyStrategy> m_Strategy;
    std::string m_FirmwareVersion;
};