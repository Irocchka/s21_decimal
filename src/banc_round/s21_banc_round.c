#include "../s21_decimal.h"

void s21_div_10_big(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal *result_1, s21_big_decimal *result_2) {
  s21_big_decimal tmp = {0};
  s21_big_decimal tmp_res = {0};
  for (int i = declen_big(value_1); i >= 0; i--) {
    shift_left_big(&tmp, 1);
    set_bit_big(&tmp, 0, get_bit_big(value_1, i));
    if (s21_is_greater_or_equal_only_mantiss_big(tmp, value_2)) {
      s21_sub_big(tmp, value_2, &tmp);
      set_sign_big(&tmp, 0);  // иначе s21_sub уходит на сложение
      shift_left_big(&tmp_res, 1);
      set_bit_big(&tmp_res, 0, 1);
    } else {
      shift_left_big(&tmp_res, 1);
    }
  }
  s21_big_decimal zero = {0};
  s21_add_big(tmp_res, zero, result_1);
  s21_add_big(tmp, zero, result_2);
}

void s21_banc_round_big(s21_big_decimal value, s21_big_decimal *result) {
  s21_big_decimal zero = {0};
  int start_exp = get_exp_big(value);
  int start_sign = get_sign_big(value);
  set_exp_big(&value, 0);
  s21_big_decimal ten = {{10, 0, 0, 0}};
  s21_big_decimal integer_part = {0};
  s21_big_decimal remains = {0};
  s21_big_decimal one = {{1, 0, 0, 0}};
  s21_div_10_big(value, ten, &integer_part, &remains);
  int last_bit =
      get_bit_big(integer_part, 0);  // 1 - число нечетное, 0 - четное
  s21_big_decimal six = {{6, 0, 0, 0}};
  s21_big_decimal five = {{5, 0, 0, 0}};
  if (s21_is_greater_or_equal_big(remains,
                                  six)) {  // остаток больше 6 или равен
    s21_add_big(integer_part, one, result);
  } else if (s21_is_less_big(remains, five)) {
    s21_add_big(integer_part, zero, result);
  } else {
    if (last_bit) {
      s21_add_big(integer_part, one, result);
    } else {
      s21_add_big(integer_part, zero, result);
    }
  }
  set_sign_big(result, start_sign);
  set_exp_big(result, start_exp - 1);
}

int banc_round_error(s21_big_decimal *result) {
  int start_exp = get_exp_big(*result);
  int start_sign = get_sign_big(*result);
  int error = 0;
  if (declen_big(*result) > 95) {
    if (start_exp == 0 && start_sign) {
      error = 2;  // перепoлнение структуры
    } else if (start_exp == 0 && start_sign == 0) {
      error = 1;
    } else {
      while (declen_big(*result) > 95) {
        s21_big_decimal tmo = {0};
        s21_banc_round_big(*result, &tmo);
        *result = tmo;
        if (get_exp_big(*result) == 0 && declen_big(*result) > 95 &&
            start_sign == 0) {
          error = 1;
          break;
        } else if (get_exp_big(*result) == 0 && declen_big(*result) > 95 &&
                   start_sign) {
          error = 2;
          break;
        }
      }
    }
  }
  return error;
}
