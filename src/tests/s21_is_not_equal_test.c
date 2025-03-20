#include "test.h"

START_TEST(is_not_equal_check_1) {
  // input
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  // act
  int work = s21_is_not_equal(dec1, dec2);
  // res
  int wanted = 0;
  ck_assert_int_eq(work, wanted);
}
END_TEST

START_TEST(is_not_equal_check_2) {
  // input
  s21_decimal dec1 = {{125, 0, 0, 0}};
  s21_decimal dec2 = {{125, 0, 0, 0}};
  // act
  int work = s21_is_not_equal(dec1, dec2);
  // res
  int wanted = 0;
  ck_assert_int_eq(work, wanted);
}
END_TEST

START_TEST(is_not_equal_check_3) {
  // input
  s21_decimal dec1 = {{125, 0, 0, 0x80000000}};
  s21_decimal dec2 = {{125, 0, 0, 0x80000000}};
  // act
  int work = s21_is_not_equal(dec1, dec2);
  // res
  int wanted = 0;
  ck_assert_int_eq(work, wanted);
}
END_TEST

START_TEST(is_not_equal_check_4) {
  // input
  s21_decimal dec1 = {{125, 0, 0, 0x10000}};
  s21_decimal dec2 = {{125, 0, 0, 0x40000}};
  // act
  int work = s21_is_not_equal(dec1, dec2);
  // res
  int wanted = 1;
  ck_assert_int_eq(work, wanted);
}
END_TEST

START_TEST(is_not_equal_check_5) {
  // input
  s21_decimal dec1 = {{125, 0, 0, 0x80010000}};
  s21_decimal dec2 = {{125, 0, 0, 0x80040000}};
  // act
  int work = s21_is_not_equal(dec1, dec2);
  // res
  int wanted = 1;
  ck_assert_int_eq(work, wanted);
}
END_TEST

START_TEST(is_not_equal_check_6) {
  // input
  s21_decimal dec1 = {{12123, 0, 0, 0x80010000}};
  s21_decimal dec2 = {{125, 0, 0, 0x80010000}};
  // act
  int work = s21_is_not_equal(dec1, dec2);
  // res
  int wanted = 1;
  ck_assert_int_eq(work, wanted);
}
END_TEST

START_TEST(is_not_equal_check_7) {
  // input
  s21_decimal dec1 = {{12123, 0, 0, 0x0010000}};
  s21_decimal dec2 = {{125, 0, 0, 0x0010000}};
  // act
  int work = s21_is_not_equal(dec1, dec2);
  // res
  int wanted = 1;
  ck_assert_int_eq(work, wanted);
}
END_TEST

START_TEST(is_not_equal_check_8) {
  // input
  s21_decimal dec1 = {{12123, 0, 0, 0x80010000}};
  s21_decimal dec2 = {{125, 0, 0, 0x0010000}};
  // act
  int work = s21_is_not_equal(dec1, dec2);
  // res
  int wanted = 1;
  ck_assert_int_eq(work, wanted);
}
END_TEST

START_TEST(is_not_equal_check_9) {
  // input
  s21_decimal dec1 = {{12123, 0, 0, 0x0010000}};
  s21_decimal dec2 = {{125, 0, 0, 0x80010000}};
  // act
  int work = s21_is_not_equal(dec1, dec2);
  // res
  int wanted = 1;
  ck_assert_int_eq(work, wanted);
}
END_TEST

START_TEST(is_not_equal_check_10) {
  // input
  s21_decimal dec1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000000}};
  s21_decimal dec2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x000000}};
  // act
  int work = s21_is_not_equal(dec1, dec2);
  // res
  int wanted = 0;
  ck_assert_int_eq(work, wanted);
}
END_TEST

Suite* s21_is_not_equal_suite() {
  Suite* s;
  TCase* tc;

  s = suite_create("s21_is_not_equal");

  tc = tcase_create("case_s21_is_not_equal");
  tcase_add_test(tc, is_not_equal_check_1);
  tcase_add_test(tc, is_not_equal_check_2);
  tcase_add_test(tc, is_not_equal_check_3);
  tcase_add_test(tc, is_not_equal_check_4);
  tcase_add_test(tc, is_not_equal_check_5);
  tcase_add_test(tc, is_not_equal_check_6);
  tcase_add_test(tc, is_not_equal_check_7);
  tcase_add_test(tc, is_not_equal_check_8);
  tcase_add_test(tc, is_not_equal_check_9);
  tcase_add_test(tc, is_not_equal_check_10);

  suite_add_tcase(s, tc);
  return s;
}