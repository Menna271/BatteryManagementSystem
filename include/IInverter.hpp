#pragma once

#include <iostream>

class IInverter
{
public:
    virtual void setCurrent(double current) = 0;
    virtual void setPower(double power) = 0;
    virtual void setGridVoltage(double volt) = 0;
    virtual void setGridFreq(double freq) = 0;

    virtual double getMaxChargePower() const = 0;
    virtual double getChargeEfficiency() const = 0;
    virtual double getDischargeEfficiency() const = 0;
    virtual double getCurrent() const = 0;
    virtual double getPower() const = 0;
    virtual double getGridVoltage() const = 0;
    virtual double getGridFreq() const = 0;

    virtual ~IInverter() = default;
};