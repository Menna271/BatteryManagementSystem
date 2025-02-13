#pragma once

#include <string>
#include "CSupplyFromPVStrategy.hpp"
#include "CSupplyFromStorageStrategy.hpp"

class CVendorXController 
{
public:
    CVendorXController() 
    : m_Strategy(nullptr) {}

    void setEnergySource(IEnergyContext* context);
    void applyControlLogic(IEnergyContext* context);

private:
    std::unique_ptr<IEnergyStrategy> m_Strategy;
    std::string m_FirmwareVersion;
};