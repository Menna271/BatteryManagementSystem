#include "CVendorXControllerAdapter.hpp"

void CVendorXControllerAdapter::determineStrategy() {
    m_ControllerX.setEnergySource();
}

void CVendorXControllerAdapter::executeStrategy() {
    m_ControllerX.applyControlLogic();
}

void CVendorXControllerAdapter::onUpdate(const std::string& field, double value) {
    determineStrategy();
}