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
    //void onSafetyEvent(const std::string& message, bool critical) override;

private:
    CVendorXController m_ControllerX;
};