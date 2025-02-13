#include "CPVPanel.hpp"

void CPVPanel::updateMeasurements(double power, double volt, double current) {
    m_Power = power;
    m_Voltage = volt;
    m_Current = current;
    notifyObservers("pv.power", m_Power);
}

void CPVPanel::registerObserver(std::shared_ptr<IObserver> obs) {
    m_Observers.push_back(obs);
}

void CPVPanel::removeObserver(std::shared_ptr<IObserver> obs) {
    std::weak_ptr<IObserver> weakObs = obs;
    m_Observers.erase(
        std::remove_if(m_Observers.begin(), m_Observers.end(),
            [&weakObs](const std::weak_ptr<IObserver>& observer) {
                return observer.lock() == weakObs.lock(); 
            }),
        m_Observers.end());
}

void CPVPanel::notifyObservers(const std::string& field, double newValue) {
    if (shouldNotify(field, newValue)) {
        for (auto& observer : m_Observers) {
            if (auto obs = observer.lock()) {
                obs->onUpdate(field, newValue);
            }
        }
        m_LastValues[field] = newValue;
    }
}

void CPVPanel::setNotificationThreshold(const std::string& field, double threshold) {
    m_NotificationThresholds[field] = threshold;
}

bool CPVPanel::shouldNotify(const std::string& field, double newValue) {
    if (!m_LastValues.count(field)) return true;
    return std::abs(newValue - m_LastValues[field]) >= m_NotificationThresholds[field];
}