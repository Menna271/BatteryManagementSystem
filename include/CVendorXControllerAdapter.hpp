#pragma once

#include "IController.hpp"
#include "CVendorXController.hpp"

class CVendorXControllerAdapter : public IController
{
public:
    CVendorXControllerAdapter() : m_ControllerX() {}

    void determineStrategy(IEnergyContext* context) override;
    void executeStrategy(IEnergyContext* context) override;

    void onUpdate(IObservable* source, const std::string& field, double value) override;
    
    void activateCooler() override;
    void deactivateCooler() override;
    void determineCoolerState();

    void setFirmwareVersion(const std::string& ver) override;
    
    std::string getFirmwareVersion() const override;

private:
    CVendorXController m_ControllerX;
};