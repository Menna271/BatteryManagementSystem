#include <gmock/gmock.h>
#include "IEnergyContext.hpp"

class MockIEnergyContext : public IEnergyContext {
    public:
        MOCK_METHOD(double, getPVPower, (), (const, override));
        MOCK_METHOD(double, getHouseConsumption, (), (const, override));
        MOCK_METHOD(double, getMaxCharge, (), (const, override));
        MOCK_METHOD(double, getMaxDischarge, (), (const, override));
        MOCK_METHOD(bool, isBatteryFull, (), (override));
        MOCK_METHOD(bool, isBatteryLow, (), (override));
        MOCK_METHOD(void, requestCharge, (double power), (override));
        MOCK_METHOD(void, requestDischarge, (double power), (override));
        MOCK_METHOD(void, setBatteryTemperature, (double temp), (override));
        MOCK_METHOD(void, sellToGrid, (double power), (override));
        MOCK_METHOD(void, buyFromGrid, (double power), (override));
        MOCK_METHOD(void, registerObserver, (std::shared_ptr<IObserver> obs), (override));
        MOCK_METHOD(void, removeObserver, (std::shared_ptr<IObserver> obs), (override));
        MOCK_METHOD(void, notifyObservers, (const std::string& field, double newValue), (override));
    };