/**
 * @file sphere.hpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief sphere header
 * @version 1.0.0
 * @date 2021-04-01
 *
 * MIT License
 *
 */
#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "constant.hpp"

#if __cplusplus == 202002L
#  include <numbers>
#endif
namespace my
{

namespace math
{

namespace sphere
{
/**
 * @brief
 *
 * @ingroup Math_sphere
 *
 * @tparam T
 * @param r
 * @return T
 */
template<typename T>
T sphereVolume(const T& r)
{
  return (4.0 / 3.0) * PI * (r * r * r);
}

/**
 * @brief
 *
 * @ingroup Math_sphere
 *
 * @tparam T
 * @param r
 * @return T
 */
template<typename T>
T sphereSurface(const T& r)
{
  return (4.0 * PI * r);
}

/**
 * @brief
 *
 * @ingroup Math_sphere
 *
 * @tparam T
 * @param r
 * @return T
 */
#if __cplusplus < 202002L
#  ifdef CMAKE_CXX_EXTENSIONS
#    if CMAKE_CXX_EXTENSIONS == 1
template<typename T>
T sphereSurface_Q(const T& r)
{
#      pragma GCC diagnostic ignored "-Wpedantic"
  return (4.0 * Q_PI * r);
}
#    endif
#  endif
#else
template<typename T>
T sphereSurface_Q(const T& r)
{
  return (4.0 * std::numbers::pi * r);
}
#endif

/**
 * @brief
 *
 * @ingroup Math_sphere
 *
 * @tparam T
 * @param r
 * @return T
 */
#if __cplusplus < 202002L
#  ifdef CMAKE_CXX_EXTENSIONS
#    if CMAKE_CXX_EXTENSIONS == 1
template<typename T>
T sphereVolume_Q(const T& r)
{
#      pragma GCC diagnostic ignored "-Wpedantic"
  return (4.0 / 3.0) * Q_PI * (r * r * r);
}
#    endif
#  endif
#else
template<typename T>
T sphereVolume_Q(const T& r)
{
  return (4.0 / 3.0) * std::numbers::pi * (r * r * r);
}
#endif

}  // namespace sphere
}  // namespace math
}  // namespace my

#endif
