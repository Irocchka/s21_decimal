#include "test.h"

START_TEST(mult_check_1) {  // ok
  // Arrange
  s21_decimal dec1 = {{42, 0, 0, 0}};
  s21_decimal dec2 = {{42, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_mult(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{1764, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(mult_check_2) {  // ok
  // Arrange
  s21_decimal dec1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal dec2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_mult(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0xFFFFFFFE, 1, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(mult_check_3) {  // ok
  // Arrange
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_mult(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{0, 0, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(mult_check_4) {  // ok
  // Arrange
  s21_decimal dec1 = {{56, 0, 0, 0x50000}};
  s21_decimal dec2 = {{120, 0, 0, 0x80000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_mult(dec1, dec2, &res);
  // Assert
  s21_decimal wanted = {{6720, 0, 0, 0xD0000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(mult_check_5) {  // ok
  // Arrange
  s21_decimal dec1 = {{56, 0, 0, 0x80050000}};
  s21_decimal dec2 = {{120, 0, 0, 0x80080000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_mult(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{6720, 0, 0, 0xD0000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(mult_check_6) {  // ok
  // Arrange
  // 26409387504754779197847983445
  s21_decimal dec1 = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  // 1.9999999999999999999999999000
  s21_decimal dec2 = {{0x1FFFFC18, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_mult(dec1, dec2, &res);
  // Asser
  // 52818775009509558395695964249
  s21_decimal wanted = {{0xAAAAA059, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(mult_check_7) {  // ok
  // Arrange
  s21_decimal dec1 = {{535, 0, 0, 0x50000}};
  s21_decimal dec2 = {{7, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_mult(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{3745, 0, 0, 0x50000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(mult_check_8) {  // ok
  // Arrange
  s21_decimal dec1 = {{535, 0, 0, 0x50000}};
  s21_decimal dec2 = {{7, 0, 0, 0x80000000}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_mult(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{3745, 0, 0, 0x80050000}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

START_TEST(mult_check_9) {  // ok
  // Arrange
  s21_decimal dec1 = {{56, 56, 56, 0}};
  s21_decimal dec2 = {{120, 120, 120, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act переполнение
  int error = s21_mult(dec1, dec2, &res);
  // Asser
  ck_assert_int_eq(error, 1);
}
END_TEST

START_TEST(mult_check_10) {  // ок
  // Arrange
  s21_decimal dec1 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal dec2 = {{0xFFFFFFFF, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  // Act
  s21_mult(dec1, dec2, &res);
  // Asser
  s21_decimal wanted = {{1, 0xFFFFFFFE, 0, 0}};
  ck_assert_int_eq(compare_struct(res, wanted), 1);
}
END_TEST

Suite* s21_mult_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_mult");

  tc = tcase_create("case_s21_mult");
  tcase_add_test(tc, mult_check_1);
  tcase_add_test(tc, mult_check_2);
  tcase_add_test(tc, mult_check_3);
  tcase_add_test(tc, mult_check_4);
  tcase_add_test(tc, mult_check_5);
  tcase_add_test(tc, mult_check_6);
  tcase_add_test(tc, mult_check_7);
  tcase_add_test(tc, mult_check_8);
  tcase_add_test(tc, mult_check_9);
  tcase_add_test(tc, mult_check_10);

  suite_add_tcase(s, tc);
  return s;
}