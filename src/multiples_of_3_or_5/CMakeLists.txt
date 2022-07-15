# ProjectEuler - Solutions to ProjectEuler problems
#
# Written in 2022 by Michael Rodriguez <mike@kaichiuchi.dev>
#
# To the extent possible under law, the author(s) have dedicated all copyright
# and related and neighboring rights to this software to the public domain
# worldwide. This software is distributed without any warranty.
#
# You should have received a copy of the CC0 Public Domain Dedication along with
# this software. If not, see
# <http://creativecommons.org/publicdomain/zero/1.0/>.

set(HDRS solution.h)

set(TEST_SRCS test.cpp)
set(BENCHMARK_SRCS benchmark.cpp)

add_executable(TestMultiplesOf3Or5 ${TEST_SRCS} ${HDRS})
target_link_libraries(TestMultiplesOf3Or5 GTest::gtest_main)

add_executable(BenchmarkMultiplesOf3Or5 ${BENCHMARK_SRCS} ${HDRS})
target_link_libraries(BenchmarkMultiplesOf3Or5 benchmark::benchmark)

projecteuler_target_configure(TestMultiplesOf3Or5)
projecteuler_target_configure(BenchmarkMultiplesOf3Or5)

gtest_discover_tests(TestMultiplesOf3Or5)