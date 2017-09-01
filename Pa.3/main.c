/*
Name:        Jasdeep Singh 
Professor:   Andrew O'Fallon 
T.A:         Sam Chen
Class:       Computer Science 121 
Lab Section: 6
Date:        9/19/26
Description: This program will open a file and compute the number of lines, 
             vowels, characters, upper case, lower case, and number in the program.
*/

#include "equations.h"
int main(void) {

	char char1 = '\0', char2 = '\0', char3 = '\0', char4 = '\0', char5 = '\0';
	char char6 = '\0', char7 = '\0', char8 = '\0', char9 = '\0', char10 = '\0';
	int ascii1 = 0, ascii2 = 0, ascii3 = 0, ascii4 = 0, ascii5 = 0, ascii6 = 0;
	int ascii7 = 0, ascii8 = 0, ascii9 = 0, ascii10 = 0;
	char character = '\0';
	int ascii_value_count = 0, line_count = 0, vowel_count = 0, digit_count = 0, puncts_count = 0;
	int alpha_count = 0, lower_case_count = 0, upper_case_count = 0, space_count = 0, alnum_count = 0;

	FILE *infile = NULL;
	FILE *output_stats = NULL;
	FILE *output_ascii = NULL;
	infile = open_input_file();
	output_ascii = open_output_ascii();
	output_stats = open_output_stats();

	char1 = read_character(infile);
	ascii1 = determine_ascii_value(char1);
	line_count = number_lines(char1, line_count);
	vowel_count = number_vowels(char1, vowel_count);
	digit_count = number_digits(char1, digit_count);
	alpha_count = number_alphas(char1, alpha_count);
	lower_case_count = number_lowers(char1, lower_case_count);
	upper_case_count = number_uppers(char1, upper_case_count);
	space_count = number_spaces(char1, space_count);
	alnum_count = number_alnums(char1, alnum_count);
	puncts_count = number_puncts(char1, puncts_count);
	print_int(output_ascii, ascii1);

	char2 = read_character(infile);
	ascii2 = determine_ascii_value(char2);
	line_count = number_lines(char2, line_count);
	vowel_count = number_vowels(char2, vowel_count);
	digit_count = number_digits(char2, digit_count);
	alpha_count = number_alphas(char2, alpha_count);
	lower_case_count = number_lowers(char2, lower_case_count);
	upper_case_count = number_uppers(char2, upper_case_count);
	space_count = number_spaces(char2, space_count);
	alnum_count = number_alnums(char2, alnum_count);
	puncts_count = number_puncts(char2, puncts_count);
	print_int(output_ascii, ascii2);

	char3 = read_character(infile);
	ascii3 = determine_ascii_value(char3);
	line_count = number_lines(char3, line_count);
	vowel_count = number_vowels(char3, vowel_count);
	digit_count = number_digits(char3, digit_count);
	alpha_count = number_alphas(char3, alpha_count);
	lower_case_count = number_lowers(char3, lower_case_count);
	upper_case_count = number_uppers(char3, upper_case_count);
	space_count = number_spaces(char3, space_count);
	alnum_count = number_alnums(char3, alnum_count);
	puncts_count = number_puncts(char3, puncts_count);
	print_int(output_ascii, ascii3);

	char4 = read_character(infile);
	ascii4 = determine_ascii_value(char4);
	line_count = number_lines(char4, line_count);
	vowel_count = number_vowels(char4, vowel_count);
	digit_count = number_digits(char4, digit_count);
	alpha_count = number_alphas(char4, alpha_count);
	lower_case_count = number_lowers(char4, lower_case_count);
	upper_case_count = number_uppers(char4, upper_case_count);
	space_count = number_spaces(char4, space_count);
	alnum_count = number_alnums(char4, alnum_count);
	puncts_count = number_puncts(char4, puncts_count);
	print_int(output_ascii, ascii4);

	char5 = read_character(infile);
	ascii5 = determine_ascii_value(char5);
	line_count = number_lines(char5, line_count);
	vowel_count = number_vowels(char5, vowel_count);
	digit_count = number_digits(char5, digit_count);
	alpha_count = number_alphas(char5, alpha_count);
	lower_case_count = number_lowers(char5, lower_case_count);
	upper_case_count = number_uppers(char5, upper_case_count);
	space_count = number_spaces(char5, space_count);
	alnum_count = number_alnums(char5, alnum_count);
	puncts_count = number_puncts(char5, puncts_count);
	print_int(output_ascii, ascii5);

	char6 = read_character(infile);
	ascii6 = determine_ascii_value(char6);
	line_count = number_lines(char6, line_count);
	vowel_count = number_vowels(char6, vowel_count);
	digit_count = number_digits(char6, digit_count);
	alpha_count = number_alphas(char6, alpha_count);
	lower_case_count = number_lowers(char6, lower_case_count);
	upper_case_count = number_uppers(char6, upper_case_count);
	space_count = number_spaces(char6, space_count);
	alnum_count = number_alnums(char6, alnum_count);
	puncts_count = number_puncts(char6, puncts_count);
	print_int(output_ascii, ascii6);

	char7 = read_character(infile);
	ascii7 = determine_ascii_value(char7);
	line_count = number_lines(char7, line_count);
	vowel_count = number_vowels(char7, vowel_count);
	digit_count = number_digits(char7, digit_count);
	alpha_count = number_alphas(char7, alpha_count);
	lower_case_count = number_lowers(char7, lower_case_count);
	upper_case_count = number_uppers(char7, upper_case_count);
	space_count = number_spaces(char7, space_count);
	alnum_count = number_alnums(char7, alnum_count);
	puncts_count = number_puncts(char7, puncts_count);
	print_int(output_ascii, ascii7);

	char8 = read_character(infile);
	ascii8 = determine_ascii_value(char8);
	line_count = number_lines(char8, line_count);
	vowel_count = number_vowels(char8, vowel_count);
	digit_count = number_digits(char8, digit_count);
	alpha_count = number_alphas(char8, alpha_count);
	lower_case_count = number_lowers(char8, lower_case_count);
	upper_case_count = number_uppers(char8, upper_case_count);
	space_count = number_spaces(char8, space_count);
	alnum_count = number_alnums(char8, alnum_count);
	puncts_count = number_puncts(char8, puncts_count);
	print_int(output_ascii, ascii8);

	char9 = read_character(infile);
	ascii9 = determine_ascii_value(char9);
	line_count = number_lines(char9, line_count);
	vowel_count = number_vowels(char9, vowel_count);
	digit_count = number_digits(char9, digit_count);
	alpha_count = number_alphas(char9, alpha_count);
	lower_case_count = number_lowers(char9, lower_case_count);
	upper_case_count = number_uppers(char9, upper_case_count);
	space_count = number_spaces(char9, space_count);
	alnum_count = number_alnums(char9, alnum_count);
	puncts_count = number_puncts(char9, puncts_count);
	print_int(output_ascii, ascii9);

	char10 = read_character(infile);
	ascii10 = determine_ascii_value(char10);
	line_count = number_lines(char10, line_count);
	vowel_count = number_vowels(char10, vowel_count);
	digit_count = number_digits(char10, digit_count);
	alpha_count = number_alphas(char10, alpha_count);
	lower_case_count = number_lowers(char10, lower_case_count);
	upper_case_count = number_uppers(char10, upper_case_count);
	space_count = number_spaces(char10, space_count);
	alnum_count = number_alnums(char10, alnum_count);
	puncts_count = number_puncts(char10, puncts_count);
	print_int(output_ascii, ascii10);


	output_stats = open_output_stats();
	print_stats(output_stats, "Number of Lines", line_count);
	print_stats(output_stats, "Number of Vowels", vowel_count);
	print_stats(output_stats, "Number of Digits", digit_count);
	print_stats(output_stats, "Number of Alpha", alpha_count);
	print_stats(output_stats, "Number of Lower Case", lower_case_count);
	print_stats(output_stats, "Number of Upper Case", upper_case_count);
	print_stats(output_stats, "Number of Spaces", space_count);
	print_stats(output_stats, "Number of Alnum", alnum_count);
	print_stats(output_stats, "Number of Punctuation", puncts_count);

	fclose(infile);
	fclose(output_stats);
	fclose(output_ascii);
}




