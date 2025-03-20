#include "test.h"

START_TEST(add_check_1) {
  // Arrange
  s21_decimal dec1 = {{42, 0, 0, 0}};
  s21_decimal dec2 = {{42, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_add(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{84, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(add_check_2) {
  // Arrange
  s21_decimal dec1 = {{42, 0, 0, 0x80000000}};
  s21_decimal dec2 = {{42, 0, 0, 0x80000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_add(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{84, 0, 0, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(add_check_3) {
  // Arrange
  s21_decimal dec1 = {{56, 0, 0, 0x100000}};
  s21_decimal dec2 = {{120, 0, 0, 0x130000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_add(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{56120, 0, 0, 0x130000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(add_check_4) {
  // Arrange
  s21_decimal dec1 = {{56, 0, 0, 0x80000000}};
  s21_decimal dec2 = {{120, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_add(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{64, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(add_check_5) {
  // Arrange
  s21_decimal dec1 = {{56, 0, 0, 0}};
  s21_decimal dec2 = {{120, 0, 0, 0x80000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_add(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{64, 0, 0, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(add_check_6) {
  // Arrange
  s21_decimal dec1 = {{56, 0, 0, 0x80160000}};
  s21_decimal dec2 = {{120, 0, 0, 0x80150000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_add(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0b10011101000, 0, 0, 0x80160000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(add_check_7) {
  // Arrange
  s21_decimal dec1 = {{0, 0, 0, 0x80000000}};
  s21_decimal dec2 = {{0, 0, 0, 0x80000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_add(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(add_check_8) {
  // Arrange
  s21_decimal dec1 = {{0, 56, 0, 0x80000000}};
  s21_decimal dec2 = {{0, 120, 0, 0x80000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_add(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0, 176, 0, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(add_check_9) {
  // Arrange
  s21_decimal dec1 = {{56, 56, 56, 0}};
  s21_decimal dec2 = {{120, 120, 120, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_add(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{176, 176, 176, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(add_check_10) {
  // Arrange
  s21_decimal dec1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal dec2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_add(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0xFFFFFFFE, 1, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(add_check_11) {
  // Arrange
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000}};
  s21_decimal dec2 = {{1, 0, 0, 0x0000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  int err = s21_add(dec1, dec2, &res);
  // Asser
  ck_assert_int_eq(err, 1);
}
END_TEST

Suite* s21_add_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_add");

  tc = tcase_create("case_s21_add");
  tcase_add_test(tc, add_check_1);
  tcase_add_test(tc, add_check_2);
  tcase_add_test(tc, add_check_3);
  tcase_add_test(tc, add_check_4);
  tcase_add_test(tc, add_check_5);
  tcase_add_test(tc, add_check_6);
  tcase_add_test(tc, add_check_7);
  tcase_add_test(tc, add_check_8);
  tcase_add_test(tc, add_check_9);
  tcase_add_test(tc, add_check_10);
  tcase_add_test(tc, add_check_11);

  suite_add_tcase(s, tc);
  return s;
}