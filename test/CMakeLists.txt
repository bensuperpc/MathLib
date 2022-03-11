cmake_minimum_required(VERSION 3.14)

project(mathlibTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)
include(../cmake/windows-set-path.cmake)

if(PROJECT_IS_TOP_LEVEL)
  find_package(mathlib REQUIRED)
  enable_testing()
endif()

#add_executable(MathLib_test source/MathLib_test.cpp)
#target_link_libraries(MathLib_test PRIVATE mathlib::mathlib)
#target_compile_features(MathLib_test PRIVATE cxx_std_17)

#add_test(NAME MathLib_test COMMAND MathLib_test)

function(add_test_fn TEST_NAME)
  add_executable("${TEST_NAME}" "source/${TEST_NAME}.cpp")
  target_link_libraries("${TEST_NAME}" PRIVATE mathlib::mathlib gtest_main)
  add_test("${TEST_NAME}" "${TEST_NAME}")
  # target_compile_features("${TEST_NAME}" PRIVATE cxx_std_17)
endfunction()

function(add_bench_fn BENCH_NAME)
  add_executable("${BENCH_NAME}" "source/${BENCH_NAME}.cpp")
  target_link_libraries("${BENCH_NAME}" PRIVATE mathlib::mathlib benchmark::benchmark_main)
  add_test("${BENCH_NAME}" "${BENCH_NAME}")
  # target_compile_features("${TEST_NAME}" PRIVATE cxx_std_17)
endfunction()


if(NOT WIN32)
  include(FetchContent)

  # Externally provided libraries
  FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG main)

  FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG main)

  # Disable tests on gtest
  set(gtest_build_tests
      OFF
      CACHE BOOL "" FORCE)
  set(gtest_build_samples
      OFF
      CACHE BOOL "" FORCE)

  # Disable tests on google benchmark
  set(BENCHMARK_ENABLE_TESTING
      OFF
      CACHE BOOL "" FORCE)
  set(BENCHMARK_ENABLE_WERROR
      OFF
      CACHE BOOL "" FORCE)
  set(BENCHMARK_FORCE_WERROR
      OFF
      CACHE BOOL "" FORCE)

  set(BENCHMARK_ENABLE_INSTALL
      OFF
      CACHE BOOL "" FORCE)

  set(BENCHMARK_DOWNLOAD_DEPENDENCIES
      ON
      CACHE BOOL "" FORCE)
      
  set(CMAKE_CXX_CLANG_TIDY "")

  FetchContent_MakeAvailable(googletest googlebenchmark)

  # Add tests
  add_test_fn(getSchwarzschild_test)
  add_test_fn(getGravitationalAttraction_test)
  add_test_fn(cylinder_test)
  add_test_fn(power_test)
  add_test_fn(sphere_test)

  # Lib: gtest gtest_main benchmark::benchmark benchmark::benchmark_main

  if(NOT CMAKE_BUILD_TYPE MATCHES Debug)
    #add_test(NAME find_string_inv_bench COMMAND find_string_inv_bench)
  elseif()
    message(STATUS "Disable crc32_bench, Performance benchmark test only run on Release/RelWithDebInfo/MinSizeRel")
  endif()

  #include(GoogleTest)
  #gtest_discover_tests(jamcrc_test)
else()
  message(WARNING "Disable tests, only supported on Linux")
endif()



add_folders(Test)
