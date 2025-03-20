#include "../s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal res = {0};
  s21_decimal zero = {0};
  s21_decimal cel = {0};
  int is_drop = 1;
  int count_power = 0;
  int start_exp1 = get_exp(value_1);
  int start_exp2 = get_exp(value_2);
  int start_sign1 = get_sign(value_1);
  int start_sign2 = get_sign(value_2);
  set_exp(&value_1, 0);
  set_exp(&value_2, 0);
  set_sign(&value_1, 0);
  set_sign(&value_2, 0);
  int error = s21_is_equal(value_2, zero) ? 3 : 0;
  int dif_exp = start_exp1 - start_exp2;
  if (error != 3) {
    while (is_drop && (declen_big(res) < 95) && (dif_exp + count_power) <= 28) {
      s21_decimal ost = {0};
      zeroes_struct(&cel);
      for (int i = declen(value_1); i >= 0; i--) {
        shift_left(&ost, 1);
        set_bit(&ost, 0, get_bit(value_1, i));
        if (s21_is_greater_or_equal_only_mantiss(ost, value_2)) {
          s21_sub(ost, value_2, &ost);
          set_sign(&ost, 0);  // иначе s21_sub уходит на сложение
          shift_left(&cel, 1);
          set_bit(&cel, 0, 1);
        } else {
          shift_left(&cel, 1);
        }
      }
      if (ost.bits[0] > 0 || ost.bits[1] > 0 || ost.bits[2] > 0) {
        pow_to_ten(&ost, 1);
        value_1 = ost;
        s21_big_decimal big_cel = {0};
        s21_decimal_to_big_decimal(cel, &big_cel);
        s21_add_only_mantiss_big(big_cel, res, &res);
        count_power++;
        pow_to_ten_big(&res, 1);
      } else {
        is_drop = 0;
        s21_big_decimal big_cel = {0};
        s21_decimal_to_big_decimal(cel, &big_cel);
        s21_add_only_mantiss_big(big_cel, res, &res);
      }
    }
    if (is_drop) {
      s21_big_decimal big_cel = {0};
      s21_decimal_to_big_decimal(cel, &big_cel);
      s21_add_only_mantiss_big(big_cel, res, &res);
    }
    set_div_exp(&res, dif_exp, count_power);
    if (is_drop) {
      s21_big_decimal round_res = {0};
      s21_banc_round_big(res, &round_res);
      error = banc_round_error(&round_res);
      s21_big_decimal_to_decimal(round_res, result);
    } else {
      s21_big_decimal_to_decimal(res, result);
    }

    if (start_sign1 != start_sign2) {
      set_sign(result, 1);
    } else {
      set_sign(result, 0);
    }
  }

  return error;
}
