#include "CVendorXControllerAdapter.hpp"

void CVendorXControllerAdapter::determineStrategy(IEnergyContext* context) {
    m_ControllerX.setEnergySource(context);
    executeStrategy(context);
}

void CVendorXControllerAdapter::executeStrategy(IEnergyContext* context) {
    m_ControllerX.applyControlLogic(context);
}

void CVendorXControllerAdapter::onUpdate(IObservable* source, const std::string& field, double value) {
    IEnergyContext* context = dynamic_cast<IEnergyContext*>(source);
    if(context) {
        determineStrategy(context);
    }
}