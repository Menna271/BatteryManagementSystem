#pragma once

#include "IObservable.hpp"
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <iostream>

class CPVPanel : public IObservable
{
public:
    CPVPanel() : m_Power(0.0), m_Voltage(230.0), m_Current(0.0) 
    {
        setNotificationThreshold("power", 100.0);
    }

    void updateMeasurements(double power, double volt, double current);

    void registerObserver(std::shared_ptr<IObserver> obs) override;
    void removeObserver(std::shared_ptr<IObserver> obs) override;
    void notifyObservers(const std::string& field, double newValue) override;

    void setNotificationThreshold(const std::string& field, double threshold);
    bool shouldNotify(const std::string& field, double newValue);

    double getPower() const { return m_Power; }
    double getVoltage() const { return m_Voltage; }
    double getCurrent() const { return m_Current; }

private:
    std::unordered_map<std::string, double> m_NotificationThresholds;
    std::unordered_map<std::string, double> m_LastValues;
    std::vector<std::weak_ptr<IObserver>> m_Observers;
    double m_Power; 
    double m_Voltage; 
    double m_Current; 
};