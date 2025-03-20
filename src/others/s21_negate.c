#include "../s21_decimal.h"

/*Возвращает результат умножения указанного Decimal на -1.*/
int s21_negate(s21_decimal value, s21_decimal *result) {
  bool err = 0;
  if (!result)
    err = 1;
  else {
    *result = value;
    set_sign(result, get_sign(*result) == 1 ? 0 : 1);
  }
  return err;
}
