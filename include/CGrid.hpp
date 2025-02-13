#pragma once 

#include "IObservable.hpp"

class CGrid 
{
public:
    CGrid() : m_Power(0.0), m_Voltage(230.0), m_Freq(60.0) {}

    void updateValues(double power, double volt, double freq) {
        m_Power = power;
        m_Voltage = volt;
        m_Freq = freq;
    }

    double getPower() const { return m_Power; }
    double getVoltage() const { return m_Voltage; }
    double getFreq() const { return m_Freq; }

    void sellPower(const double& power) {  } 
    void buyPower(const double& power) {  }

private:
    double m_Power; 
    double m_Voltage; 
    double m_Freq; 
};