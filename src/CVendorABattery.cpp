#include "CVendorABattery.hpp"

void CVendorABattery::vendorA_charge(double watts) {
    std::cout << "Battery voltage before charge: " << batteries.front().voltage << std::endl;
    const double per_batt = watts / batteries.size();
    for(auto& batt : batteries) {
        batt.voltage += per_batt * 0.01;
        batt.voltage = std::min(batt.voltage, batt.max_voltage);
    }
    std::cout << "Battery voltage after charge: " << batteries.front().voltage << std::endl;
}

void CVendorABattery::vendorA_discharge(double watts) {
    std::cout << "Battery voltage before discharge: " << batteries.front().voltage << std::endl;
    const double per_batt = watts / batteries.size();
        for(auto& batt : batteries) {
            batt.voltage -= per_batt * 0.01;
            batt.voltage = std::max(batt.voltage, batt.min_voltage);
    }
    std::cout << "Battery voltage after discharge: " << batteries.front().voltage << std::endl;
}

bool CVendorABattery::are_batteries_full() const {
    return std::all_of(batteries.begin(), batteries.end(),
        [](const Battery& b) { return b.voltage >= b.max_voltage; });
}

bool CVendorABattery::are_batteries_low() const {
    return std::any_of(batteries.begin(), batteries.end(),
        [](const Battery& b) { return b.voltage <= b.min_voltage; });
}

double CVendorABattery::calc_charge_capacity() const {
    double available_capacity = 0;
    for (const auto& bat : batteries) {
        if (bat.voltage < bat.max_voltage) {
            available_capacity += bat.max_power;
        }
    }
    return available_capacity;
}

double CVendorABattery::calc_discharge_capacity() const {
    double available_power = 0;
    for (const auto& bat : batteries) {
        if (bat.voltage > bat.min_voltage) {
            available_power += bat.max_power;
        }
    }
    return available_power;
}