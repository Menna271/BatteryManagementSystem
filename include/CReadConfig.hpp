#pragma once

#include "json.hpp" 
#include <stdexcept>
#include <iostream>
#include <fstream>

class CReadConfig
{
public:
    CReadConfig(const std::string& filename);

    std::string m_InverterVendor;
    std::string m_BatteryVendor;
    std::string m_ControllerVendor;
    std::string m_TypeOfStorage;
    int m_NumberOfBatteryModules;

    nlohmann::json getJsonConfig() const { return m_StorageConfig; }

private:
    nlohmann::json m_StorageConfig;
    static constexpr const char* m_ConfigDir = "../ConfigFiles/";
};

void from_json(const nlohmann::json& j, CReadConfig& config);