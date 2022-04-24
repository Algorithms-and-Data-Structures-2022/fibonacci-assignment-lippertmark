#include <iostream>

#include "assignment/matrix2d.hpp"
#include "assignment/fibonacci.hpp"

using namespace std;
using namespace assignment;

int main(int argc, char **argv) {

  Matrix2x2 mat = {{{1, 1}, {1, 0}}};

  // 0 1 1 2 3 5 8 13 21 34
  mat = matrix_power(FibMatrix, 3); // = 8

  for (const auto& rows: mat) {
    for (int elem: rows) {
      cout << elem << '\t';
    }
    cout << '\n';
  }

  cout << fib_matrix(9);

  return 0;
}
