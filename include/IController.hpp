#pragma once

#include <string>
#include "CSupplyFromPVStrategy.hpp"
#include "CSupplyFromStorageStrategy.hpp"

class IController : public IObserver
{
public:
    //virtual void setStrategy(std::unique_ptr<IEnergyStrategy> strategy) = 0;
    virtual void determineStrategy(IEnergyContext* context) = 0;
    virtual void executeStrategy(IEnergyContext* context) = 0;
    
    virtual void activateCooler() = 0;
    virtual void deactivateCooler() = 0;

    virtual void setFirmwareVersion(const std::string& ver) = 0;
    
    virtual std::string getFirmwareVersion() const = 0;
    
    virtual ~IController() = default;
};