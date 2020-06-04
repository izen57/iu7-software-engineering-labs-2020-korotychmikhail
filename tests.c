#include <stdio.h>
#include <string.h>
#include "bin_to_hex.h"
#define MAX_LENGHT_OF_BIN 128
int bin_to_hex_positive_test(char *expected_hex, int expected_error)
{
	char actual_hex[MAX_LENGHT_OF_BIN / 4 + 1];
	for (int i = 0; i <= MAX_LENGHT_OF_BIN / 4 + 1; i++)
		actual_hex[i] = '\0';
	int error = bin_to_hex("1000111101000000111100011", actual_hex);
	if (error != expected_error)
		return 1;
	if (strcmp(actual_hex, expected_hex))
		return 1;
	return 0;
}
int bin_to_hex_should_works_correct_with_negative_number(char *expected_hex, int expected_error)
{
	char actual_hex[MAX_LENGHT_OF_BIN / 4 + 1];
	for (int i = 0; i <= MAX_LENGHT_OF_BIN / 4 + 1; i++)
		actual_hex[i] = '\0';
	int error = bin_to_hex("10000111", actual_hex);
	if (error != expected_error)
		return 1;
	if (strcmp(actual_hex, expected_hex))
		return 1;
	return 0;
}
int bin_to_hex_negative_test(int expected_error)
{
	char actual_hex[MAX_LENGHT_OF_BIN / 4 + 1];
	for (int i = 0; i <= MAX_LENGHT_OF_BIN / 4 + 1; i++)
		actual_hex[i] = '\0';
	int error = bin_to_hex("4567", actual_hex);
	if (error != expected_error)
		return 1;
	return 0;
}
int bin_to_hex_should_works_correct_with_lot_of_numerals(char *expected_hex, int expected_error)
{
	char actual_hex[MAX_LENGHT_OF_BIN / 4 + 1];
	for (int i = 0; i <= MAX_LENGHT_OF_BIN / 4 + 1; i++)
		actual_hex[i] = '\0';
	int error = bin_to_hex("000000", actual_hex);
	if (error != expected_error)
		return 1;
	if (strcmp(actual_hex, expected_hex))
		return 1;
	return 0;
}
int bin_to_hex_should_works_correct_with_one_number(char *expected_hex, int expected_error)
{
	char actual_hex[MAX_LENGHT_OF_BIN / 4 + 1];
	for (int i = 0; i <= MAX_LENGHT_OF_BIN / 4 + 1; i++)
		actual_hex[i] = '\0';
	int error = bin_to_hex("1", actual_hex);
	if (error != expected_error)
		return 1;
	if (strcmp(actual_hex, expected_hex))
		return 1;
	return 0;
}
int main(void)
{
	int failed_tests = 0, total_tests = 0;
	failed_tests += bin_to_hex_should_works_correct_with_one_number("1", 0);
	total_tests++;
	failed_tests += bin_to_hex_should_works_correct_with_lot_of_numerals("0", 0);
	total_tests++;
	failed_tests += bin_to_hex_negative_test(1);
	total_tests++;
	failed_tests += bin_to_hex_should_works_correct_with_negative_number("87", 0);
	total_tests++;
	failed_tests += bin_to_hex_positive_test("11e81e3", 0);
	total_tests++;
	printf("Failed tests: %d of %d", failed_tests, total_tests);
	return 0;
}