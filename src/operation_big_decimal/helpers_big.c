#include "../s21_decimal.h"

int maxdec_big(s21_big_decimal dec1, s21_big_decimal dec2) {  // fuf
  int len1 = declen_big(dec1), len2 = declen_big(dec2);
  int len = (len1 > len2) ? len1 : len2;
  return len;
}

int declen_big(s21_big_decimal dec) {  // fuf
  int res = 1;
  for (int i = 223; i >= 0; i--) {
    if (get_bit_big(dec, i)) {
      res = i;
      break;
    }
  }
  return res;
}

void shift_left_big(s21_big_decimal* dec, int count_shift) {  // fuf
  for (int i = 0; i < count_shift; i++) {
    bool bit_shift_31 = get_bit_big(*dec, 31);
    bool bit_shift_63 = get_bit_big(*dec, 63);
    bool bit_shift_95 = get_bit_big(*dec, 95);
    bool bit_shift_127 = get_bit_big(*dec, 127);
    bool bit_shift_159 = get_bit_big(*dec, 159);
    bool bit_shift_191 = get_bit_big(*dec, 191);

    dec->bits[0] = dec->bits[0] << 1;
    dec->bits[1] = dec->bits[1] << 1;
    dec->bits[2] = dec->bits[2] << 1;
    dec->bits[3] = dec->bits[3] << 1;
    dec->bits[4] = dec->bits[4] << 1;
    dec->bits[5] = dec->bits[5] << 1;
    dec->bits[6] = dec->bits[6] << 1;

    if (bit_shift_31 == 1) {
      set_bit_big(dec, 32, 1);
    }
    if (bit_shift_63 == 1) {
      set_bit_big(dec, 64, 1);
    }
    if (bit_shift_95 == 1) {
      set_bit_big(dec, 96, 1);
    }
    if (bit_shift_127 == 1) {
      set_bit_big(dec, 128, 1);
    }
    if (bit_shift_159 == 1) {
      set_bit_big(dec, 160, 1);
    }
    if (bit_shift_191 == 1) {
      set_bit_big(dec, 192, 1);
    }
  }
}

void reverse_big(s21_big_decimal* dec, int len) {
  for (int i = len; i >= 0; i--) {
    if (get_bit_big(*dec, i) == 1)
      set_bit_big(dec, i, 0);
    else
      set_bit_big(dec, i, 1);
  }
}

void pow_to_ten_big(s21_big_decimal* dec, int pow_count) {
  s21_big_decimal tmp_start = {0};
  while (pow_count--) {
    tmp_start = *dec;
    shift_left_big(&tmp_start, 3);
    shift_left_big(dec, 1);
    s21_add_only_mantiss_big(tmp_start, *dec, dec);
  }
}

void normalization_big(s21_big_decimal* dec1, s21_big_decimal* dec2) {
  int exp1 = get_exp_big(*dec1);
  int exp2 = get_exp_big(*dec2);
  if (exp1 > exp2) {
    pow_to_ten_big(dec2, exp1 - exp2);
    set_exp_big(dec2, exp1);
  } else if (exp2 > exp1) {
    pow_to_ten_big(dec1, exp2 - exp1);
    set_exp_big(dec1, exp2);
  }
}