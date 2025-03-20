#include "test.h"

START_TEST(negate_check_1) {
  // Arrange
  s21_decimal dec1 = {{42, 0, 0, 0}};
  s21_decimal res = {0};
  // Act
  s21_negate(dec1, &res);
  // Asser
  s21_decimal wanted = {{42, 0, 0, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(negate_check_2) {
  // Arrange
  s21_decimal dec1 = {{562, 0, 0, 0x80000000}};
  s21_decimal res = {0};
  // Act
  s21_negate(dec1, &res);
  // Asser
  s21_decimal wanted = {{562, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(negate_check_3) {
  // Arrange
  s21_decimal dec1 = {{456, 234, 0, 0x80000000}};
  s21_decimal* res = NULL;
  // Act
  int err = s21_negate(dec1, res);
  // Asser
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(negate_check_4) {
  // Arrange
  s21_decimal dec1 = {{456, 234, 0, 0x80000000}};
  s21_decimal res = {0};
  // Act
  s21_negate(dec1, &res);
  // Assert
  s21_decimal wanted = {{456, 234, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

Suite* s21_negate_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_negate");

  tc = tcase_create("case_s21_negate");
  tcase_add_test(tc, negate_check_1);
  tcase_add_test(tc, negate_check_2);
  tcase_add_test(tc, negate_check_3);
  tcase_add_test(tc, negate_check_4);

  suite_add_tcase(s, tc);
  return s;
}
