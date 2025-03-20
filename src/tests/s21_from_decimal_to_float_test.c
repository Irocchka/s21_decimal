#include "test.h"

START_TEST(from_decimal_to_float_check_1) {
  // Arrange
  s21_decimal dec1 = {{42123, 0, 0, 0}};
  float res = 0;
  // Act
  s21_from_decimal_to_float(dec1, &res);
  // Asser
  float wanted = 42123;
  ck_assert_float_eq(res, wanted);
}
END_TEST

START_TEST(from_decimal_to_float_check_2) {
  // Arrange
  s21_decimal dec1 = {{562, 0, 0, 0x10000}};
  float res = 0;
  // Act
  s21_from_decimal_to_float(dec1, &res);
  // Asser
  float wanted = 56.2;
  ck_assert_float_eq(res, wanted);
}
END_TEST

START_TEST(from_decimal_to_float_check_3) {
  // Arrange
  s21_decimal dec1 = {{451444, 0, 0, 0x80070000}};
  float res = 0;
  // Act
  s21_from_decimal_to_float(dec1, &res);
  // Asser
  float wanted = -0.0451444;
  ck_assert_float_eq(wanted, res);
}
END_TEST

Suite* s21_from_decimal_to_float_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_from_decimal_to_float");

  tc = tcase_create("case_s21_from_decimal_to_float");
  tcase_add_test(tc, from_decimal_to_float_check_1);
  tcase_add_test(tc, from_decimal_to_float_check_2);
  tcase_add_test(tc, from_decimal_to_float_check_3);

  suite_add_tcase(s, tc);
  return s;
}
