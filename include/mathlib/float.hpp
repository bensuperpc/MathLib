/**
 * @file float.hpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief
 * @version 1.0.0
 * @date 2021-04-01
 *
 * MIT License
 *
 */

#ifndef FLOAT_HPP_
#define FLOAT_HPP_

//#include <algorithm>
// #include <cstdlib>
//#include <cmath>

#include <cmath>
#include <limits>
#include <type_traits>

namespace my
{
namespace math
{
namespace fp
{

template<typename IntegralType>
typename std::enable_if<std::is_integral<IntegralType>::value, bool>::type
are_aqual(const IntegralType& a, const IntegralType& b)
{
  return a == b;
}

template<typename FloatingType>
typename std::enable_if<std::is_floating_point<FloatingType>::value, bool>::type
are_aqual(const FloatingType& a, const FloatingType& b)
{
  return std::fabs(a - b) < std::numeric_limits<FloatingType>::epsilon();
}

}  // namespace fp
}  // namespace math
}  // namespace my
#endif
