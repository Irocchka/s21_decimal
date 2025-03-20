#include "../s21_decimal.h"

void s21_decimal_to_big_decimal(s21_decimal value_1,
                                s21_big_decimal* result) {  // fuf
  for (int i = 0; i <= 95; i++) {
    set_bit_big(result, i, get_bit(value_1, i));
  }
  set_exp_big(result, get_exp(value_1));
  set_sign_big(result, get_sign(value_1));
}