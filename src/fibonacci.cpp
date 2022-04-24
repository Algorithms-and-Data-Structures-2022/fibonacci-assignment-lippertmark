#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    // Напишите здесь свой код ...

    return 0;
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    // Напишите здесь свой код ...

    return 0;
  }

  int64_t fib_recursive(int n) {

    // Напишите здесь свой код ...

    return 0;
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      return cache[n];
    }

    if (cache[n] != -1) {
      // Напишите здесь свой код ...
      return 0;
    }

    // Напишите здесь свой код ...

    return 0;
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }

    // Напишите здесь свой код ...

    // Tip: используйте реализованную функцию matrix_pow

    return 0;
  }

}  // namespace assignment
