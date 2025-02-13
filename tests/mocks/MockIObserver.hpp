#include <gmock/gmock.h>
#include "IObserver.hpp"

class MockIObserver : public IObserver 
{
public:
    MOCK_METHOD(void, onUpdate, (IObservable* source, const std::string& field, double value), (override));
};