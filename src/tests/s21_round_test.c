#include "test.h"

START_TEST(round_check_1) {
  // Arrange
  s21_decimal dec1 = {{123321, 0, 0, 0x30000}};
  s21_decimal res = {0};
  // Act
  s21_round(dec1, &res);
  // Asser
  s21_decimal wanted = {{123, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(round_check_2) {
  // Arrange
  s21_decimal dec1 = {{56291238, 0, 0, 0}};
  s21_decimal res = {0};
  // Act
  s21_round(dec1, &res);
  // Assert
  s21_decimal wanted = {{56291238, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(round_check_3) {
  // Arrange
  s21_decimal dec1 = {{123456, 0, 0, 0x20000}};
  s21_decimal res = {0};
  // Act
  s21_round(dec1, &res);
  s21_decimal wanted = {{1235, 0, 0, 0}};
  // Assert
  ck_assert_int_eq(compare_struct(wanted, res), 1);
}
END_TEST

START_TEST(round_check_4) {
  // Arrange
  s21_decimal dec1 = {{123456, 0, 0, 0x80020000}};
  s21_decimal res = {0};
  // Act
  s21_round(dec1, &res);
  s21_decimal wanted = {{1235, 0, 0, 0x80000000}};
  // Assert
  ck_assert_int_eq(compare_struct(wanted, res), 1);
}
END_TEST

START_TEST(round_check_5) {
  // Arrange
  s21_decimal dec1 = {{456, 234, 0, 0x80000000}};
  s21_decimal* res = NULL;
  // Act
  int err = s21_round(dec1, res);
  // Asser
  ck_assert_int_eq(err, 1);
}
END_TEST

START_TEST(round_check_6) {
  // Arrange
  s21_decimal dec1 = {{451, 0, 0, 0x80010000}};
  s21_decimal res = {0};
  // Act
  s21_round(dec1, &res);
  // Asser
  s21_decimal wanted = {{45, 0, 0, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

Suite* s21_round_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_round");

  tc = tcase_create("case_s21_round");
  tcase_add_test(tc, round_check_1);
  tcase_add_test(tc, round_check_2);
  tcase_add_test(tc, round_check_3);
  tcase_add_test(tc, round_check_4);
  tcase_add_test(tc, round_check_5);
  tcase_add_test(tc, round_check_6);

  suite_add_tcase(s, tc);
  return s;
}
