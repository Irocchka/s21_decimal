#include "../s21_decimal.h"

/*
  Используется в зависимости от знака
*/
void s21_add_only_mantiss_big(s21_big_decimal value_1, s21_big_decimal value_2,
                              s21_big_decimal* result) {  // fuf
  int overflow_bit = 0;
  for (int i = 0; i <= (maxdec_big(value_1, value_2) + 1); i++) {
    unsigned int result_bit =
        get_bit_big(value_1, i) + get_bit_big(value_2, i) + overflow_bit;
    unsigned int res = result_bit % 2;
    overflow_bit = result_bit / 2;
    set_bit_big(result, i, res);
  }
  set_exp_big(result, get_exp_big(value_1));
  set_sign_big(result, get_sign_big(value_1));
}

/*
  Используется в вычитании для разноименных знаков
*/
void s21_add_big(s21_big_decimal val_1, s21_big_decimal val_2,
                 s21_big_decimal* res) {
  bool sign_1 = get_sign_big(val_1), sign_2 = get_sign_big(val_2);
  if (sign_1 == sign_2) {
    s21_add_only_mantiss_big(val_1, val_2, res);
  } else if (sign_1 == 1 && sign_2 == 0) {
    set_sign_big(&val_1, 0);
    s21_sub_big(val_2, val_1, res);
  } else {
    set_sign_big(&val_2, 0);
    s21_sub_big(val_1, val_2, res);
  }
}

/*
  Используется в сложении для разноименных знаков
*/
void s21_sub_big(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal* result) {
  bool sign_1 = get_sign_big(value_1), sign_2 = get_sign_big(value_2);
  if (sign_1 == 1 && sign_2 == 1) {
    set_sign_big(&value_2, 0);
    set_sign_big(&value_1, 0);
    s21_big_decimal tmp = value_1;
    value_1 = value_2;
    value_2 = tmp;
    sub_origin_big(value_1, value_2, result);
  } else if (sign_1 == 0 && sign_2 == 0) {
    sub_origin_big(value_1, value_2, result);
  } else if (sign_1 == 0 && sign_2 == 1) {
    set_sign_big(&value_2, 0);
    s21_add_big(value_1, value_2, result);
  } else if (sign_1 == 1 && sign_2 == 0) {
    set_sign_big(&value_2, 1);
    s21_add_big(value_1, value_2, result);
  }
}

/*
  Базовое вычитание
*/
void sub_origin_big(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal* result) {
  int start_val = maxdec_big(value_1, value_2);
  reverse_big(&value_2, start_val);
  s21_add_only_mantiss_big(value_1, value_2, result);
  if (declen_big(*result) > start_val) {
    for (int i = 223; i >= 0; i--) {
      if (get_bit_big(*result, i)) {
        set_bit_big(result, i, 0);
        break;
      }
    }
    s21_big_decimal tmp = {{1, 0, 0, 0}};
    s21_add_only_mantiss_big(*result, tmp, result);
    set_sign_big(result, 0);
    set_exp_big(result, get_exp_big(value_1));
  } else {
    reverse_big(result, start_val);
    set_sign_big(result, 1);
    set_exp_big(result, get_exp_big(value_1));
  }
}

void set_div_exp(s21_big_decimal* res, int dif_exp, int count_power) {
  if (count_power == 0 && dif_exp < 0) {
    pow_to_ten_big(res, abs(dif_exp));
  } else if (count_power == 0 && dif_exp >= 0) {
    set_exp_big(res, dif_exp);
  } else if (count_power > 0 && dif_exp < 0) {
    int dif_pow_exp = dif_exp + count_power;
    if (dif_pow_exp >= 0) {
      set_exp_big(res, dif_pow_exp);
    } else if (dif_pow_exp < 0) {
      pow_to_ten_big(res, abs(dif_pow_exp));
    }
  } else if (count_power > 0 && dif_exp >= 0) {
    set_exp_big(res, (dif_exp + count_power));
  }
}
