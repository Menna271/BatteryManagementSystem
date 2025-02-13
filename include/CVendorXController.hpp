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

    void turn_cooler_on();
    void turn_cooler_off();

    void write_firmware_version(const std::string& ver);
    std::string read_firmware_version() const;

    bool getCoolerState();

private:
    std::unique_ptr<IEnergyStrategy> m_Strategy;
    std::string m_FirmwareVersion;
    bool m_isCoolerOn;
};