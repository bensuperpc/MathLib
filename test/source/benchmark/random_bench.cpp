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

static void DoSetup([[maybe_unused]] const benchmark::State& state) {}

static void DoTeardown([[maybe_unused]] const benchmark::State& state) {}

static void random_basic_bench(benchmark::State& state) {

  int64_t size = state.range(0);
  size_t result = 0;

  for (auto _ : state) {
    benchmark::DoNotOptimize(result);

    result = ben::math::rand::random<size_t, false>(0, size);

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

static void random64_basic_bench(benchmark::State& state) {

  int64_t size = state.range(0);
  size_t result = 0;

  for (auto _ : state) {
    benchmark::DoNotOptimize(result);

    result = ben::math::rand::random<size_t, true>(0, size);

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

static void random_basic_vec_bench(benchmark::State& state) {

  int64_t size = state.range(0);
  std::vector<size_t> vec(size, 0);

  for (auto _ : state) {
    benchmark::DoNotOptimize(vec);

    ben::math::rand::random<size_t, false>(vec, 0, 100);

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

template <typename T>
static void random64_basic_vec_bench(benchmark::State& state) {

  int64_t size = state.range(0);
  std::vector<size_t> vec(size, 0);

  for (auto _ : state) {
    benchmark::DoNotOptimize(vec);

    ben::math::rand::random<size_t, true>(vec, 0, 100);

    benchmark::ClobberMemory();
    // state.PauseTiming();
    // state.SkipWithError("No path found");
    // state.ResumeTiming();
  }
  state.SetItemsProcessed(state.iterations());
  state.SetBytesProcessed(state.iterations() * size * sizeof(size_t));

  // state.SetLabel("OK");
}
BENCHMARK(random64_basic_vec_bench<int64_t>)
    ->Name("random64_basic_vec")
    ->RangeMultiplier(10)
    ->Range(1, 1000)
    ->ThreadRange(1, 1)
    ->Unit(benchmark::kNanosecond)
    ->Setup(DoSetup)
    ->Teardown(DoTeardown)
    ->MeasureProcessCPUTime()
    ->UseRealTime();

// Run the benchmark
// BENCHMARK_MAIN();

int main(int argc, char** argv) {
  ::benchmark::Initialize(&argc, argv);
  ::benchmark::RunSpecifiedBenchmarks();
}
