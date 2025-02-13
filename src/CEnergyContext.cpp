#include "CEnergyContext.hpp"

void CEnergyContext::onUpdate(const std::string& field, double value) {
    // Store values with source id
    m_Values[field] = value;
    notifyObservers(field, value); 
}

double CEnergyContext::getPVPower() const {
    return m_Values.at("pv.power");
}

double CEnergyContext::getHouseConsumption() const {
    return m_Values.at("house.power");
}

void CEnergyContext::requestCharge(double power) {
    if (m_Storage) {
        m_Storage->Charge(power); // Charge the batteries
    }
}

void CEnergyContext::requestDischarge(double power) {
    if (m_Storage) {
        m_Storage->Discharge(power); // Discharge the batteries
    }
}

double CEnergyContext::getMaxCharge() const {
    if(m_Storage) {
        return m_Storage->calcMaxCharge();
    }
}

double CEnergyContext::getMaxDischarge() const {
    if(m_Storage) {
        return m_Storage->calcMaxDischarge();
    }
}

bool CEnergyContext::isBatteryFull() {
    if(m_Storage) {
        return m_Storage->isBatteryFull();
    }
}

bool CEnergyContext::isBatteryLow() {
    if(m_Storage) {
        return m_Storage->isBatteryLow();
    }
}

void CEnergyContext::sellToGrid(double power) {
    if (m_Grid) {
        m_Grid->sellPower(power); // Sell power to the grid
    }
}

void CEnergyContext::buyFromGrid(double power) {
    if (m_Grid) {
        m_Grid->buyPower(power); // Buy power from the grid
    }
}

void CEnergyContext::registerObserver(std::shared_ptr<IObserver> obs) {
    m_Observers.push_back(obs);
}

void CEnergyContext::removeObserver(std::shared_ptr<IObserver> obs) {
    std::weak_ptr<IObserver> weakObs = obs;
    m_Observers.erase(
        std::remove_if(m_Observers.begin(), m_Observers.end(),
            [&weakObs](const std::weak_ptr<IObserver>& observer) {
                return observer.lock() == weakObs.lock(); 
            }),
        m_Observers.end());
}

void CEnergyContext::notifyObservers(const std::string& field, double newValue) {
    for (auto& observer : m_Observers) {
        if (auto obs = observer.lock()) {
            obs->onUpdate(field, newValue);
        }
    }
}