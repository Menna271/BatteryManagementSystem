#include <gmock/gmock.h>
#include "IInverter.hpp"

class MockIInverter : public IInverter 
{
public:
    MOCK_METHOD(void, setCurrent, (double current), (override));
    MOCK_METHOD(void, setPower, (double power), (override));
    MOCK_METHOD(void, setGridVoltage, (double volt), (override));
    MOCK_METHOD(void, setGridFreq, (double freq), (override));
    MOCK_METHOD(double, getMaxChargePower, (), (const, override));
    MOCK_METHOD(double, getChargeEfficiency, (), (const, override));
    MOCK_METHOD(double, getDischargeEfficiency, (), (const, override));
    MOCK_METHOD(double, getCurrent, (), (const, override));
    MOCK_METHOD(double, getPower, (), (const, override));
    MOCK_METHOD(double, getGridVoltage, (), (const, override));
    MOCK_METHOD(double, getGridFreq, (), (const, override));
};