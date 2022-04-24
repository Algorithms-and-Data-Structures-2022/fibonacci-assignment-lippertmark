#include <catch2/catch.hpp>

#include "assignment/fibonacci.hpp"

#include <array>
#include <cstdint>  // int64_t

using namespace assignment;

constexpr int kFibMax = 11;

constexpr std::array<int64_t, kFibMax> kFibTable = {
    0,       1,       1,       2,        3,        5,        8,        13,        21,        34,        55};

SCENARIO("Fibonacci::Binet") {
  const int number = GENERATE(range(0, kFibMax));
  CHECK(fib_binet(number) == kFibTable[number]);
}

SCENARIO("Fibonacci::Iterative") {
  const int number = GENERATE(range(0, kFibMax));
  CHECK(fib_iterative(number) == kFibTable[number]);
}

SCENARIO("Fibonacci::Recursive") {
  const int number = GENERATE(range(0, kFibMax));
  CHECK(fib_recursive(number) == kFibTable[number]);
}

SCENARIO("Fibonacci::Memoization") {
  const int number = GENERATE(range(0, kFibMax));

  // prepare the cache
  auto cache = std::vector<int64_t>(number + 1, -1);

  cache[0] = 0;

  if (number > 0) {
    cache[1] = 1;
  }

  CHECK(fib_recursive_memoization(number, cache) == kFibTable[number]);
}

SCENARIO("Fibonacci::Matrix") {
  const int number = GENERATE(range(0, kFibMax));
  CHECK(fib_matrix(number) == kFibTable[number]);
}
