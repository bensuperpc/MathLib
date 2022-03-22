/**
 * @file random_bench.cpp
 * @author Bensuperpc (bensuperpc@gmail.com)
 * @brief
 * @version 1.0.0
 * @date 2022-03-22
 *
 * MIT License
 *
 */

#include <cstddef>
#include <vector>

#include "mathlib/random.hpp"

#include <benchmark/benchmark.h>

/**
 * @brief Construct a new bench case
 *
 */

static void random_basic_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  const auto size = state.range(0);
  size_t result = 0;

  for (auto _ : state) {
    benchmark::DoNotOptimize(result);

    result = my::math::rand::random<size_t, false>(0, size);

    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * size * sizeof(size_t));

  // state.SetLabel("OK");
}
BENCHMARK(random_basic_bench)
    ->Name("random_basic")
    ->RangeMultiplier(10)
    ->Range(1, 1000);

/**
 * @brief Construct a new bench case
 *
 */

static void random64_basic_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  const auto size = state.range(0);
  size_t result = 0;

  for (auto _ : state) {
    benchmark::DoNotOptimize(result);

    result = my::math::rand::random<size_t, true>(0, size);

    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * size * sizeof(size_t));

  // state.SetLabel("OK");
}
BENCHMARK(random64_basic_bench)
    ->Name("random64_basic")
    ->RangeMultiplier(10)
    ->Range(1, 1000);

/**
 * @brief Construct a new bench case
 *
 */

static void random_basic_vec_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  const auto size = state.range(0);
  std::vector<size_t> vec(size, 0);

  for (auto _ : state) {
    benchmark::DoNotOptimize(vec);

    my::math::rand::random<size_t, false>(vec, 0, 100);

    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * size * sizeof(size_t));

  // state.SetLabel("OK");
}
BENCHMARK(random_basic_vec_bench)
    ->Name("random_basic_vec")
    ->RangeMultiplier(10)
    ->Range(1, 1000);

/**
 * @brief Construct a new bench case
 *
 */

static void random64_basic_vec_bench(benchmark::State& state)
{
  // Code inside this loop is measured repeatedly
  const auto size = state.range(0);
  std::vector<size_t> vec(size, 0);

  for (auto _ : state) {
    benchmark::DoNotOptimize(vec);

    my::math::rand::random<size_t, true>(vec, 0, 100);

    benchmark::ClobberMemory();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * size * sizeof(size_t));

  // state.SetLabel("OK");
}
BENCHMARK(random64_basic_vec_bench)
    ->Name("random64_basic_vec")
    ->RangeMultiplier(10)
    ->Range(1, 1000);

// Run the benchmark
// BENCHMARK_MAIN();
