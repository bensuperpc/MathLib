/**
 * @file float_test.cpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief Source: https://stackoverflow.com/q/27228813
 * @version 1.0.0
 * @date 2022-03-21
 *
 * MIT License
 *
 */

#include "mathlib/float.hpp"

#include "gtest/gtest.h"

TEST(are_aqual, basic_float_1)
{
  float data1 = 1.5f;
  float data2 = 1.5f;
  bool result = my::math::fp::are_aqual<float>(data1, data2);

  EXPECT_EQ(result, true);
}

TEST(are_aqual, basic_float_2)
{
  float data1 = 1.51541f;
  float data2 = 1.5f;
  bool result = my::math::fp::are_aqual<float>(data1, data2);

  EXPECT_EQ(result, false);
}

TEST(are_aqual, basic_double_1)
{
  double data1 = 1.5f;
  double data2 = 1.5f;
  bool result = my::math::fp::are_aqual<double>(data1, data2);

  EXPECT_EQ(result, true);
}

TEST(are_aqual, basic_double_2)
{
  double data1 = 1.51541f;
  double data2 = 1.5f;
  bool result = my::math::fp::are_aqual<double>(data1, data2);

  EXPECT_EQ(result, false);
}

TEST(are_aqual, basic_uint32_t_1)
{
  uint32_t data1 = 150;
  uint32_t data2 = 150;
  bool result = my::math::fp::are_aqual<uint32_t>(data1, data2);

  EXPECT_EQ(result, true);
}

TEST(are_aqual, basic_uint64_t_2)
{
  uint64_t data1 = 50;
  uint64_t data2 = 60;
  bool result = my::math::fp::are_aqual<uint64_t>(data1, data2);

  EXPECT_EQ(result, false);
}
