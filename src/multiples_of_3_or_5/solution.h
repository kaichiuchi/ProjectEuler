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

// If we list all the natural numbers below 10 that are multiples of 3 or 5, we
// get 3, 5, 6 and 9. The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below 1000.

#ifndef PROJECTEULER_MULTIPLES_OF_3_AND_5_SOLUTION
#define PROJECTEULER_MULTIPLES_OF_3_AND_5_SOLUTION

#include <cmath>

/// Computes the sum of all the multiples of 3 or 5 below 1000 in a brute force
/// manner.
///
/// If the values of the parameters are known at compile-time, the runtime cost
/// will be eliminated and the answer will be calculated at compile-time. If
/// this ends up being the case, it is no different than using the optimized
/// solution other than perhaps a longer compile time.
///
/// \return The sum of all the multiples of 3 or 5 below 1000.
constexpr auto BruteForceSolution(const int max, const int first,
                                  const int second) noexcept
    -> int {
  auto sum = 0;

  for (auto num = 1; num < max; ++num) {
    if (((num % first) == 0) || ((num % second) == 0)) {
      sum += num;
    }
  }
  return sum;
}

/// Computes the sum of all the multiples of first and second below max using a
/// closed-summation formula.
///
/// If the values of the parameters are known at compile-time, the runtime cost
/// will be eliminated and the answer will be calculated at compile time. If
/// this ends up being the case, it is no different than using the brute force
/// solution other than perhaps a shorter compile time.
///
/// \param max
/// \param first
/// \param second
/// \return
constexpr auto OptimizedSolution(const int max, const int first,
                                 const int second) noexcept
    -> int {
  constexpr auto sum = [](const int x, const int n) noexcept -> int {
    const auto divisor = (n - 1) / x;
    return (divisor * x * (divisor + 1)) / 2;
  };

  const auto threes = sum(first, max);
  const auto fives = sum(second, max);
  const auto fifteens = sum(first * second, max);

  return threes + fives - fifteens;
}

#endif  // PROJECTEULER_MULTIPLES_OF_3_AND_5_SOLUTION