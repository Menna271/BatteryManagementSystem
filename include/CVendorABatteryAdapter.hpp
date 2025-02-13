#pragma once

#include "CVendorABattery.hpp"
#include "IBattery.hpp"
#include "IObservable.hpp"

class CVendorABatteryAdapter : public IBattery
{
public:
    CVendorABatteryAdapter(int count)
        : m_VendorBattery(count) {}

    void setVoltage(int index, double voltage) override;
    void setTemperature(double temp) override;

    int getNumberOfBatteries() const override;
    double getVoltage(int index) const override;
    double getMaxPower(int index) const override;
    double getTemperature(int index) const override;
    double getMaxTemperature() const override;
    double getFullVoltage(int index) const override;
    double getLowVoltage(int index) const override;

    bool isBatteryLow() const override;
    bool isBatteryFull() const override;

    double getBattChargeCapacity() const override;
    double getBattDischargeCapacity() const override;

    void charge(double power) override;
    void discharge(double power) override;

private:
    CVendorABattery m_VendorBattery;
};