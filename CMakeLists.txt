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
    dimSafe_benchmark
    test/benchmark.cpp
)

add_executable(
    dimSafe_example
    examples/example.cpp
)

add_executable(
    dimSafe_test_arithmetic
    test/test_arithmetic.cpp
)

add_executable(
    dimSafe_test_dimension_math
    test/test_dimension_math.cpp
)

add_executable(
    dimSafe_test_comparisons
    test/test_comparisons.cpp
)

target_link_libraries(
    dimSafe_example
    PRIVATE
        dimSafe
)

target_link_libraries(
    dimSafe_benchmark
    PRIVATE
        dimSafe
)

target_link_libraries(
    dimSafe_test_arithmetic
    PRIVATE
        dimSafe
)

target_link_libraries(
    dimSafe_test_dimension_math
    PRIVATE
        dimSafe
)

target_link_libraries(
    dimSafe_test_comparisons
    PRIVATE
        dimSafe
)

add_test(
    NAME dimSafe_benchmark
    COMMAND dimSafe_benchmark
)

add_test(
    NAME dimSafe_test_arithmetic
    COMMAND dimSafe_test_arithmetic
)

add_test(
    NAME dimSafe_test_dimension_math
    COMMAND dimSafe_test_dimension_math
)

add_test(
    NAME dimSafe_test_comparisons
    COMMAND dimSafe_test_comparisons
)