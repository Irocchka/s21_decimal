#include "../s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  bool err = 0;
  double x = 0;
  for (int i = 95; i >= 0; i--) {
    if (get_bit(src, i)) x += pow(2, i);
  }
  x /= pow(10, get_exp(src));
  *dst = (float)x * (get_sign(src) ? -1 : 1);
  return err;
}