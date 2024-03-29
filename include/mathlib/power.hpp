/**
 * @file power.hpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief
 * @version 1.0.0
 * @date 2021-04-01
 *
 * MIT License
 *
 */

#ifndef _POWER_HPP_
#define _POWER_HPP_
namespace ben {
namespace math {
/**
 * @brief
 *
 * @tparam T
 * @param nbr
 * @param pow
 * @return T
 */
template <typename T>
auto power(const T& nb, const long int& p) -> T {
  if (p < 0)
    return (0);
  if (p != 0)
    return (nb * power(nb, p - 1));
  else
    return 1;
}

/**
 * @brief
 *
 * @tparam T
 * @param nbr
 * @return true
 * @return false
 */
template <typename T>
auto isPowerOfTwo(const T& x) -> bool {
  return x && (!(x & (x - 1)));
}
}  // namespace math
}  // namespace ben
#endif
