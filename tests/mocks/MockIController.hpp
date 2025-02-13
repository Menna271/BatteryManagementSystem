#include <gmock/gmock.h>
#include "IController.hpp"

class MockIController : public IController {
    public:
        MOCK_METHOD(void, determineStrategy, (IEnergyContext* context), (override));
        MOCK_METHOD(void, executeStrategy, (IEnergyContext* context), (override));
        MOCK_METHOD(void, activateCooler, (), (override));
        MOCK_METHOD(void, deactivateCooler, (), (override));
        MOCK_METHOD(void, setFirmwareVersion, (const std::string& ver), (override));
        MOCK_METHOD(std::string, getFirmwareVersion, (), (const, override));
        MOCK_METHOD(void, onUpdate, (IObservable* source, const std::string& field, double value), (override));
    };