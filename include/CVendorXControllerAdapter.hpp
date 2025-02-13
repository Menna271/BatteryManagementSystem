#pragma once

#include "IController.hpp"
#include "CVendorXController.hpp"

class CVendorXControllerAdapter : public IController
{
public:
    CVendorXControllerAdapter(std::shared_ptr<IEnergyContext> energyContext) : m_ControllerX(energyContext) {}

    void determineStrategy() override;
    void executeStrategy() override;

    void onUpdate(const std::string& field, double value) override;
    //void onSafetyEvent(const std::string& message, bool critical) override;

private:
    CVendorXController m_ControllerX;
};