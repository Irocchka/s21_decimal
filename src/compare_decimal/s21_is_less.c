#include "../s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int flag_less = TRUE;  // 1
  int flag_eq = 1;
  int flag_stop = 1;
  normalization(&value_1, &value_2);
  bool sign_1 = get_sign(value_1);
  bool sign_2 = get_sign(value_2);
  if (sign_1 != sign_2) {  // разные знаки
    flag_less = (sign_1 == 1) ? TRUE : FALSE;
  } else {
    if (s21_is_equal(value_1, value_2) == 0) {
      for (int i = 95; i >= 0 && flag_stop; i--) {
        if (get_bit(value_1, i) > get_bit(value_2, i)) {
          flag_less = FALSE;
          flag_stop = 0;
        }
        if (get_bit(value_1, i) < get_bit(value_2, i)) {
          flag_less = TRUE;
          flag_stop = 0;
        }
      }
    } else {
      flag_less = FALSE;
      flag_eq = 0;
    }
    if (sign_1 == 1 && sign_2 == 1 && flag_eq == 1) {  // оба отрицательные
      flag_less = (flag_less == FALSE) ? TRUE : FALSE;
    }
  }
  return flag_less;
}