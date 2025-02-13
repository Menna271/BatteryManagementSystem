#pragma once 

#include <unordered_map>
#include <cmath> 
#include "CStorageFactory.hpp"
#include "IObserver.hpp"
#include "IEnergyContext.hpp"

class CStorageSystem : public std::enable_shared_from_this<CStorageSystem>
{
public:
    CStorageSystem(const std::string& filename);

    void initializeStorageSystem();
    void displayConfig();

    double calcMaxCharge() const;
    double calcMaxDischarge() const;

    bool isBatteryFull();
    bool isBatteryLow();

    void Charge(double power);     
    void Discharge(double power );  

    std::shared_ptr<IController> getController() const { return m_Controller; }

private:
    CStorageFactory m_Factory;
    std::unique_ptr<IBattery> m_BatteryModules;
    std::unique_ptr<IInverter> m_Inverter;
    std::shared_ptr<IController> m_Controller;
    int m_NumberOfBatteryModules;
};