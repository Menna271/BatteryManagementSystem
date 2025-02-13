#pragma once

#include "IInverter.hpp"

class CVendorBInverter
{
    struct Inverter {
        double current;
        double power;
        double grid_voltage;
        double grid_freq;
        const double max_charge_power;
        const double charge_efficiency;
        const double discharge_efficiency;

        Inverter(double c, double p, double gv, double gf, double mcp, double ce, double de)
            : current(c), power(p), grid_voltage(gv), grid_freq(gf), 
              max_charge_power(mcp), charge_efficiency(ce), discharge_efficiency(de) {}
    };

    Inverter inverter;

public:
    CVendorBInverter() : inverter(0.0, 0.0, 230.0, 60.0, 3000.0, 0.95, 0.90) {}

    double read_current() const { return inverter.current; }
    double read_power() const { return inverter.power; }
    double read_grid_voltage() const { return inverter.grid_voltage; }
    double read_grid_freq() const { return inverter.grid_freq; }
    double read_max_charge_power() const { return inverter.max_charge_power; }
    double read_charge_efficiency() const { return inverter.charge_efficiency; }
    double read_discharge_efficiency() const { return inverter.discharge_efficiency; }

    void write_current(double c) { inverter.current = c; }
    void write_power(double p) { inverter.power = p; }
    void write_grid_voltage(double v) { inverter.grid_voltage = v; }
    void write_grid_freq(double f) { inverter.grid_freq = f; }
};