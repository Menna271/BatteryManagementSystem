cmake_minimum_required(VERSION 3.10)
project(SonnenBatterie)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    include
    tests/mocks
)

add_subdirectory(src)
add_subdirectory(tests)