cmake_minimum_required(VERSION 3.14)

project(MathLibTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)
include(../cmake/windows-set-path.cmake)

if(PROJECT_IS_TOP_LEVEL)
  find_package(MathLib REQUIRED)
  enable_testing()
endif()

add_executable(MathLib_test source/MathLib_test.cpp)
target_link_libraries(MathLib_test PRIVATE MathLib::MathLib)
target_compile_features(MathLib_test PRIVATE cxx_std_17)

add_test(NAME MathLib_test COMMAND MathLib_test)

add_folders(Test)
