#include "CStorageFactory.hpp"

CStorageFactory::CStorageFactory(const std::string& filename)
    : m_Config(filename)
{
}

std::shared_ptr<IController> CStorageFactory::createController() {
    std::string controller = m_Config.m_ControllerVendor;
    if(controller == "VendorX") {
        return std::make_shared<CVendorXControllerAdapter>();
    }
    throw std::invalid_argument("Unsupported vendor");
}

std::unique_ptr<IInverter> CStorageFactory::createInverter() {
    std::string inverter = m_Config.m_InverterVendor;
    if(inverter == "VendorB") {
        return std::make_unique<CVendorBInverterAdapter>();
    } 
    throw std::invalid_argument("Unsupported vendor");
}

std::unique_ptr<IBattery> CStorageFactory::createBattery() {
    std::string battery = m_Config.m_BatteryVendor;
    if(battery == "VendorA") {
        return std::make_unique<CVendorABatteryAdapter>(m_Config.m_NumberOfBatteryModules);
    }
    throw std::invalid_argument("Unsupported vendor");
}