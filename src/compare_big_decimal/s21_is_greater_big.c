#include "../s21_decimal.h"

int s21_is_greater_big(s21_big_decimal value_1, s21_big_decimal value_2) {
  int flag_great = s21_is_less_big(value_1, value_2);
  if (s21_is_not_equal_big(value_1, value_2)) {
    flag_great = (flag_great) ? FALSE : TRUE;
  }
  return flag_great;
}