#include "test.h"

START_TEST(div_check_1) {
  // Arrange
  s21_decimal dec1 = {{42, 0, 0, 0}};
  s21_decimal dec2 = {{42, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  // Получается отрицательный ноль
  s21_div(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{1, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(div_check_2) {
  // Arrange
  s21_decimal dec1 = {{562, 0, 0, 0}};
  s21_decimal dec2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_div(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{281, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(div_check_3) {
  // Arrange
  s21_decimal dec1 = {{456, 0, 0, 0x50000}};
  s21_decimal dec2 = {{3, 0, 0, 0x70000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_div(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{15200, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(div_check_4) {
  // Arrange
  s21_decimal dec1 = {{56, 0, 0, 0x50000}};
  s21_decimal dec2 = {{120, 0, 0, 0x80000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_div(dec1, dec2, &res);
  // Assert
  s21_decimal wanted = {{0x3AAAAAAB, 0xE9CD011C, 0xF142D1A, 0x190000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(div_check_5) {
  // Arrange
  s21_decimal dec1 = {{56, 0, 0, 0x80050000}};
  s21_decimal dec2 = {{120, 0, 0, 0x80080000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_div(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0x3AAAAAAB, 0xE9CD011C, 0xF142D1A, 0x190000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(div_check_6) {
  // Arrange
  s21_decimal dec1 = {{506285, 0, 0, 0x50000}};
  s21_decimal dec2 = {{105603, 0, 0, 0x80080000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_div(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0xF3E85E82, 0xC826FEEE, 0xF7DB18C, 0x80180000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(div_check_7) {
  // Arrange
  s21_decimal dec1 = {{2, 0, 0, 0}};
  s21_decimal dec2 = {{5, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_div(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{4, 0, 0, 0x10000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(div_check_8) {
  // Arrange
  s21_decimal dec1 = {{535, 0, 0, 0x50000}};
  s21_decimal dec2 = {{7, 0, 0, 0x80000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_div(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0x97A4924A, 0x1DAC8BF3, 0x65270, 0x801C0000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(div_check_9) {
  // Arrange
  s21_decimal dec1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal dec2 = {{5, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_div(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{858993459, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(div_check_10) {
  // Arrange
  s21_decimal dec1 = {{0xFFFFFFFF, 0, 0, 0x50000}};
  s21_decimal dec2 = {{0xFFFFFFFF, 0, 0, 0x60000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_div(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{10, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

Suite* s21_div_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_div");

  tc = tcase_create("case_s21_div");
  tcase_add_test(tc, div_check_1);
  tcase_add_test(tc, div_check_2);
  tcase_add_test(tc, div_check_3);
  tcase_add_test(tc, div_check_4);
  tcase_add_test(tc, div_check_5);
  tcase_add_test(tc, div_check_6);
  tcase_add_test(tc, div_check_7);
  tcase_add_test(tc, div_check_8);
  tcase_add_test(tc, div_check_9);
  tcase_add_test(tc, div_check_10);

  suite_add_tcase(s, tc);
  return s;
}