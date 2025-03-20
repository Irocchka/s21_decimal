#include "test.h"

START_TEST(from_decimal_to_int_check_1) {
  // Arrange
  s21_decimal dec1 = {{42123, 0, 0, 0}};
  int res = 0;
  // Act
  s21_from_decimal_to_int(dec1, &res);
  // Asser
  int wanted = 42123;
  ck_assert_int_eq(res, wanted);
}
END_TEST

START_TEST(from_decimal_to_int_check_2) {
  // Arrange
  s21_decimal dec1 = {{562, 0, 0, 0x10000}};
  int res = 0;
  // Act
  s21_from_decimal_to_int(dec1, &res);
  // Asser
  int wanted = 56;
  ck_assert_int_eq(res, wanted);
}
END_TEST

START_TEST(from_decimal_to_int_check_3) {
  // Arrange
  s21_decimal dec1 = {{451444, 0, 0, 0x80070000}};
  int res = 0;
  // Act
  s21_from_decimal_to_int(dec1, &res);
  // Asser
  int wanted = 0;
  ck_assert_int_eq(wanted, res);
}
END_TEST

START_TEST(from_decimal_to_int_check_5) {
  // Arrange
  s21_decimal dec1 = {{123, 0, 0, 0x80000000}};
  int res = 0;
  // Act
  s21_from_decimal_to_int(dec1, &res);
  // Asser
  int wanted = -123;
  ck_assert_int_eq(wanted, res);
}
END_TEST

START_TEST(from_decimal_to_int_check_4) {
  // Arrange
  s21_decimal dec1 = {{123, 1, 0, 0x80000000}};
  int res = 0;
  // Act
  int err = s21_from_decimal_to_int(dec1, &res);
  // Asser
  ck_assert_int_eq(err, 1);
}
END_TEST

Suite* s21_from_decimal_to_int_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_from_decimal_to_int");

  tc = tcase_create("case_s21_from_decimal_to_int");
  tcase_add_test(tc, from_decimal_to_int_check_1);
  tcase_add_test(tc, from_decimal_to_int_check_2);
  tcase_add_test(tc, from_decimal_to_int_check_3);
  tcase_add_test(tc, from_decimal_to_int_check_4);
  tcase_add_test(tc, from_decimal_to_int_check_5);

  suite_add_tcase(s, tc);
  return s;
}
