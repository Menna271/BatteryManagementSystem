#pragma once

#include <iostream>
#include <vector>

class IBattery
{
public:
    virtual void setVoltage(int index, double voltage) = 0;
    virtual void setTemperature(double temp) = 0;

    virtual int getNumberOfBatteries() const = 0;
    virtual double getVoltage(int index) const = 0;
    virtual double getMaxPower(int index) const = 0;
    virtual double getTemperature(int index) const = 0;
    virtual double getMaxTemperature() const = 0;
    virtual double getFullVoltage(int index) const = 0;
    virtual double getLowVoltage(int index) const = 0;

    virtual void charge(double power) = 0;
    virtual void discharge(double power) = 0;

    virtual bool isBatteryLow() const = 0;
    virtual bool isBatteryFull() const = 0;

    virtual double getBattChargeCapacity() const = 0;
    virtual double getBattDischargeCapacity() const = 0;

    virtual ~IBattery() = default;
};