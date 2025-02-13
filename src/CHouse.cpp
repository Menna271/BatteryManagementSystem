#include "CHouse.hpp"

void CHouse::updateMeasurements(double power, double volt, double current, double freq) {
    m_Power = power;
    m_Voltage = volt;
    m_Current = current;
    m_Freq = freq;
    notifyObservers("house.power", m_Power);
}

void CHouse::registerObserver(std::shared_ptr<IObserver> obs) {
    m_Observers.push_back(obs);
}

void CHouse::removeObserver(std::shared_ptr<IObserver> obs) {
    std::weak_ptr<IObserver> weakObs = obs;
    m_Observers.erase(
        std::remove_if(m_Observers.begin(), m_Observers.end(),
            [&weakObs](const std::weak_ptr<IObserver>& observer) {
                return observer.lock() == weakObs.lock(); 
            }),
        m_Observers.end());
}

void CHouse::notifyObservers(const std::string& field, double newValue) {
    if (shouldNotify(field, newValue)) {
        for (auto& observer : m_Observers) {
            if (auto obs = observer.lock()) {
                obs->onUpdate(this, field, newValue);
            }
        }
        m_LastValues[field] = newValue;
    }
}

void CHouse::setNotificationThreshold(const std::string& field, double threshold) {
    m_NotificationThresholds[field] = threshold;
}

bool CHouse::shouldNotify(const std::string& field, double newValue) {
    if (!m_LastValues.count(field)) return true;
    return std::abs(newValue - m_LastValues[field]) >= m_NotificationThresholds[field];
}