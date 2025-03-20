#include "../s21_decimal.h"

int s21_mult(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int error = 0;
  s21_big_decimal val_1 = {0};
  s21_big_decimal val_2 = {0};
  s21_big_decimal res = {0};
  s21_decimal_to_big_decimal(value_1, &val_1);
  s21_decimal_to_big_decimal(value_2, &val_2);
  for (int i = 0; i < 224; i++) {
    if (get_bit_big(val_2, i) == 1) {
      s21_add_big(res, val_1, &res);
    }
    shift_left_big(&val_1, 1);
  }
  set_exp_big(&res, get_exp_big(val_1) + get_exp_big(val_2));
  error = banc_round_error(&res);
  if (error == 0) {
    if (get_sign(value_1) != get_sign(value_2)) {
      set_sign_big(&res, 1);
    } else {
      set_sign_big(&res, 0);
    }
    s21_big_decimal_to_decimal(res, result);
  }
  return error;
}
