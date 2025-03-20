#include "test.h"

START_TEST(from_int_to_decimal_check_1) {
  // Arrange
  s21_decimal res = {0};
  int src = 123;
  // Act
  s21_from_int_to_decimal(src, &res);
  // Asser
  s21_decimal wanted = {{123, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(from_int_to_decimal_check_2) {
  // Arrange
  s21_decimal res = {0};
  int src = -12312;
  // Act
  s21_from_int_to_decimal(src, &res);
  // Asser
  s21_decimal wanted = {{12312, 0, 0, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(from_int_to_decimal_check_3) {
  // Arrange
  s21_decimal* res = NULL;
  int src = -12;
  // Act
  int err = s21_from_int_to_decimal(src, res);
  // Asser
  ck_assert_int_eq(err, 1);
}
END_TEST

Suite* s21_from_int_to_decimal_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_from_int_to_decimal");

  tc = tcase_create("case_s21_from_int_to_decimal");
  tcase_add_test(tc, from_int_to_decimal_check_1);
  tcase_add_test(tc, from_int_to_decimal_check_2);
  tcase_add_test(tc, from_int_to_decimal_check_3);

  suite_add_tcase(s, tc);
  return s;
}
