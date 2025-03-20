#include "../s21_decimal.h"
// ПЕРЕПИСАТЬ!!!!!!!!!!!!!!!!!

/*Округляет Decimal до ближайшего целого числа в сторону отрицательной
 * бесконечности..*/
int s21_floor(s21_decimal value, s21_decimal *result) {
  bool err = 0;
  s21_decimal one = {{1, 0, 0, 0}};
  if (!result)
    err = 1;
  else {
    bool sign = get_sign(value);
    zeroes_struct(result);
    int exp = get_exp(value);
    for (int i = 0; i < exp; i++) {
      div_10(value, &value);
    }
    *result = value;
    set_sign(result, sign);
    if (exp > 0 && sign) {
      s21_sub(*result, one, result);
    }
  }
  return err;
}