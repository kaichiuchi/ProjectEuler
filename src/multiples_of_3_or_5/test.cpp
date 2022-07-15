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

#include "gtest/gtest.h"
#include "solution.h"

TEST(MultiplesOf3And5, NaiveSolution) {
  const auto sum = BruteForceSolution(1'000, 3, 5);
  EXPECT_EQ(sum, 233'168);
}

TEST(MultiplesOf3And5, BetterSolution) {
  const auto sum = OptimizedSolution(1'000, 3, 5);
  EXPECT_EQ(sum, 233'168);
}