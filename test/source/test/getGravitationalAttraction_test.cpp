/**
 * @file test_getGravitationalAttraction.cpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief
 * @version 1.0.0
 * @date 2021-04-01
 *
 * MIT License
 *
 */

#include "mathlib/getGravitationalAttraction.hpp"

#include "gtest/gtest.h"
#include "mathlib/constant.hpp"

TEST(getSchwarzschild, basic_double_1) {
  auto data1 = static_cast<long int>(
      ben::math::ga::getGravitationalAttraction<double>(10000, 20000, 30000));
  auto data2 = static_cast<long int>(0);

  EXPECT_EQ(data1, data2);
}

auto main(int argc, char** argv) -> int {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}