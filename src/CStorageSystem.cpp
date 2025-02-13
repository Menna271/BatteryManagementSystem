#include "CStorageSystem.hpp"

CStorageSystem::CStorageSystem(const std::string& filename)
    : m_Factory(filename),
      m_BatteryModules(nullptr),
      m_Inverter(nullptr),
      m_Controller(nullptr),
      m_NumberOfBatteryModules(1)
{
}

void CStorageSystem::initializeStorageSystem() {
    m_NumberOfBatteryModules = m_Factory.getNumberOfBatteryModules();
    m_BatteryModules = std::move(m_Factory.createBattery());
    m_Inverter = std::move(m_Factory.createInverter());
    m_Controller = std::move(m_Factory.createController());
    
    displayConfig();
}

void CStorageSystem::displayConfig() {
    std::cout << "*************** Storage System ***************\n"
    << "Specs: \n" 
    << "Inverter: " << m_Factory.getInverterVendor() << std::endl
    << "Battery: " << m_Factory.getBatteryVendor() << std::endl
    << "Controller: " << m_Factory.getControllerVendor() << std::endl
    << "Storage Type: " << m_Factory.getStorageType() << std::endl
    << "Number of Modules: " << m_NumberOfBatteryModules << std::endl;
}

double CStorageSystem::calcMaxCharge() const {
    double batteryCapacity = m_BatteryModules->getBattChargeCapacity();
    double invMaxPower = m_Inverter->getMaxChargePower();
    return std::min(batteryCapacity, invMaxPower);
}

double CStorageSystem::calcMaxDischarge() const {
    double batteryPower = m_BatteryModules->getBattDischargeCapacity();
    double invMaxPower = m_Inverter->getMaxChargePower();
    return std::min(batteryPower, invMaxPower);
}

void CStorageSystem::Charge(double power) {
    double efficiency = m_Inverter->getChargeEfficiency();
    m_Inverter->setPower(power*efficiency);
    m_BatteryModules->charge(power);
}

void CStorageSystem::Discharge(double power) {
    double efficiency = m_Inverter->getDischargeEfficiency();
    m_Inverter->setPower(-power*efficiency);
    m_BatteryModules->discharge(power);
}

bool CStorageSystem::isBatteryFull() {
    return m_BatteryModules->isBatteryFull();
}

bool CStorageSystem::isBatteryLow() {
    return m_BatteryModules->isBatteryLow();
}