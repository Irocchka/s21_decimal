#include "../s21_decimal.h"

int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2) {
  int flag_great_eq = s21_is_greater(value_1, value_2);
  if (s21_is_equal(value_1, value_2)) {
    flag_great_eq = TRUE;
  }
  return flag_great_eq;
}