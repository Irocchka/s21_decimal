#include "../s21_decimal.h"

int get_bit_big(s21_big_decimal value, int index) {
  int bits_no = index / 32, bits_ind = index % 32;
  return ((value.bits[bits_no] >> (bits_ind)) & 0x1);
}

void set_bit_big(s21_big_decimal* value, int index, int bit) {
  int bits_no = index / 32, bits_ind = index % 32;
  if (bit) {
    value->bits[bits_no] |= 1 << bits_ind;
  } else {
    value->bits[bits_no] &= ~(1 << bits_ind);
  }
}

int get_sign_big(s21_big_decimal value) { return get_bit_big(value, 255); }

void set_sign_big(s21_big_decimal* value, int sign) {
  set_bit_big(value, 255, sign);
}

int get_exp_big(s21_big_decimal value) { return value.bits[7] >> 16 & 0xFF; }

void set_exp_big(s21_big_decimal* value, int exp) {
  value->bits[7] &= 0x80000000;
  value->bits[7] |= exp << 16;
}