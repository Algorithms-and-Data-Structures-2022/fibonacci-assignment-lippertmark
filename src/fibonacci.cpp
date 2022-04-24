#include "assignment/fibonacci.hpp"

#include <cmath>    // pow, sqrt, round
#include <cstdint>  // int64_t

namespace assignment {

  int64_t fib_binet(int n) {

    if (n <= 1) {
      return n;
    }

    double f = (1+sqrt(5))/2;

    return int64_t((pow(f, n)-pow(-f, -n))/(2*f-1));
  }

  int64_t fib_iterative(int n) {

    if (n <= 1) {
      return n;
    }

    // буфер для хранения двух последних значения ряда Фибоначчи
    int64_t fib_prev = 0;
    int64_t fib_curr = 1;

    for (int i = 1; i < n; ++i) {
      int64_t new_item = fib_prev + fib_curr;
      fib_prev = fib_curr;
      fib_curr = new_item;
    }

    return fib_curr;
  }

  int64_t fib_recursive(int n) {
    if(n == 1){
      return 1;
    }
    if (n==0){
      return 0;
    }


    return fib_recursive(n-1) + fib_recursive(n-2);
  }

  int64_t fib_recursive_memoization(int n, std::vector<int64_t>& cache) {

    if (n <= 1) {
      cache[n] = n;
      return cache[n];
    }

    if (cache[n] != -1) {
      return cache[n];
    }

    cache[n] = fib_recursive_memoization(n-1, cache) + fib_recursive_memoization(n-2, cache);

    return cache[n];
  }

  int64_t fib_matrix(int n) {

    if (n <= 1) {
      return n;
    }
    Matrix2x2 mat = FibMatrix;
    mat = matrix_power(mat, n-1);
    return mat[0][0] + mat[0][1];
  }

}  // namespace assignment
