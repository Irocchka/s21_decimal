#include "../s21_decimal.h"

int s21_is_equal(s21_decimal value_1, s21_decimal value_2) {
  int flag_eq = TRUE;  // 1
  normalization(&value_1, &value_2);
  if (get_sign(value_1) != get_sign(value_2)) {  // разные знаки
    flag_eq = FALSE;
  } else {
    for (int i = 95; i >= 0; i--) {
      if (get_bit(value_1, i) != get_bit(value_2, i)) {
        flag_eq = FALSE;
        break;
      }
    }
  }
  return flag_eq;
}