#include "CReadConfig.hpp"

CReadConfig::CReadConfig(const std::string& filename) {
    std::ifstream file(std::string(m_ConfigDir) + filename);
    if (file.is_open()) {
        file >> m_StorageConfig;
        file.close();

        from_json(m_StorageConfig, *this);
    } else {
        throw std::runtime_error("Could not open config file.");
    }
}

void from_json(const nlohmann::json& j, CReadConfig& config) {
    try {
        j.at("inverter_vendor").get_to(config.m_InverterVendor);
        j.at("battery_vendor").get_to(config.m_BatteryVendor);
        j.at("controller_vendor").get_to(config.m_ControllerVendor);
        j.at("storage_type").get_to(config.m_TypeOfStorage);
        j.at("number_of_modules").get_to(config.m_NumberOfBatteryModules);
    } catch (const nlohmann::json::out_of_range& e) {
        throw std::runtime_error("Missing key in StorageConfig: " + std::string(e.what()));
        std::exit(EXIT_FAILURE);
    } catch (const nlohmann::json::type_error& e) {
        throw std::runtime_error("Type mismatch in StorageConfig: " + std::string(e.what()));
        std::exit(EXIT_FAILURE);
    }
}