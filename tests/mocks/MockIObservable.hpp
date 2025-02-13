#include <gmock/gmock.h>
#include "IObservable.hpp"

class MockIObservable : public IObservable 
{
public:
    MOCK_METHOD(void, registerObserver, (std::shared_ptr<IObserver> obs), (override));
    MOCK_METHOD(void, removeObserver, (std::shared_ptr<IObserver> obs), (override));
    MOCK_METHOD(void, notifyObservers, (const std::string& field, double newValue), (override));
};