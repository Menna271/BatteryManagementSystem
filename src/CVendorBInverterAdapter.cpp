#include "CVendorBInverterAdapter.hpp"

void CVendorBInverterAdapter::setCurrent(double current) {
    m_VendorInverter.write_current(current);
}

void CVendorBInverterAdapter::setPower(double power) {
    m_VendorInverter.write_power(power);
}

void CVendorBInverterAdapter::setGridVoltage(double volt) {
    m_VendorInverter.write_grid_voltage(volt);
}

void CVendorBInverterAdapter::setGridFreq(double freq) {
    m_VendorInverter.write_grid_freq(freq);
}

double CVendorBInverterAdapter::getMaxChargePower() const {
    return m_VendorInverter.read_max_charge_power();
}

double CVendorBInverterAdapter::getChargeEfficiency() const {
    return m_VendorInverter.read_charge_efficiency();
}

double CVendorBInverterAdapter::getDischargeEfficiency() const {
    return m_VendorInverter.read_discharge_efficiency();
}

double CVendorBInverterAdapter::getCurrent() const {
    return m_VendorInverter.read_current();
}

double CVendorBInverterAdapter::getPower() const {
    return m_VendorInverter.read_power();
}

double CVendorBInverterAdapter::getGridVoltage() const {
    return m_VendorInverter.read_grid_voltage();
}

double CVendorBInverterAdapter::getGridFreq() const {
    return m_VendorInverter.read_grid_freq();
}