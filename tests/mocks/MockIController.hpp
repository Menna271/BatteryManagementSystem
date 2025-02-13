#include <gmock/gmock.h>
#include "IController.hpp"

class MockIController : public IController {
    public:
        MOCK_METHOD(void, determineStrategy, (IEnergyContext* context), (override));
        MOCK_METHOD(void, executeStrategy, (IEnergyContext* context), (override));
        // IObserver method:
        MOCK_METHOD(void, onUpdate, (IObservable* source, const std::string& field, double value), (override));
    };