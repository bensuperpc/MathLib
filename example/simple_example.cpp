#include <iostream>
#include <vector>

#include "mathlib/random.hpp"

auto main() -> int
{
  const int min = 0;
  const int max = 100;

  const int result = my::math::rand::random<int>(min, max);
  std::cout << result << std::endl;

  std::vector<int> vec = {-1, -1, -1, -1, -1};

  my::math::rand::random<int>(vec, min, max);
  for (auto& i : vec) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
