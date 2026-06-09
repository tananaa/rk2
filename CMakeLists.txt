cmake_minimum_required(VERSION 3.10)
project(rk2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

file(GLOB SOURCES "src/*.cpp")
add_executable(observer ${SOURCES})

include(CPackConfig.cmake)

if(BUILD_TESTS)
    enable_testing()
    find_package(GTest REQUIRED)
    
    add_executable(tests tests/test_observer.cpp)
    target_link_libraries(tests GTest::gtest_main)
    target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    add_test(NAME tests COMMAND tests)
endif()

install(TARGETS observer DESTINATION bin)
