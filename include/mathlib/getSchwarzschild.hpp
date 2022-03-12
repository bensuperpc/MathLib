/**
 * @file getSchwarzschild.hpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief
 * @version 1.0.0
 * @date 2021-04-01
 *
 * MIT License
 *
 */
#ifndef GETSCHWARZCHILD_HPP_
#define GETSCHWARZCHILD_HPP_

#include <math.h>

#include "constant.hpp"
namespace my
{
namespace math
{
namespace schwarzschild
{
/**
 * @brief Get the Schwarzschild object
 *
 * @ingroup Math_Schwarzschild
 *
 * @tparam T
 * @param masse
 * @return T
 */
template<typename T>
T getSchwarzschild(const T& masse)
{
  return (masse > 0) ? (2.0 * CONSTANTE_G * masse) / (pow(LIGHT_SPEED, 2)) : 0;
}
}  // namespace schwarzschild
}  // namespace math
}  // namespace my

#endif
