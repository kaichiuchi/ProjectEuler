# Multiples of 3 or 5

[Link to problem](https://projecteuler.net/problem=1)

## Description

    If we list all the natural numbers below 10 that are multiples of 3 or 5,
    we get 3, 5, 6 and 9. The sum of these multiples is 23.

    Find the sum of all the multiples of 3 or 5 below 1000.

## Unit Tests

The unit tests are simple: we pass known values at compile time and check the
results of each function. We don't care about optimization for this situation.

## Benchmark

    ----------------------------------------------------------------------
    Benchmark                            Time             CPU   Iterations
    ----------------------------------------------------------------------
    NaiveSolution_Benchmark         786351 ns       786252 ns         1000
    OptimizedSolution_Benchmark       7.74 ns         7.74 ns     91249202