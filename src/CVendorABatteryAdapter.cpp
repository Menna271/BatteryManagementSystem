#include "CVendorABatteryAdapter.hpp"

void CVendorABatteryAdapter::setVoltage(int index, double voltage) {
    m_VendorBattery.write_voltage(index, voltage);
  //  checkVoltage(index, voltage);
}

void CVendorABatteryAdapter::setTemperature(int index, double temp) {
    m_VendorBattery.write_temperature(index, temp);
   // checkTemperature(index, temp);
}

void CVendorABatteryAdapter::updateMeasurements(const std::vector<double>& voltages,const std::vector<double>& temps) {
    for(size_t i = 0; i < m_VendorBattery.battery_count(); ++i) {
        setVoltage(i, voltages[i]);
        setTemperature(i, temps[i]);
    }
}

int CVendorABatteryAdapter::getNumberOfBatteries() const {
    m_VendorBattery.battery_count();
}

double CVendorABatteryAdapter::getVoltage(int index) const {
    m_VendorBattery.read_voltage(index);
}

double CVendorABatteryAdapter::getMaxPower(int index) const {
    m_VendorBattery.read_max_power(index);
}

double CVendorABatteryAdapter::getTemperature(int index) const {
    m_VendorBattery.read_temperature(index);
}

double CVendorABatteryAdapter::getMaxTemperature(int index) const {
    m_VendorBattery.read_max_temp(index);
}

double CVendorABatteryAdapter::getFullVoltage(int index) const {
    m_VendorBattery.read_max_volt(index);
}

double CVendorABatteryAdapter::getLowVoltage(int index) const {
    m_VendorBattery.read_min_volt(index);
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

// void CVendorABatteryAdapter::checkVoltage(int index, double volt) {
//     if(m_VendorBattery.is_voltage_below_threshold(index, volt)) {
//         for (auto& observer : m_Observers) {
//             if (auto obs = observer.lock()) {
//                 obs->onSafetyEvent(
//                     "Battery " + std::to_string(index) + 
//                     " low: " + std::to_string(volt), true
//                 );
//             }
//         }
//     }
// }

// void CVendorABatteryAdapter::checkTemperature(int index, double temp) {
//     if(m_VendorBattery.is_temp_above_threshold(index, temp)) {
//         for (auto& observer : m_Observers) {
//             if (auto obs = observer.lock()) {
//                 obs->onSafetyEvent(
//                     "Battery " + std::to_string(index) + 
//                     " overheating: " + std::to_string(temp), true
//                 );
//             }
//         }
//     }
// }