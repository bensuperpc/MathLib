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

/**
 * @brief Construct a new test case
 *
 */
TEST(random, basic_vec_int_1)
{
  std::vector<int> vec = {-1, -1, -1, -1, -1};
  const auto min = 0;
  const auto max = 100;

  my::math::rand::random<int, true>(vec, 0, 100);
  for (auto& vec_ : vec)  // access by reference to avoid copying
  {
    EXPECT_IN_RANGE(vec_, min, max);
  }
}

/**
 * @brief Construct a new test case
 *
 */
TEST(random, basic_vec_int_2)
{
  std::vector<int> vec = {-1, -1, -1, -1, -1};
  const auto min = 0;
  const auto max = 160;

  my::math::rand::random<int, true>(vec, min, max);
  for (auto& vec_ : vec)
  {
    EXPECT_IN_RANGE(vec_, min, max);
  }
}

/**
 * @brief Construct a new test case
 *
 */
TEST(random, basic_vec_float_1)
{
  std::vector<float> vec = {-1.0, -1.0, -1.0, -1.0, -1.0};
  const auto min = 0.0;
  const auto max = 1.0;

  my::math::rand::random<float, true>(vec, min, max);
  for (auto& vec_ : vec)
  {
    EXPECT_IN_RANGE(vec_, min, max);
  }
}

/**
 * @brief Construct a new test case
 *
 */
TEST(random, basic_vec_float_2)
{
  std::vector<float> vec = {-2.0, -2.0, -2.0, -2.0, -2.0};
  const auto min = -1.0;
  const auto max = 1.0;

  my::math::rand::random<float, true>(vec, min, max);
  for (auto& vec_ : vec)
  {
    EXPECT_IN_RANGE(vec_, min, max);
  }
}

/**
 * @brief Construct a new test case
 *
 */
TEST(random, basic_vec_double_1)
{
  std::vector<double> vec = {-1.0, -1.0, -1.0, -1.0, -1.0};
  const auto min = 0.0;
  const auto max = 1.0;

  my::math::rand::random<double, true>(vec, min, max);
  for (auto& vec_ : vec)
  {
    EXPECT_IN_RANGE(vec_, min, max);
  }
}
