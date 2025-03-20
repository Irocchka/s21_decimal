#include "../s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  bool err = 0;
  if (!dst)
    err = 1;
  else if (fabsf(src) > 7.922816251e+28)
    err = 1;
  else if (fabsf(src) < 1e-28) {
    err = 1;
    zeroes_struct(dst);
  } else {
    zeroes_struct(dst);
    char nota[128];
    bool sign = (src < 0) ? 1 : 0;
    src = (src < 0) ? src * -1 : src;
    sprintf(nota, "%.6e", src);
    int exp = get_exp_from_char(nota);
    nota_to_decimal(nota, dst);
    if (exp >= 6) {
      pow_to_ten(dst, exp - (6 - count_zeroes_after_dot(nota)));
      exp = 0;
    } else {
      exp = processing_exp(exp, src);
    }
    set_sign(dst, sign);
    set_exp(dst, exp);
  }
  return err;
}

int count_zeroes_after_dot(char *nota) {
  int len = strlen(nota) - 5;
  int count = 0;
  for (int i = len; i >= 0; i--) {
    if (nota[i] != '0') {
      break;
    } else
      count++;
  }
  return count;
}

int get_exp_from_char(char *src) {
  int exp;
  while (*src++) {
    if (*src == 'e') {
      exp = strtol(++src, NULL, 10);
    }
  }
  return exp;
}

void nota_to_decimal(char *src, s21_decimal *dst) {
  int dig = 1, num = 0, flag_zero = 0;
  int len = strlen(src) - 5;
  for (int i = len; i >= 0; i--) {  // 5 это e-05
    if (src[i] != '0') flag_zero = 1;
    if (flag_zero && src[i] != '.') {
      num += dig * (src[i] - '0');
      dig *= 10;
    }
  }
  s21_from_int_to_decimal(num, dst);
}

int processing_exp(int exp, float src) {
  char f_nota[128];
  int dec_exp = 0;
  bool flag = 0;
  if (exp < 0) {
    sprintf(f_nota, "%.*f", -1 * exp + 6, src);
    for (int i = strlen(f_nota) - 1; i >= 2; i--) {
      if (f_nota[i] != '0') flag = 1;
      if (flag) dec_exp++;
    }
  } else {
    sprintf(f_nota, "%.*f", 6 - exp, src);
    dec_exp = -exp - 2;
    for (int i = strlen(f_nota) - 1; i >= 0; i--) {
      if (f_nota[i] != '0') flag = 1;
      if (flag) dec_exp++;
    }
  }
  return dec_exp;
}