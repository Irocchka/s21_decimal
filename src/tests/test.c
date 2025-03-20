#include "test.h"

int run_tests(Suite* s);

int main() {
  Suite* all_cases[] = {s21_add_suite(),
                        s21_sub_suite(),
                        s21_mult_suite(),
                        s21_div_suite(),
                        s21_negate_suite(),
                        s21_round_suite(),
                        s21_is_equal_suite(),
                        s21_is_not_equal_suite(),
                        s21_is_less_suite(),
                        s21_is_less_or_equal_suite(),
                        s21_is_greater_suite(),
                        s21_is_greater_or_equal_suite(),
                        s21_from_decimal_to_float_suite(),
                        s21_from_float_to_decimal_suite(),
                        s21_from_decimal_to_int_suite(),
                        s21_from_int_to_decimal_suite(),
                        s21_floor_suite(),
                        s21_truncate_suite()};

  for (int i = 0; i < 18; i++) {
    run_tests(all_cases[i]);
  }
  return 0;
}

int run_tests(Suite* s) {
  SRunner* runner;
  runner = srunner_create(s);
  int failed = 0;
  srunner_run_all(runner, CK_NORMAL);
  failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int compare_struct(s21_decimal dec1, s21_decimal dec2) {
  return (dec1.bits[0] == dec2.bits[0] && dec1.bits[1] == dec2.bits[1] &&
          dec1.bits[2] == dec2.bits[2] && dec1.bits[3] == dec2.bits[3]);
}
