// CHouse_test.cpp
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "CHouse.hpp"
#include "CPVPanel.hpp"
#include "MockIObserver.hpp"

using ::testing::_;

TEST(ObserverTest, HouseConsumptionChanges) {
    CHouse house;
    auto mockObserver = std::make_shared<MockIObserver>();

    // onUpdate is called when the threshold is exceeded
    EXPECT_CALL(*mockObserver, onUpdate(&house, "house.power", _))
        .Times(2);

    house.registerObserver(mockObserver);

    // threshold = 100.0
    house.updateMeasurements(3000.0, 230.0, 10.0, 60.0);
    house.updateMeasurements(2800.0, 230.0, 10.0, 60.0);
    house.updateMeasurements(2750.0, 230.0, 10.0, 60.0);
}

TEST(ObserverTest, PvPowerChanges) {
    CPVPanel panel;
    auto mockObserver = std::make_shared<MockIObserver>();

    // onUpdate is called when the threshold is exceeded
    EXPECT_CALL(*mockObserver, onUpdate(&panel, "pv.power", _))
        .Times(2);

    panel.registerObserver(mockObserver);

    // threshold = 100.0
    panel.updateMeasurements(3000.0, 230.0, 10.0);
    panel.updateMeasurements(2800.0, 230.0, 10.0);
    panel.updateMeasurements(2750.0, 230.0, 10.0);
}
