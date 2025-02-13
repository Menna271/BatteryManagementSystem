add_library(SonnenBatterieLib
    CEnergyContext.cpp
    CHouse.cpp
    CPVPanel.cpp
    CReadConfig.cpp
    CStorageFactory.cpp
    CStorageSystem.cpp
    CSupplyFromPVStrategy.cpp
    CSupplyFromStorageStrategy.cpp
    CVendorABatteryAdapter.cpp
    CVendorBInverterAdapter.cpp
    CVendorXControllerAdapter.cpp
    CVendorABattery.cpp
    CVendorXController.cpp
)

add_executable(SonnenBatterie main.cpp)
target_link_libraries(SonnenBatterie SonnenBatterieLib)