// SupplyFromPVStrategy_test.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "CSupplyFromPVStrategy.hpp"
#include "MockIEnergyContext.hpp"  

using ::testing::Return;

TEST(SupplyFromPVStrategyTest, ManageEnergyUsesPVPower) {
    MockIEnergyContext mockContext;
    CSupplyFromPVStrategy strategy;

    EXPECT_CALL(mockContext, getPVPower())
        .Times(1)
        .WillOnce(Return(2800.0));

    EXPECT_CALL(mockContext, getHouseConsumption())
        .Times(1)
        .WillOnce(Return(2500.0));

    EXPECT_CALL(mockContext, getMaxCharge())
        .Times(1)
        .WillOnce(Return(2200.0));

    EXPECT_CALL(mockContext, isBatteryFull())
        .Times(1)
        .WillOnce(Return(false));
    
    EXPECT_CALL(mockContext, requestCharge(300.0))
        .Times(1);

    EXPECT_CALL(mockContext, sellToGrid(0.0))
        .Times(1);

    strategy.manageEnergy(&mockContext);
}
