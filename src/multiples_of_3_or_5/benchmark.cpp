// ProjectEuler - Solutions to ProjectEuler problems
//
// Written in 2022 by Michael Rodriguez <mike@kaichiuchi.dev>
//
// To the extent possible under law, the author(s) have dedicated all copyright
// and related and neighboring rights to this software to the public domain
// worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication along
// with this software. If not, see
// <http://creativecommons.org/publicdomain/zero/1.0/>.

#include <random>
#include "benchmark/benchmark.h"
#include "solution.h"

namespace {
auto GenerateRandomNumber(const int max) noexcept -> int {
  std::random_device random_device;

  auto random_engine = std::default_random_engine{random_device()};
  auto dist = std::uniform_int_distribution<int>{1, max};

  return dist(random_engine);
}

void NaiveSolution_Benchmark(benchmark::State& state) {
  const auto max = GenerateRandomNumber(1'000'000);
  const auto first_multiple = GenerateRandomNumber(14);
  const auto second_multiple = GenerateRandomNumber(94);

  for (auto _ : state) {
    BruteForceSolution(max, first_multiple, second_multiple);
  }
}

void OptimizedSolution_Benchmark(benchmark::State& state) {
  const auto max = GenerateRandomNumber(1'000'000);
  const auto first_multiple = GenerateRandomNumber(5);
  const auto second_multiple = GenerateRandomNumber(3);

  for (auto _ : state) {
    OptimizedSolution(max, first_multiple, second_multiple);
  }
}
}

BENCHMARK(NaiveSolution_Benchmark);
BENCHMARK(OptimizedSolution_Benchmark);

BENCHMARK_MAIN();