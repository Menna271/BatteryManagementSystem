#include "CEnergyContext.hpp"

CEnergyContext::CEnergyContext(std::shared_ptr<CStorageSystem> storage, std::shared_ptr<CGrid> grid)
: m_Storage(storage), 
  m_Grid(grid) 
{
    registerObserver(m_Storage->getController());
}

void CEnergyContext::onUpdate(IObservable* source, const std::string& field, double value) {
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
        m_Storage->Charge(power); 
    }
}

void CEnergyContext::requestDischarge(double power) {
    if (m_Storage) {
        m_Storage->Discharge(power); 
    }
}

double CEnergyContext::getMaxCharge() const {
    if(m_Storage) {
        return m_Storage->calcMaxCharge();
    } else {
        throw std::runtime_error("storage not initialized in energy context");
    }
}

double CEnergyContext::getMaxDischarge() const {
    if(m_Storage) {
        return m_Storage->calcMaxDischarge();
    } else {
        throw std::runtime_error("storage not initialized in energy context");
    }
}

bool CEnergyContext::isBatteryFull() {
    if(m_Storage) {
        return m_Storage->isBatteryFull();
    } else {
        throw std::runtime_error("storage not initialized in energy context");
    }
}

bool CEnergyContext::isBatteryLow() {
    if(m_Storage) {
        return m_Storage->isBatteryLow();
    } else {
        throw std::runtime_error("storage not initialized in energy context");
    }
}

void CEnergyContext::sellToGrid(double power) {
    if (m_Grid) {
        m_Grid->sellPower(power); 
    } else {
        throw std::runtime_error("storage not initialized in energy context");
    }
}

void CEnergyContext::buyFromGrid(double power) {
    if (m_Grid) {
        m_Grid->buyPower(power); 
    } else {
        throw std::runtime_error("storage not initialized in energy context");
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
            obs->onUpdate(this, field, newValue);
        }
    }
}

void CEnergyContext::setBatteryTemperature(double temp) {
    m_Storage->setBatteryTemp(temp);
    double maxTemp = m_Storage->getMaxBatteryTemp();
    if((m_Values["batt.temp"] < maxTemp && temp > maxTemp) ||
        (m_Values["batt.temp"] > maxTemp && temp < maxTemp)) {
        m_Values["batt.temp"] = temp;
        notifyObservers("batt.temp", temp);
    } 
}