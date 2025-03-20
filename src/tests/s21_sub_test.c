#include "test.h"

START_TEST(sub_check_1) {
  // Arrange
  s21_decimal dec1 = {{42, 0, 0, 0}};
  s21_decimal dec2 = {{42, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  // Получается отрицательный ноль
  s21_sub(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(sub_check_2) {
  // Arrange
  s21_decimal dec1 = {{120, 0, 0, 0x80000000}};
  s21_decimal dec2 = {{42, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_sub(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{162, 0, 0, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(sub_check_3) {
  // Arrange
  s21_decimal dec1 = {{56, 0, 0, 0x100000}};
  s21_decimal dec2 = {{120, 0, 0, 0x130000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_sub(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{55880, 0, 0, 0x130000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(sub_check_4) {
  // Arrange
  s21_decimal dec1 = {{56, 0, 0, 0}};
  s21_decimal dec2 = {{120, 0, 0, 0x80000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_sub(dec1, dec2, &res);
  // Assert
  s21_decimal wanted = {{176, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(sub_check_5) {
  // Arrange
  s21_decimal dec1 = {{56, 0, 0, 0x100000}};
  s21_decimal dec2 = {{20, 0, 0, 0x80140000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_sub(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{560020, 0, 0, 0x140000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(sub_check_6) {
  // Arrange
  s21_decimal dec1 = {{50, 0, 0, 0x80160000}};
  s21_decimal dec2 = {{120, 0, 0, 0x80150000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_sub(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{1150, 0, 0, 0x160000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(sub_check_7) {
  // Arrange
  s21_decimal dec1 = {{0, 0, 0, 0x80000000}};
  s21_decimal dec2 = {{0, 0, 0, 0x80000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_sub(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0, 0, 0, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(sub_check_8) {
  // Arrange
  s21_decimal dec1 = {{0, 50, 0, 0x80000000}};
  s21_decimal dec2 = {{0, 120, 0, 0x80000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_sub(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0, 70, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(sub_check_9) {
  // Arrange
  s21_decimal dec1 = {{56, 56, 56, 0}};
  s21_decimal dec2 = {{120, 120, 120, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_sub(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{64, 64, 64, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(sub_check_10) {
  // Arrange
  s21_decimal dec1 = {{0xFFFFFFFF, 0, 0, 0x80000000}};
  s21_decimal dec2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_sub(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0xFFFFFFFE, 1, 0, 0x80000000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(sub_check_11) {
  // Arrange
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  s21_decimal dec2 = {{1, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  int err = s21_sub(dec1, dec2, &res);
  // Asser
  ck_assert_int_eq(err, 2);
}
END_TEST

Suite* s21_sub_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_sub");

  tc = tcase_create("case_s21_sub");
  tcase_add_test(tc, sub_check_1);
  tcase_add_test(tc, sub_check_2);
  tcase_add_test(tc, sub_check_3);
  tcase_add_test(tc, sub_check_4);
  tcase_add_test(tc, sub_check_5);
  tcase_add_test(tc, sub_check_6);
  tcase_add_test(tc, sub_check_7);
  tcase_add_test(tc, sub_check_8);
  tcase_add_test(tc, sub_check_9);
  tcase_add_test(tc, sub_check_10);
  tcase_add_test(tc, sub_check_11);

  suite_add_tcase(s, tc);
  return s;
}