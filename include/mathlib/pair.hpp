/**
 * @file pair.hpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief
 * @version 1.0.0
 * @date 2021-04-01
 *
 * MIT License
 *
 */

#ifndef _PAIR_HPP_
#define _PAIR_HPP_
#include <cstdint>
namespace my
{
namespace math
{

/**
 * @brief
 *
 * @ingroup Math_pair
 *
 * @tparam T
 * @param nbr
 * @return true
 * @return false
 */
template<typename T>
bool is_odd(const T& nbr)
{
  if (nbr & 1)
    return true;
  else
    return false;
}

/**
 * @brief
 *
 * @ingroup Math_pair
 *
 * @tparam T
 * @param nbr
 * @return true
 * @return false
 */
template<typename T>
bool is_even(const T& nbr)
{
  if (nbr & 1)
    return false;
  else
    return true;
}
}  // namespace math
}  // namespace my
#endif
