/**
 * @file test_getSchwarzschild.cpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief
 * @version 1.0.0
 * @date 2021-04-01
 *
 * MIT License
 *
 */

#include "MathLib/getSchwarzschild.hpp"

#include "MathLib/constant.hpp"
#include "gtest/gtest.h"

namespace schwarzschild = my::math::schwarzschild;

TEST(getSchwarzschild, basic_double_1)
{
  auto data1 =
      static_cast<long int>(schwarzschild::getSchwarzschild<double>(SUN_MASS));
  auto data2 = static_cast<long int>(2953);

  EXPECT_EQ(data1, data2);
}

TEST(getSchwarzschild, basic_double_2)
{
  auto data1 =
      static_cast<long int>(schwarzschild::getSchwarzschild<double>(0));
  auto data2 = static_cast<long int>(0);

  EXPECT_EQ(data1, data2);
}
