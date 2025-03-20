#include "../s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  long int x = 0;
  bool err = 0;
  for (int i = 95; i >= 0; i--) {
    if (get_bit(src, i)) x += (long int)pow(2, i);
    if (x >= 2147483648) {
      err = 1;
    }
  }
  x /= (int)pow(10, get_exp(src));
  *dst = x * (get_sign(src) ? -1 : 1);
  return err;
}