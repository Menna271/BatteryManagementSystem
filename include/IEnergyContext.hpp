#pragma once

#include "IObservable.hpp"

class IEnergyContext : public IObservable {
public:
    virtual double getPVPower() const = 0;
    virtual double getHouseConsumption() const = 0;
    virtual double getMaxCharge() const = 0;
    virtual double getMaxDischarge() const = 0;
    virtual bool isBatteryFull() = 0;
    virtual bool isBatteryLow() = 0;
    virtual void requestCharge(double power) = 0;
    virtual void requestDischarge(double power) = 0;
    virtual void sellToGrid(double power) = 0;
    virtual void buyFromGrid(double power) = 0;
    virtual ~IEnergyContext() = default;
};