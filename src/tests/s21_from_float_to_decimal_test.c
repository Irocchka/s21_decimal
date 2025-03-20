#include "test.h"

START_TEST(from_float_to_decimal_check_1) {
  // Arrange
  s21_decimal res = {0};
  float src = 1.123;
  // Act
  s21_from_float_to_decimal(src, &res);
  // Asser
  s21_decimal wanted = {{1123, 0, 0, 0x30000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(from_float_to_decimal_check_2) {
  // Arrange
  s21_decimal res = {0};
  float src = -123.12;
  // Act
  s21_from_float_to_decimal(src, &res);
  // Asser
  s21_decimal wanted = {{12312, 0, 0, 0x80020000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(from_float_to_decimal_check_3) {
  // Arrange
  s21_decimal res = {0};
  float src = 0.1233;
  // Act
  s21_from_float_to_decimal(src, &res);
  // Asser
  s21_decimal wanted = {{1233, 0, 0, 0x40000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(from_float_to_decimal_check_4) {
  // Arrange
  s21_decimal res = {0};
  float src = 1233120;
  // Act
  s21_from_float_to_decimal(src, &res);
  // Asser
  s21_decimal wanted = {{1233120, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(from_float_to_decimal_check_5) {
  // Arrange
  s21_decimal res = {0};
  float src = 1e-29;
  // Act
  int err = s21_from_float_to_decimal(src, &res);
  // Asser
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(from_float_to_decimal_check_6) {
  // Arrange
  s21_decimal res = {0};
  float src = 7.922816251e+29;
  // Act
  int err = s21_from_float_to_decimal(src, &res);
  // Asser
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(from_float_to_decimal_check_7) {
  // Arrange
  s21_decimal res = {0};
  float src = -0.0000012312;
  // Act
  s21_from_float_to_decimal(src, &res);
  // Asser
  s21_decimal wanted = {{12312, 0, 0, 0x800A0000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(from_float_to_decimal_check_8) {
  // Arrange
  s21_decimal* res = NULL;
  float src = -12;
  // Act
  int err = s21_from_float_to_decimal(src, res);
  // Asser
  ck_assert_int_eq(err, 1);
}
END_TEST

Suite* s21_from_float_to_decimal_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_from_float_to_decimal");

  tc = tcase_create("case_s21_from_float_to_decimal");
  tcase_add_test(tc, from_float_to_decimal_check_1);
  tcase_add_test(tc, from_float_to_decimal_check_2);
  tcase_add_test(tc, from_float_to_decimal_check_3);
  tcase_add_test(tc, from_float_to_decimal_check_4);
  tcase_add_test(tc, from_float_to_decimal_check_5);
  tcase_add_test(tc, from_float_to_decimal_check_6);
  tcase_add_test(tc, from_float_to_decimal_check_7);
  tcase_add_test(tc, from_float_to_decimal_check_8);

  suite_add_tcase(s, tc);
  return s;
}
