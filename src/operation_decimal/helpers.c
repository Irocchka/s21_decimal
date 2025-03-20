#include "../s21_decimal.h"

int s21_add_only_mantiss(s21_decimal value_1, s21_decimal value_2,
                         s21_decimal* result) {
  int transfer_bit = 0, overflow = 0;
  for (int i = 0; i <= (maxdec(value_1, value_2) + 1); i++) {
    int x = get_bit(value_1, i);
    int y = get_bit(value_2, i);
    int res = (x + y + transfer_bit) % 2;
    set_bit(result, i, res);
    transfer_bit = (x + y + transfer_bit > 1) ? 1 : 0;
    overflow = find_over_flow(*result);
  }
  return overflow;
}

void pow_to_ten(s21_decimal* dec, int pow_count) {
  s21_decimal tmp_start = {0};
  while (pow_count--) {
    tmp_start = *dec;
    shift_left(&tmp_start, 3);
    shift_left(dec, 1);
    s21_add_only_mantiss(tmp_start, *dec, dec);
  }
}
void shift_left(s21_decimal* dec, int count_shift) {
  for (int i = 0; i < count_shift; i++) {
    bool bit_shift_31 = get_bit(*dec, 31);
    bool bit_shift_63 = get_bit(*dec, 63);
    dec->bits[0] = dec->bits[0] << 1;
    dec->bits[1] = dec->bits[1] << 1;
    dec->bits[2] = dec->bits[2] << 1;
    if (bit_shift_31 == 1) {
      set_bit(dec, 32, 1);
    }
    if (bit_shift_63 == 1) {
      set_bit(dec, 64, 1);
    }
  }
}

void normalization(s21_decimal* dec1, s21_decimal* dec2) {
  int exp1 = get_exp(*dec1);
  int exp2 = get_exp(*dec2);
  if (exp1 > exp2) {
    pow_to_ten(dec2, exp1 - exp2);
    set_exp(dec2, exp1);
  } else if (exp2 > exp1) {
    pow_to_ten(dec1, exp2 - exp1);
    set_exp(dec1, exp2);
  }
}

int declen(s21_decimal dec) {
  int res = 1;
  for (int i = 95; i >= 0; i--) {
    if (get_bit(dec, i)) {
      res = i;
      break;
    }
  }
  return res;
}

int maxdec(s21_decimal dec1, s21_decimal dec2) {
  int len1 = declen(dec1), len2 = declen(dec2);
  int len = (len1 > len2) ? len1 : len2;
  return len;
}

void zeroes_struct(s21_decimal* dec) {
  for (int i = 0; i < 4; i++) {
    dec->bits[i] = 0;
  }
}

int find_over_flow(s21_decimal dec) {
  int overflow = 0;
  for (int i = 111; i >= 96; i--) {
    overflow += get_bit(dec, i);
  }
  return overflow;
}
