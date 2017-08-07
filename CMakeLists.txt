cmake_minimum_required(VERSION 3.1)
set(PROJECT_NAME_STR schach)

project(${PROJECT_NAME_STR} C CXX)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    src
)

#-------------------
# set common include folder for module
#-------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/include)
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

set(
    CMAKE_LIBRARY_OUTPUT_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}/lib"
    CACHE
    PATH
    "Library output directory"
)

set(
    CMAKE_RUNTIME_OUTPUT_DIRECTORY
    "${CMAKE_CURRENT_SOURCE_DIR}/bin"
    CACHE
    PATH
    "Executable output directory"
)

add_executable(schach "${CMAKE_CURRENT_SOURCE_DIR}/src/schach.cpp")

# The following is taken from:
# see: https://github.com/snikulov/google-test-examples/blob/master/CMakeLists.txt

#-------------------
# Module source
#-------------------
#set(PROJECT_LIB_NAME ${PROJECT_NAME_STR}_impl)

#include_directories(${COMMON_INCLUDES})
# file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
#add_library(${PROJECT_LIB_NAME} ${SRC_FILES})

add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

#-------------------
# Test
#-------------------
# add_definitions(${MSVC_COMPILER_DEFS})

enable_testing()

set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES})
add_dependencies(${PROJECT_TEST_NAME} googletest)


if(NOT WIN32 OR MINGW)
    target_link_libraries(${PROJECT_TEST_NAME}
        ${GTEST_LIBS_DIR}/libgtest.a
        ${GTEST_LIBS_DIR}/libgtest_main.a
        )
else()
    target_link_libraries(${PROJECT_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
    target_link_libraries(${PROJECT_TEST_NAME}
        debug ${GTEST_LIBS_DIR}/DebugLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        optimized ${GTEST_LIBS_DIR}/ReleaseLibs/${CMAKE_FIND_LIBRARY_PREFIXES}gtest_main${CMAKE_FIND_LIBRARY_SUFFIXES}
        )
endif()

target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

add_test(NAME "AllTests" COMMAND ${PROJECT_TEST_NAME} WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})