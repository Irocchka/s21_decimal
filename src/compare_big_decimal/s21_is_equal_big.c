#include "../s21_decimal.h"

int s21_is_equal_big(s21_big_decimal value_1, s21_big_decimal value_2) {
  int flag_eq = TRUE;                                    // 1
  if (get_sign_big(value_1) != get_sign_big(value_2)) {  // разные знаки
    flag_eq = FALSE;
  } else {
    for (int i = 191; i >= 0; i--) {
      if (get_bit_big(value_1, i) != get_bit_big(value_2, i)) {
        flag_eq = FALSE;
        break;
      }
    }
  }
  return flag_eq;
}