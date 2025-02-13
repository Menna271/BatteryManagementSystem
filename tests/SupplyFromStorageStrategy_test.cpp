#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "CSupplyFromStorageStrategy.hpp"
#include "MockIEnergyContext.hpp"  

using ::testing::Return;

TEST(SupplyFromStorageStrategyTest, BatteryIsLow) {
    MockIEnergyContext mockContext;
    CSupplyFromStorageStrategy strategy;

    EXPECT_CALL(mockContext, getPVPower())
        .Times(1)
        .WillOnce(Return(2500.0));

    EXPECT_CALL(mockContext, getHouseConsumption())
        .Times(1)
        .WillOnce(Return(3000.0));

    EXPECT_CALL(mockContext, getMaxDischarge())
        .Times(1)
        .WillOnce(Return(2000.0));

    EXPECT_CALL(mockContext, isBatteryLow())
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_CALL(mockContext, buyFromGrid(500.0))
        .Times(1);

    strategy.manageEnergy(&mockContext);
}

TEST(SupplyFromStorageStrategyTest, BatteryNotLow) {
    MockIEnergyContext mockContext;
    CSupplyFromStorageStrategy strategy;

    EXPECT_CALL(mockContext, getPVPower())
        .Times(1)
        .WillOnce(Return(2500.0));

    EXPECT_CALL(mockContext, getHouseConsumption())
        .Times(1)
        .WillOnce(Return(3000.0));

    EXPECT_CALL(mockContext, getMaxDischarge())
        .Times(1)
        .WillOnce(Return(2000.0));

    EXPECT_CALL(mockContext, isBatteryLow())
        .Times(1)
        .WillOnce(Return(false));

    EXPECT_CALL(mockContext, requestDischarge(500.0))
        .Times(1);

    EXPECT_CALL(mockContext, buyFromGrid(0.0))
        .Times(1);

    strategy.manageEnergy(&mockContext);
}
