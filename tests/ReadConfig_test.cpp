#include <gtest/gtest.h>
#include "CReadConfig.hpp"

TEST(ReadConfigTest, ReadsValidConfiguration) {
    ASSERT_NO_THROW({
        CReadConfig config("configA.json");
        auto jsonConfig = config.getJsonConfig();
        
        EXPECT_TRUE(jsonConfig.contains("controller_vendor"));
        EXPECT_TRUE(jsonConfig.contains("inverter_vendor"));
        EXPECT_TRUE(jsonConfig.contains("battery_vendor"));
        EXPECT_TRUE(jsonConfig.contains("storage_type"));
        EXPECT_TRUE(jsonConfig.contains("number_of_modules"));

        EXPECT_EQ(config.m_ControllerVendor, "VendorX");
        EXPECT_EQ(config.m_InverterVendor, "VendorB");
        EXPECT_EQ(config.m_BatteryVendor, "VendorA");
        EXPECT_EQ(config.m_TypeOfStorage, "Standard");
        EXPECT_EQ(config.m_NumberOfBatteryModules, 3);
    });
}
