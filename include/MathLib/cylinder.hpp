/**
 * @file cylinder.hpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief
 * @version 1.0.0
 * @date 2021-04-01
 *
 * MIT License
 *
 */

#ifndef CYLINDER_HPP_
#define CYLINDER_HPP_

#include "constant.hpp"

#if __cplusplus == 202002L
#  include <numbers>
#endif

namespace my
{
namespace math
{

namespace cylinder
{

/**
 * @brief
 *
 * @ingroup Math_cylinder
 *
 * @tparam T
 * @param r
 * @param h
 * @return T
 */
#if __cplusplus < 202002L
template<typename T>
T cylinderSurface(const T& r, const T& h)
{
  return 2.0 * PI * r * r + 2.0 * PI * r * h;
}
#else
template<typename T>
T cylinderSurface(const T& r, const T& h)
{
  return 2.0 * std::numbers::pi * r * r + 2.0 * std::numbers::pi * r * h;
}
#endif

/**
 * @brief
 *
 * @ingroup Math_cylinder
 *
 * @tparam T
 * @param r
 * @param h
 * @return T
 */
#if __cplusplus < 202002L
template<typename T>
T cylinderVolume(const T& r, const T& h)
{
  return h * PI * r * r;
}
#else
template<typename T>
T cylinderVolume(const T& r, const T& h)
{
  return h * std::numbers::pi * r * r;
}
#endif
}  // namespace cylinder
}  // namespace math
}  // namespace my

#endif
