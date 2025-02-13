#pragma once

#include "CVendorABattery.hpp"
#include "IBattery.hpp"
#include "IObservable.hpp"

class CVendorABatteryAdapter : public IBattery
{
public:
    CVendorABatteryAdapter(int count)
        : m_VendorBattery(count) {}

    // IBattery implementation
    void setVoltage(int index, double voltage) override;
    void setTemperature(int index, double temp) override;

    void updateMeasurements(const std::vector<double>& voltages,const std::vector<double>& temps) override;

    int getNumberOfBatteries() const override;
    double getVoltage(int index) const override;
    double getMaxPower(int index) const override;
    double getTemperature(int index) const override;
    double getMaxTemperature(int index) const override;
    double getFullVoltage(int index) const override;
    double getLowVoltage(int index) const override;

    bool isBatteryLow() const override;
    bool isBatteryFull() const override;

    double getBattChargeCapacity() const override;
    double getBattDischargeCapacity() const override;
    // void checkVoltage(int index, double volt) override;
    // void checkTemperature(int index, double temp) override;

    void charge(double power) override;
    void discharge(double power) override;

private:
    CVendorABattery m_VendorBattery;
};