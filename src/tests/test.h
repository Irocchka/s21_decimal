#ifndef DECIMAL_TEST
#define DECIMAL_TEST

#include <check.h>
#include <stdlib.h>

#include "../s21_decimal.h"

int compare_struct(s21_decimal dec1, s21_decimal dec2);

Suite *s21_add_suite(void);
Suite *s21_sub_suite(void);
Suite *s21_mult_suite(void);
Suite *s21_div_suite(void);

Suite *s21_negate_suite(void);
Suite *s21_round_suite(void);
Suite *s21_floor_suite(void);
Suite *s21_truncate_suite(void);

Suite *s21_from_decimal_to_float_suite(void);
Suite *s21_from_decimal_to_int_suite(void);
Suite *s21_from_int_to_decimal_suite(void);
Suite *s21_from_float_to_decimal_suite(void);

Suite *s21_is_equal_suite(void);
Suite *s21_is_not_equal_suite(void);
Suite *s21_is_less_suite(void);
Suite *s21_is_less_or_equal_suite(void);
Suite *s21_is_greater_suite(void);
Suite *s21_is_greater_or_equal_suite(void);

#endif