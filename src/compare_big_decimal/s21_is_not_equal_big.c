#include "../s21_decimal.h"

int s21_is_not_equal_big(s21_big_decimal value_1, s21_big_decimal value_2) {
  int flag_not_eq = (s21_is_equal_big(value_1, value_2) == TRUE) ? FALSE : TRUE;
  return flag_not_eq;
}