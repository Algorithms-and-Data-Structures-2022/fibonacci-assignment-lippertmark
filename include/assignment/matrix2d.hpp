#pragma once

#include <array>
#include <cstdint>  // int64_t

namespace assignment {

  // массив из массивов = двумерная матрица
  // [0] => [a_00, a_01]
  // [1] => [a_10, a_11]
  using Matrix2x2 = std::array<std::array<int, 2>, 2>;

  // единичная матрица (identity matrix)
  inline constexpr Matrix2x2 IdentityMatrix = {{{1, 0}, {0, 1}}};

  /**
   * Вычисление произведения двух матриц размерностью 2x2.
   *
   * Сложность ~ O(1).
   *
   * @param left - левая матрица
   * @param right - правая матрица
   * @return результат произведения (матрица 2x2)
   */
  Matrix2x2 matrix_multiply(const Matrix2x2& left, const Matrix2x2& right);

  /**
   * Возведение в степень матрицы размерности 2x2.
   *
   * Сложность ~ O(log n).
   * Используется алгоритм бинарного возведения в степень.
   * Ссылка: https://e-maxx.ru/algo/binary_pow
   *
   * @param matrix - возводимая в степень матрица
   * @param power - значение степени (неотрицательное число)
   * @return результат возведения матрицы в степень (матрица 2x2)
   */
  Matrix2x2 matrix_power(Matrix2x2 matrix, int power);

}  // namespace assignment