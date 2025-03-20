#include "../s21_decimal.h"
int get_bit(s21_decimal value, int index) {
  int bits_no = index / 32, bits_ind = index % 32;
  return ((value.bits[bits_no] >> (bits_ind)) & 0x1);
}

void set_bit(s21_decimal* value, int index, int bit) {
  int bits_no = index / 32, bits_ind = index % 32;
  if (bit) {
    value->bits[bits_no] |= 1 << bits_ind;
  } else {
    value->bits[bits_no] &= ~(1 << bits_ind);
  }
}

int get_sign(s21_decimal value) { return get_bit(value, 127); }

void set_sign(s21_decimal* value, int sign) { set_bit(value, 127, sign); }

int get_exp(s21_decimal value) { return value.bits[3] >> 16 & 0xFF; }

void set_exp(s21_decimal* value, int exp) {
  value->bits[3] &= 0x80000000;
  value->bits[3] |= exp << 16;
}