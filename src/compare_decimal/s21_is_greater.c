#include "../s21_decimal.h"

int s21_is_greater(s21_decimal value_1, s21_decimal value_2) {
  int flag_great = s21_is_less(value_1, value_2);
  if (s21_is_not_equal(value_1, value_2)) {
    flag_great = (flag_great) ? FALSE : TRUE;
  }
  return flag_great;
}
