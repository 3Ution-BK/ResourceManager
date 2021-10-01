cmake_minimum_required(VERSION 3.1.0)

project("ResourceManager"
        VERSION 1.0.0
        DESCRIPTION "Simple example of resource manager")

set(${PROJECT_NAME}_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/include")
set(${PROJECT_NAME}_MODULE_DIR "${CMAKE_SOURCE_DIR}/cmake")
set(${PROJECT_NAME}_SOURCE_DIR "${CMAKE_SOURCE_DIR}/src")
set(${PROJECT_NAME}_UNITTEST_DIR "${CMAKE_SOURCE_DIR}/test")

add_subdirectory(src)

option(BUILD_TESTS "Build the unit test of the project" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
