#pragma once

#include <vector>
#include <algorithm>
#include <limits>
#include <iostream>

class CVendorABattery 
{
    struct Battery {
        double voltage ;
        double temp;
        const double max_power;
        const double max_temp;
        const double max_voltage;
        const double min_voltage;

        Battery(double v, double t, double mp, double maxv, double minv, double maxt)
            : voltage(v), temp(t), max_power(mp), max_voltage(maxv), min_voltage(minv), max_temp(maxt) {}
    };

    std::vector<Battery> batteries;

public:
    CVendorABattery(const int& count) : batteries(count, {13.8, 25.0, 1000.0, 13.8, 11.5, 65.0}) {}

    int battery_count() const { return batteries.size(); }
    double read_voltage(int index) const { return batteries[index].voltage; }
    double read_temperature(int index) const { return batteries[index].temp; }
    double read_max_power(int index) const { return batteries[index].max_power; }
    double read_max_temp() const;
    double read_max_volt(int index) const { return batteries[index].max_voltage; }
    double read_min_volt(int index) const {return batteries[index].min_voltage; }

    void write_voltage(int index, double v) { batteries[index].voltage = v; }
    void write_temperature(double t);
    
    bool are_batteries_full() const;
    bool are_batteries_low() const;

    double calc_charge_capacity() const;
    double calc_discharge_capacity() const;

    void vendorA_charge(double watts);
    void vendorA_discharge(double watts);
};