#pragma once

#include <string>
#include "CSupplyFromPVStrategy.hpp"
#include "CSupplyFromStorageStrategy.hpp"

class IController : public IObserver
{
public:
    //virtual void setStrategy(std::unique_ptr<IEnergyStrategy> strategy) = 0;
    virtual void determineStrategy() = 0;
    virtual void executeStrategy() = 0;

    virtual void setFirmwareVersion(const std::string& ver) { m_FirmwareVersion = ver; }
    
    virtual std::string getFirmwareVersion() const { return m_FirmwareVersion; }
    
    virtual ~IController() = default;

protected: 
    std::string m_FirmwareVersion;
};