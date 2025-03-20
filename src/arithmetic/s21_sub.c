#include "../s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result) {
  int error = 0;
  s21_big_decimal val_1 = {0};
  s21_big_decimal val_2 = {0};
  s21_big_decimal res = {0};
  s21_decimal_to_big_decimal(value_1, &val_1);
  s21_decimal_to_big_decimal(value_2, &val_2);
  normalization_big(&val_1, &val_2);
  bool sign_1 = get_sign_big(val_1), sign_2 = get_sign_big(val_2);
  if (sign_1 == 1 && sign_2 == 1) {  // work
    set_sign_big(&val_2, 0);
    set_sign_big(&val_1, 0);
    s21_big_decimal tmp = val_1;
    val_1 = val_2;
    val_2 = tmp;
    sub_origin_big(val_1, val_2, &res);
  } else if (sign_1 == 0 && sign_2 == 0) {  // work
    sub_origin_big(val_1, val_2, &res);
  } else if (sign_1 == 0 && sign_2 == 1) {  // work
    set_sign_big(&val_2, 0);
    s21_add_big(val_1, val_2, &res);
    //   output_decimal_big(res);
  } else if (sign_1 == 1 && sign_2 == 0) {  // work
    set_sign_big(&val_2, 1);
    s21_add_big(val_1, val_2, &res);
  }
  error = banc_round_error(&res);
  // output_decimal_big(res);
  if (error == 0) {
    s21_big_decimal_to_decimal(res, result);
  }
  return error;
}