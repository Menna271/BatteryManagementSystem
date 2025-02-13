find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(SonnenBatterieTests
    SupplyFromPVStrategy_test.cpp
    SupplyFromStorageStrategy_test.cpp
    ReadConfig_test.cpp
    Observer_test.cpp
    main.cpp  
)

target_link_libraries(SonnenBatterieTests SonnenBatterieLib ${GTEST_LIBRARIES} gmock gtest)

add_test(NAME SonnenBatterieTests COMMAND SonnenBatterieTests)