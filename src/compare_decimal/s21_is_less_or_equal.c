#include "../s21_decimal.h"

int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int flag_less_eq = s21_is_less(value_1, value_2);
  if (s21_is_equal(value_1, value_2)) {
    flag_less_eq = TRUE;
  }
  return flag_less_eq;
}