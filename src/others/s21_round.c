#include "../s21_decimal.h"

/*Округляет Decimal до ближайшего целого числа.*/
int s21_round(s21_decimal value, s21_decimal *result) {
  bool err = 0;
  int exp = get_exp(value);
  int sign = get_sign(value);
  if (!result)
    err = 1;
  else if (!exp) {
    *result = value;
  } else {
    s21_decimal integer = {0};
    s21_decimal remains = {0};
    while (exp--) {
      div_10_for_remains(value, &integer, &remains);
      value = integer;
    }
    set_sign(&integer, sign);
    if (s21_is_greater_or_equal(remains, (s21_decimal){{5, 0, 0, 0}}) &&
        !sign) {
      s21_add(integer, (s21_decimal){{1, 0, 0, 0}}, result);
    } else if (s21_is_greater_or_equal(remains, (s21_decimal){{5, 0, 0, 0}}) &&
               sign) {
      s21_add(integer, (s21_decimal){{1, 0, 0, 0x80000000}}, result);
    } else {
      *result = integer;
    }
  }
  return err;
}

void div_10_for_remains(s21_decimal value, s21_decimal *integer,
                        s21_decimal *remains) {
  zeroes_struct(integer);
  zeroes_struct(remains);
  s21_decimal ten = {{10, 0, 0, 0}};
  for (int i = declen(value); i >= 0; i--) {
    shift_left(remains, 1);
    set_bit(remains, 0, get_bit(value, i));
    if (s21_is_greater_or_equal_only_mantiss(*remains, ten)) {
      s21_sub(*remains, ten, remains);
      set_sign(remains, 0);  // иначе s21_sub уходит на сложение
      shift_left(integer, 1);
      set_bit(integer, 0, 1);
    } else {
      shift_left(integer, 1);
    }
  }
}