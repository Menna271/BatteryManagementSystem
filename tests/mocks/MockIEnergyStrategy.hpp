#include <gmock/gmock.h>
#include "IEnergyStrategy.hpp"

class MockIEnergyStrategy : public IEnergyStrategy 
{
public:
    MOCK_METHOD(void, manageEnergy, (IEnergyContext* context), (override));
};