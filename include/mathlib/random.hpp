/**
 * @file random.hpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief
 * @version 1.0.0
 * @date 2021-04-01
 *
 * MIT License
 *
 */

/*
** Source:
*https://stackoverflow.com/questions/14638739/generating-a-random-double-between-a-range-of-values
*/

#ifndef RANDOM_HPP_
#define RANDOM_HPP_

#include <algorithm>
#include <ctime>
#include <iostream>
#include <iterator>
#include <random>

namespace my
{
namespace math
{
namespace rand
{
/**
 * @brief
 *
 * @tparam T
 * @param fMin
 * @param fMax
 * @return T
 */
template<typename T, bool mersenne_64 = true>
T random(const T& fMin, const T& fMax)
{
  typedef typename std::conditional<mersenne_64 == true,
                                    std::mt19937_64,
                                    std::mt19937>::type random_engine;
  random_engine rng;
  std::random_device rnd_device;
  rng.seed(rnd_device());

  if constexpr (std::is_integral<T>::value) {
    std::uniform_int_distribution<T> dist(fMin, fMax);
    return dist(rng);
  } else if (std::is_floating_point<T>::value) {
    std::uniform_real_distribution<T> dist(fMin, fMax);
    return dist(rng);
  } else {
    return 0.0;
  }
}

}  // namespace rand
}  // namespace math
}  // namespace my
#endif
