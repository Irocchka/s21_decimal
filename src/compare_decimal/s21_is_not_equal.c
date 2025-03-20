#include "../s21_decimal.h"

int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2) {
  int flag_not_eq = (s21_is_equal(value_1, value_2) == TRUE) ? FALSE : TRUE;
  return flag_not_eq;
}