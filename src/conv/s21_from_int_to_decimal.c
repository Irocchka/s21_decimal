#include "../s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  bool err = 0;
  if (!dst)
    err = 1;
  else {
    zeroes_struct(dst);
    if (src >= 0) {
      for (int i = 31; i >= 0; i--) {
        set_bit(dst, i, get_bit_int(src, i));
      }
    } else {
      src--;
      src = ~src;
      for (int i = 31; i >= 0; i--) {
        set_bit(dst, i, get_bit_int(src, i));
      }
      set_sign(dst, 1);
    }
  }
  return err;
}

bool get_bit_int(int src, int ind) { return src & (1 << ind); }
