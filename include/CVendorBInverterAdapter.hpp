#pragma once

#include "CVendorBInverter.hpp"
#include "IInverter.hpp"

class CVendorBInverterAdapter : public IInverter
{
public:
    CVendorBInverterAdapter()
        : m_VendorInverter() {}

    void setCurrent(double current) override;
    void setPower(double power) override;
    void setGridVoltage(double volt) override;
    void setGridFreq(double freq) override;
    
    double getMaxChargePower() const override;
    double getChargeEfficiency() const override;
    double getDischargeEfficiency() const override;
    double getCurrent() const override;
    double getPower() const override;
    double getGridVoltage() const override;
    double getGridFreq() const override;

private:
    CVendorBInverter m_VendorInverter;
};