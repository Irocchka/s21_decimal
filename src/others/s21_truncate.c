#include "../s21_decimal.h"

/*
Возвращает целые цифры указанного Decimal числа;
любые дробные цифры отбрасываются, включая конечные нули.*/
int s21_truncate(s21_decimal value, s21_decimal *result) {
  int err = 0;
  if (!result)
    err = 1;
  else {
    bool sign = get_sign(value);
    zeroes_struct(result);
    int exp = get_exp(value);
    for (int i = 0; i < exp; i++) {
      div_10(value, &value);
    }
    *result = value;
    set_sign(result, sign);
  }
  return err;
}

void div_10(s21_decimal value, s21_decimal *result) {
  s21_decimal tmp = {0};
  s21_decimal tmp_res = {0};
  s21_decimal ten = {{10, 0, 0, 0}};
  for (int i = declen(value); i >= 0; i--) {
    shift_left(&tmp, 1);
    set_bit(&tmp, 0, get_bit(value, i));
    if (s21_is_greater_or_equal_only_mantiss(tmp, ten)) {
      s21_sub(tmp, ten, &tmp);
      set_sign(&tmp, 0);  // иначе s21_sub уходит на сложение
      shift_left(&tmp_res, 1);
      set_bit(&tmp_res, 0, 1);
    } else {
      shift_left(&tmp_res, 1);
    }
  }
  *result = tmp_res;
}