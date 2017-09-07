cmake_minimum_required(VERSION 3.2)
set(PROJECT_NAME_STR schach)
project(${PROJECT_NAME_STR})

set(CMAKE_MODULE_PATH ${schach_SOURCE_DIR}/CMake)

set(CMAKE_CXX_FLAGS "-g -Wall")

# see: https://crascit.com/2015/03/28/enabling-cxx11-in-cmake/
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#-------------------
# schach target
#-------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")
file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)  # depreciated
add_executable(${PROJECT_NAME_STR} ${SRC_FILES})


#-------------------
# Test
#-------------------
# see: https://github.com/Crascit/DownloadProject

# include(CTest)  # automatically call enable_testing() + several new targets

enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES} ${SRC_FILES})
# add_dependencies(${PROJECT_TEST_NAME} ${PROJECT_NAME_STR})

# Downloading external modules at configure time (not build time!)
include(CMake/DownloadProject.cmake)
download_project(PROJ                googletest
                 GIT_REPOSITORY      https://github.com/google/googletest.git
                 GIT_TAG             master
                 UPDATE_DISCONNECTED 1
)
# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})

add_executable(square_test test/square_test.cpp)
target_link_libraries(square_test gtest)
add_test(NAME square COMMAND square_test)

# target_link_libraries(example gtest gmock_main)
# add_test(NAME "AllTests" 
#          COMMAND ${PROJECT_TEST_NAME} 
#          WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})