#cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
#find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
#add_executable(runTests krtest.cpp)
#target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

cmake_minimum_required(VERSION 3.14)
project(gtest)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Create the test binary
add_executable(runTests gtests.cpp)

# Link with Google Test
target_link_libraries(runTests GTest::gtest_main)

# Discover and run tests
include(GoogleTest)
gtest_discover_tests(runTests)

