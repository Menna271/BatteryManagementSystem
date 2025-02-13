#pragma once

#include "IEnergyContext.hpp"
#include "IObserver.hpp"
#include "CStorageSystem.hpp"
#include "CGrid.hpp"

class CEnergyContext : public IEnergyContext, public IObserver 
{
public:
    CEnergyContext(std::shared_ptr<CStorageSystem> storage, std::shared_ptr<CGrid> grid)
        : m_Storage(storage), m_Grid(grid) {}

    void onUpdate(const std::string& field, double value) override;
    double getPVPower() const override;
    double getHouseConsumption() const override;
    void requestCharge(double power) override;
    void requestDischarge(double power) override;
    double getMaxCharge() const override;
    double getMaxDischarge() const override;
    bool isBatteryFull() override;
    bool isBatteryLow() override;
    void sellToGrid(double power) override;
    void buyFromGrid(double power) override;
    void registerObserver(std::shared_ptr<IObserver> obs) override;
    void removeObserver(std::shared_ptr<IObserver> obs) override;
    void notifyObservers(const std::string& field, double newValue) override;

private:
    std::unordered_map<std::string, double> m_Values = {{"pv.power", 0.0}, {"house.power", 0.0}};
    std::vector<std::weak_ptr<IObserver>> m_Observers;
    std::shared_ptr<CStorageSystem> m_Storage;
    std::shared_ptr<CGrid> m_Grid;
};