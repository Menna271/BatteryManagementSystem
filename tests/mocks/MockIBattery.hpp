#include <gmock/gmock.h>
#include "IBattery.hpp"

class MockIBattery : public IBattery {
    public:
        MOCK_METHOD(void, setVoltage, (int index, double voltage), (override));
        MOCK_METHOD(void, setTemperature, (double temp), (override));
        MOCK_METHOD(int, getNumberOfBatteries, (), (const, override));
        MOCK_METHOD(double, getVoltage, (int index), (const, override));
        MOCK_METHOD(double, getMaxPower, (int index), (const, override));
        MOCK_METHOD(double, getTemperature, (int index), (const, override));
        MOCK_METHOD(double, getMaxTemperature, (), (const, override));
        MOCK_METHOD(double, getFullVoltage, (int index), (const, override));
        MOCK_METHOD(double, getLowVoltage, (int index), (const, override));
        MOCK_METHOD(void, charge, (double power), (override));
        MOCK_METHOD(void, discharge, (double power), (override));
        MOCK_METHOD(bool, isBatteryLow, (), (const, override));
        MOCK_METHOD(bool, isBatteryFull, (), (const, override));
        MOCK_METHOD(double, getBattChargeCapacity, (), (const, override));
        MOCK_METHOD(double, getBattDischargeCapacity, (), (const, override));
    };