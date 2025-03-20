#include "../s21_decimal.h"

void s21_big_decimal_to_decimal(s21_big_decimal value_1,
                                s21_decimal* result) {  // fuf
  for (int i = 0; i <= 95; i++) {
    set_bit(result, i, get_bit_big(value_1, i));
  }
  set_exp(result, get_exp_big(value_1));
  set_sign(result, get_sign_big(value_1));
}
