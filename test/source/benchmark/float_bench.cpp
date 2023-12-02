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

#include "mathlib/float.hpp"

#include <benchmark/benchmark.h>

static void DoSetup([[maybe_unused]] const benchmark::State& state) {}

static void DoTeardown([[maybe_unused]] const benchmark::State& state) {}

template <typename T, bool relative>
static void floatCompareRelativeBench(benchmark::State& state) {
    int64_t size = state.range(0);
    benchmark::DoNotOptimize(size);

    T value1 = static_cast<T>(size);
    benchmark::DoNotOptimize(value1);
    T value2 = static_cast<T>(size);
    benchmark::DoNotOptimize(value2);

    for (auto _ : state) {
        benchmark::DoNotOptimize(ben::math::fp::areEqual<T, relative>(value1, value2));
        benchmark::ClobberMemory();
        // state.PauseTiming();
        // state.SkipWithError("No path found");
        // state.ResumeTiming();
    }
    state.SetItemsProcessed(state.iterations());
    state.SetBytesProcessed(state.iterations() * sizeof(T));
    // state.counters["range"] = range;
    // state.SetLabel("OK");
}
BENCHMARK(floatCompareRelativeBench<float, true>)
//    ->Name("floatCompareRelativeBench")
    ->RangeMultiplier(1000)
    ->Range(1, 1000)
    ->ThreadRange(1, 1)
    ->Unit(benchmark::kNanosecond)
    ->Setup(DoSetup)
    ->Teardown(DoTeardown)
    ->MeasureProcessCPUTime()
    ->UseRealTime();
BENCHMARK(floatCompareRelativeBench<float, false>)
//    ->Name("floatCompareRelativeBench")
    ->RangeMultiplier(1000)
    ->Range(1, 1000)
    ->ThreadRange(1, 1)
    ->Unit(benchmark::kNanosecond)
    ->Setup(DoSetup)
    ->Teardown(DoTeardown)
    ->MeasureProcessCPUTime()
    ->UseRealTime();
BENCHMARK(floatCompareRelativeBench<double, true>)
//    ->Name("floatCompareRelativeBench")
    ->RangeMultiplier(1000)
    ->Range(1, 1000)
    ->ThreadRange(1, 1)
    ->Unit(benchmark::kNanosecond)
    ->Setup(DoSetup)
    ->Teardown(DoTeardown)
    ->MeasureProcessCPUTime()
    ->UseRealTime();
BENCHMARK(floatCompareRelativeBench<double, false>)
//    ->Name("floatCompareRelativeBench")
    ->RangeMultiplier(1000)
    ->Range(1, 1000)
    ->ThreadRange(1, 1)
    ->Unit(benchmark::kNanosecond)
    ->Setup(DoSetup)
    ->Teardown(DoTeardown)
    ->MeasureProcessCPUTime()
    ->UseRealTime();
BENCHMARK(floatCompareRelativeBench<long double, true>)
//    ->Name("floatCompareRelativeBench")
    ->RangeMultiplier(1000)
    ->Range(1, 1000)
    ->ThreadRange(1, 1)
    ->Unit(benchmark::kNanosecond)
    ->Setup(DoSetup)
    ->Teardown(DoTeardown)
    ->MeasureProcessCPUTime()
    ->UseRealTime();
BENCHMARK(floatCompareRelativeBench<long double, false>)
//    ->Name("floatCompareRelativeBench")
    ->RangeMultiplier(1000)
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
