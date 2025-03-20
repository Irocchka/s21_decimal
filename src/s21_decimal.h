#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALSE 0
#define TRUE 1

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef struct {
  unsigned int bits[8];
} s21_big_decimal;

// Arithmetic
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_mult(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal* result);

// Bit operations for decimal
int get_bit(s21_decimal value, int index);
void set_bit(s21_decimal* value, int index, int bit);
int get_sign(s21_decimal value);
void set_sign(s21_decimal* value, int sign);
int get_exp(s21_decimal value);
void set_exp(s21_decimal* value, int exp);
void zeroes_struct(s21_decimal* dec);
int find_over_flow(s21_decimal dec);

// Bit operations for big_decimal
int get_bit_big(s21_big_decimal value, int index);
void set_bit_big(s21_big_decimal* value, int index, int bit);
int get_sign_big(s21_big_decimal value);
void set_sign_big(s21_big_decimal* value, int sign);
int get_exp_big(s21_big_decimal value);
void set_exp_big(s21_big_decimal* value, int exp);

// Compare
int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal_only_mantiss(s21_decimal value_1,
                                         s21_decimal value_2);

// Compare for big decimal
int s21_is_less_big(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_equal_big(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_greater_or_equal_big(s21_big_decimal value_1,
                                s21_big_decimal value_2);
int s21_is_greater_big(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_not_equal_big(s21_big_decimal value_1, s21_big_decimal value_2);
int s21_is_greater_or_equal_only_mantiss_big(s21_big_decimal value_1,
                                             s21_big_decimal value_2);

// banc round
int banc_round_error(s21_big_decimal* result);
void s21_banc_round_big(s21_big_decimal value, s21_big_decimal* result);
void s21_div_10_big(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal* result_1, s21_big_decimal* result_2);

// Helpers decimal
int s21_add_only_mantiss(s21_decimal value_1, s21_decimal value_2,
                         s21_decimal* result);
void pow_to_ten(s21_decimal* dec, int pow_count);
void normalization(s21_decimal* dec1, s21_decimal* dec2);
int declen(s21_decimal dec);
int maxdec(s21_decimal dec1, s21_decimal dec2);
void shift_left(s21_decimal* dec, int shift_count);

// Helpers big_decimal
int maxdec_big(s21_big_decimal dec1, s21_big_decimal dec2);
void normalization_big(s21_big_decimal* dec1, s21_big_decimal* dec2);
void reverse_big(s21_big_decimal* dec, int len);
int declen_big(s21_big_decimal dec);
void shift_left_big(s21_big_decimal* dec, int count_shift);
void pow_to_ten_big(s21_big_decimal* dec, int pow_count);
void normalization_big(s21_big_decimal* dec1, s21_big_decimal* dec2);

// Converse
void s21_decimal_to_big_decimal(s21_decimal value_1, s21_big_decimal* result);
void s21_big_decimal_to_decimal(s21_big_decimal value_1, s21_decimal* result);
int s21_from_int_to_decimal(int src, s21_decimal* dst);
int s21_from_float_to_decimal(float src, s21_decimal* dst);
int s21_from_decimal_to_int(s21_decimal src, int* dst);
int s21_from_decimal_to_float(s21_decimal src, float* dst);
int get_exp_from_char(char* src);
void nota_to_decimal(char* src, s21_decimal* dst);
int processing_exp(int exp, float src);
int count_zeroes_after_dot(char* nota);
bool get_bit_int(int src, int ind);

// Arithmetic Common Help
void sub_origin_big(s21_big_decimal value_1, s21_big_decimal value_2,
                    s21_big_decimal* result);
void s21_sub_big(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal* result);
void s21_add_only_mantiss_big(s21_big_decimal value_1, s21_big_decimal value_2,
                              s21_big_decimal* result);
void s21_add_big(s21_big_decimal val_1, s21_big_decimal val_2,
                 s21_big_decimal* res);
void set_div_exp(s21_big_decimal* res, int dif_exp, int count_power);

// Others
int s21_floor(s21_decimal value, s21_decimal* result);
int s21_round(s21_decimal value, s21_decimal* result);
int s21_truncate(s21_decimal value, s21_decimal* result);
int s21_negate(s21_decimal value, s21_decimal* result);
void div_10(s21_decimal value, s21_decimal* result);
void div_10_for_remains(s21_decimal value, s21_decimal* integer,
                        s21_decimal* remains);
#endif