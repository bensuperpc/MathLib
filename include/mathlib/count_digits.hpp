/**
 * @file count_digits.hpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief
 * @version 0.1
 * @date 2021-04-01
 *
 * MIT License
 *
 */

#ifndef COUNT_DIGITS_HPP_
#define COUNT_DIGITS_HPP_

#include <bits/stdc++.h>

namespace my
{
namespace math
{
namespace count_digits
{
/**
 * @brief
 *
 * @ingroup Math_count_digits
 *
 * @tparam T
 * @param n
 * @return T
 */
template<typename T>
T count_digits_1(T n)
{
  T count = 0;
  while (n != 0) {
    n = n / 10;
    ++count;
  }
  return count;
}

/**
 * @brief
 *
 * @ingroup Math_count_digits
 *
 * @tparam T
 * @param n
 * @return T
 */
template<typename T>
T count_digits_2(const T& n)
{
  if (n == 0)
    return 0;
  return 1 + count_digits_2(n / 10);
}

/**
 * @brief
 *
 * @ingroup Math_count_digits
 *
 * @tparam T
 * @param n
 * @return T
 */
template<typename T>
T count_digits_3(const T& n)
{
  return (T)std::floor(std::log10(n) + 1);
}

/**
 * @brief
 *
 * @ingroup Math_count_digits
 *
 * @tparam T
 * @param n
 * @return T
 */
template<typename T>
T count_digits_4(const T& n)
{
  std::string num = std::to_string(n);
  return (T)num.size();
}
}  // namespace count_digits
}  // namespace math
}  // namespace my

#endif
