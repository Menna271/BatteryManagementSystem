cmake_minimum_required(VERSION 3.10)

# Set the project name
project(MyProject)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Option to enable sanitizers
option(ENABLE_SANITIZERS "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

# Add sanitizer flags if enabled
if(ENABLE_SANITIZERS)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        # Add AddressSanitizer and UndefinedBehaviorSanitizer
        add_compile_options(-fsanitize=address,undefined)
        add_link_options(-fsanitize=address,undefined)
        
        # Add extra flags for better diagnostics
        add_compile_options(-fno-omit-frame-pointer)
        add_compile_options(-fno-optimize-sibling-calls)
        
        # Link against the sanitizer runtime
        link_libraries(-fsanitize=address,undefined)
    else()
        message(WARNING "Sanitizers are only supported with GCC or Clang.")
    endif()
endif()

# Create the executable
add_executable(MyExecutable ${SOURCES})