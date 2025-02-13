#pragma once

#include "CReadConfig.hpp"
#include "CVendorABatteryAdapter.hpp"
#include "CVendorBInverterAdapter.hpp"
#include "CVendorXControllerAdapter.hpp"
#include <memory>

class CStorageFactory
{
public:
    CStorageFactory(const std::string& filename);

    std::string getControllerVendor() const { return m_Config.m_ControllerVendor; }
    std::string getInverterVendor() const { return m_Config.m_InverterVendor; }
    std::string getBatteryVendor() const { return m_Config.m_BatteryVendor; }
    std::string getStorageType() const { return m_Config.m_TypeOfStorage; }
    int getNumberOfBatteryModules() const { return m_Config.m_NumberOfBatteryModules; }

    std::shared_ptr<IController> createController();
    std::unique_ptr<IInverter> createInverter();
    std::unique_ptr<IBattery> createBattery();

private:
    CReadConfig m_Config;
};