#include <catch2/catch.hpp>

#include "assignment/fibonacci.hpp"

#include <array>
#include <cstdint>  // int64_t

using namespace assignment;

constexpr int kFibMax = 44;

constexpr std::array<int64_t, kFibMax> kFibTable = {
    0,       1,       1,       2,        3,        5,        8,        13,        21,        34,        55,
    89,      144,     233,     377,      610,      987,      1597,     2584,      4181,      6765,      10946,
    17711,   28657,   46368,   75025,    121393,   196418,   317811,   514229,    832040,    1346269,   2178309,
    3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141, 267914296, 433494437};

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
