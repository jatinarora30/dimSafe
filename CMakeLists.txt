cmake_minimum_required(VERSION 3.16)

project(
    dimSafe
    VERSION 0.1.0
    LANGUAGES CXX
)

# ------------------------------------------------------------
# Header-only library
# ------------------------------------------------------------

add_library(dimSafe INTERFACE)

target_compile_features(dimSafe INTERFACE cxx_std_20)

target_include_directories(
    dimSafe
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

target_compile_options(
    dimSafe
    INTERFACE
        -O3
        -march=native
        -flto
)

# ------------------------------------------------------------
# Compiler warnings
# ------------------------------------------------------------

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(
        dimSafe
        INTERFACE
            -Wall
            -Wextra
            -Wpedantic
    )
elseif(MSVC)
    target_compile_options(
        dimSafe
        INTERFACE
            /W4
    )
endif()

# ------------------------------------------------------------
# Tests
# ------------------------------------------------------------

enable_testing()

add_executable(
    dimSafe_tests
    test/test.cpp
)

target_link_libraries(
    dimSafe_tests
    PRIVATE
        dimSafe
)

add_test(
    NAME dimSafe_tests
    COMMAND dimSafe_tests
)