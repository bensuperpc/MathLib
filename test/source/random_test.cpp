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

#include <cstdlib>

#include "mathlib/random.hpp"

#include "gtest/gtest.h"

#define EXPECT_IN_RANGE(VAL, MIN, MAX) \
  EXPECT_GE((VAL), (MIN)); \
  EXPECT_LE((VAL), (MAX))

#define ASSERT_IN_RANGE(VAL, MIN, MAX) \
  ASSERT_GE((VAL), (MIN)); \
  ASSERT_LE((VAL), (MAX))

/**
 * @brief Construct a new test case
 *
 */
TEST(random, basic_int_1)
{
  auto data1 = 0;
  auto data2 = 100;

  auto result = my::math::rand::random<int>(data1, data2);
  EXPECT_IN_RANGE(result, data1, data2);
}

/**
 * @brief Construct a new test case
 *
 */
TEST(random, basic_int_2)
{
  auto data1 = 0;
  auto data2 = 100;

  auto result = my::math::rand::random<int, false>(data1, data2);
  EXPECT_IN_RANGE(result, data1, data2);
}

/**
 * @brief Construct a new test case
 *
 */
TEST(random, basic_float_1)
{
  auto data1 = 0.0f;
  auto data2 = 1.0f;

  auto result = my::math::rand::random<float>(data1, data2);
  EXPECT_IN_RANGE(result, data1, data2);
}

/**
 * @brief Construct a new test case
 *
 */
TEST(random, basic_float_2)
{
  auto data1 = 0.0f;
  auto data2 = 1.0f;

  auto result = my::math::rand::random<float, false>(data1, data2);
  EXPECT_IN_RANGE(result, data1, data2);
}
