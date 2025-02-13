#include "CVendorABatteryAdapter.hpp"

void CVendorABatteryAdapter::setVoltage(int index, double voltage) {
    m_VendorBattery.write_voltage(index, voltage);
  //  checkVoltage(index, voltage);
}

void CVendorABatteryAdapter::setTemperature(double temp) {
    m_VendorBattery.write_temperature(temp);
}

int CVendorABatteryAdapter::getNumberOfBatteries() const {
    return m_VendorBattery.battery_count();
}

double CVendorABatteryAdapter::getVoltage(int index) const {
    return m_VendorBattery.read_voltage(index);
}

double CVendorABatteryAdapter::getMaxPower(int index) const {
    return m_VendorBattery.read_max_power(index);
}

double CVendorABatteryAdapter::getTemperature(int index) const {
    return m_VendorBattery.read_temperature(index);
}

double CVendorABatteryAdapter::getMaxTemperature() const {
    return m_VendorBattery.read_max_temp();
}

double CVendorABatteryAdapter::getFullVoltage(int index) const {
    return m_VendorBattery.read_max_volt(index);
}

double CVendorABatteryAdapter::getLowVoltage(int index) const {
    return m_VendorBattery.read_min_volt(index);
}

void CVendorABatteryAdapter::charge(double power) {
    m_VendorBattery.vendorA_charge(power);
}

void CVendorABatteryAdapter::discharge(double power) {
    m_VendorBattery.vendorA_discharge(power);
}

bool CVendorABatteryAdapter::isBatteryLow() const {
    return m_VendorBattery.are_batteries_low();
}

bool CVendorABatteryAdapter::isBatteryFull() const {
    return m_VendorBattery.are_batteries_full();
}

double CVendorABatteryAdapter::getBattChargeCapacity() const {
    return m_VendorBattery.calc_charge_capacity();
}

double CVendorABatteryAdapter::getBattDischargeCapacity() const {
    return m_VendorBattery.calc_discharge_capacity();
}