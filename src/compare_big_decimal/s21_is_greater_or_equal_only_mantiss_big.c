#include "../s21_decimal.h"

int s21_is_greater_or_equal_only_mantiss_big(s21_big_decimal value_1,
                                             s21_big_decimal value_2) {
  int flag_ccompare = 1;
  for (int i = 223; i >= 0; i--) {
    bool bit_1 = get_bit_big(value_1, i);
    bool bit_2 = get_bit_big(value_2, i);
    if (bit_1 > bit_2) {
      flag_ccompare = 1;
      break;
    } else if (bit_2 > bit_1) {
      flag_ccompare = 0;
      break;
    }
  }
  return flag_ccompare;
}