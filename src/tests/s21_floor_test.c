#include "test.h"

START_TEST(floor_check_1) {
  // Arrange
  s21_decimal dec1 = {{235, 0, 0, 0x20000}};
  s21_decimal res = {0};
  // Act
  s21_floor(dec1, &res);
  // Asser
  s21_decimal wanted = {{2, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(floor_check_2) {
  // Arrange
  s21_decimal dec1 = {{267, 0, 0, 0x20000}};
  s21_decimal res = {0};
  // Act
  s21_floor(dec1, &res);
  // Assert
  s21_decimal wanted = {{2, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(floor_check_3) {
  // Arrange
  s21_decimal dec1 = {{235, 0, 0, 0x80020000}};
  s21_decimal res = {0};
  // Act
  s21_floor(dec1, &res);
  s21_decimal wanted = {{3, 0, 0, 0x80000000}};
  // Assert
  ck_assert_int_eq(compare_struct(wanted, res), 1);
}
END_TEST

START_TEST(floor_check_4) {
  // Arrange
  s21_decimal dec1 = {{456, 0, 0, 0x80000000}};
  s21_decimal* res = NULL;
  // Act
  int err = s21_floor(dec1, res);
  // Asser
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(floor_check_5) {
  // Arrange
  s21_decimal dec1 = {{49, 0, 0, 0x10000}};
  s21_decimal res = {0};
  // Act
  s21_floor(dec1, &res);
  s21_decimal wanted = {{4, 0, 0, 0}};
  // Asser
  ck_assert_int_eq(compare_struct(wanted, res), 1);
}
END_TEST

START_TEST(floor_check_6) {
  // Arrange
  s21_decimal dec1 = {{49, 0, 0, 0x80010000}};
  s21_decimal res = {0};
  // Act
  s21_floor(dec1, &res);
  s21_decimal wanted = {{5, 0, 0, 0x80000000}};
  // Asser
  ck_assert_int_eq(compare_struct(wanted, res), 1);
}
END_TEST

START_TEST(floor_check_7) {
  // Arrange
  s21_decimal dec1 = {{49, 0, 0, 0}};
  s21_decimal res = {0};
  // Act
  s21_floor(dec1, &res);
  s21_decimal wanted = {{49, 0, 0, 0}};
  // Asser
  ck_assert_int_eq(compare_struct(wanted, res), 1);
}
END_TEST

Suite* s21_floor_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_floor");

  tc = tcase_create("case_s21_floor");
  tcase_add_test(tc, floor_check_1);
  tcase_add_test(tc, floor_check_2);
  tcase_add_test(tc, floor_check_3);
  tcase_add_test(tc, floor_check_4);
  tcase_add_test(tc, floor_check_5);
  tcase_add_test(tc, floor_check_6);
  tcase_add_test(tc, floor_check_7);

  suite_add_tcase(s, tc);
  return s;
}
