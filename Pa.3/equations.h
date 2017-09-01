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

#define EQUATION_H_

#include <stdio.h>
#include <math.h> 

#define  NEWLINE 1
#define  NOT_NEWLINE 0
#define  VOWEL 2 
#define  NOT_VOWEL 0
#define  DIGIT 3 
#define  NOT_DIGIT 0
#define  ALPHA 4
#define  NOT_ALPHA 0
#define  LOWER 5
#define  NOT_LOWER 0
#define  UPPER 6
#define  NOT_UPPER 0
#define  WHITESPACE 7
#define  NOT_WHITESPACE 0
#define  ALNUM 8
#define  NOT_ALNUM 0
#define  PUNCT 9
#define  NOT_PUNCT 0 

FILE * open_input_file(void); //Opens "input.dat" for reading.
FILE *open_output_stats(void);
FILE *open_output_ascii(void);
char read_character(FILE *infile); // // Reads one character from the input file.
int determine_ascii_value(char character); //Returns the ASCII value of the character passed into the function.
int is_line(char character); // Determines if the character is a newline, if the character
                             //is a newline a 1 is returned otherwise a 0 is returned. Make sure that you #define two constants 
                            //NEWLINE and NOT_NEWLINE as 1 and 0, respectively.Return the #defined constant.
int number_lines(char character, int current_number_lines); // Determines if the character passed into the function indicates the end of a line  
                                                            //(use is_line ( )), if so the function adds 1 to the current_number_lines and returns the value; 
                                                           //otherwise it returns the current_number_lines without any modification.
int is_vowel(char character); // Determines if the character is a vowel (note: the character may be lower or upper case), 
                             //if the character is a vowel a 2 is returned otherwise a 0 is returned. 
int number_vowels(char character, int current_number_vowels); // Determines if the character passed into the function is a vowel (use is_vowel ( )),
                                                             // if so the function adds 1 to the current_number_vowels and returns the value; 
                                                             //otherwise it returns the current_number_vowels without any modification.
int is_digit(char character); // Determines if the character is a digit (i.e. '0' - '9'), if the character is a digit 
                             //a 3 is returned otherwise a 0 is returned. Make sure that you #define two constants DIGIT and NOT_DIGIT as 3 and 0, 
                             //respectively.Return the #defined constant.
int number_digits(char character, int current_number_digits); // Determines if the character passed into the function is a digit (use is_digit ( )),
                                                             // if so the function adds 1 to the current_number_digits and returns the value; 
                                                            // otherwise it returns the current_number_digits without any modification.
int is_alpha(char character); // Determines if the character is an alpha character (i.e. 'a' - 'z', 'A' - 'Z'), 
                              // if the character is an alpha character a 4 is returned otherwise a 0 is returned. 
int number_alphas(char character, int current_number_alphas); // Determines if the character passed into the function is an alpha character (use is_alpha ( )),
                                                              // if so the function adds 1 to the current_number_alphas and returns the value; 
                                                              // otherwise it returns the current_number_alphas without any modification.
int is_lower(char character); //  Determines if the character is a lowercase character, 
                             //if the character is a lowercase character a 5 is returned otherwise a 0 is returned.
                             // Make sure that you #define two constants LOWER and NOT_LOWER as 5 and 0, respectively.Return the #defined constant.
int number_lowers(char character, int current_number_lowers); //  Determines if the character passed into the function is a lowercase character (use is_lower ( )),
                                                              // if so the function adds 1 to the current_number_lowers and returns the value; 
                                                              // otherwise it returns the current_number_lowers without any modification.
int is_upper(char character); // Determines if the character is an uppercase character, if the character is an uppercase character 
                              // a 6 is returned otherwise a 0 is returned. Make sure that you #define two constants UPPER and
                             //NOT_UPPER as 6 and 0, respectively.Return the #defined constant.
int number_uppers(char character, int current_number_uppers); // Determines if the character passed into the function is a uppercase character (use is_upper ( )),
                                                              // if so the function adds 1 to the current_number_uppers and returns the value; 
                                                              // otherwise it returns the current_number_uppers without any modification.
int is_space(char character); //  Determines if the character is a whitespace character (i.e. space ' ', form feed '\f', new-line '\n', 
                             //carriage return '\r', horizontal tab '\t', and vertical tab '\v'), if the character is a whitespace character a 7 is returned 
                             //otherwise a 0 is returned.Make sure that you #define two constants WHITESPACE and NOT_WHITESPACE as 7 and 0, respectively.
int number_spaces(char character, int current_number_spaces); // Determines if the character passed into the function is a space character (use is_space ( )),
                                                              // if so the function adds 1 to the current_number_spaces and returns the value; 
                                                             // otherwise it returns the current_number_spaces without any modification.
int is_alnum(char character); // Determines if the character is an alpha or digit character, if the character is an alpha 
                             // or digit character a 8 is returned otherwise a 0 is returned.
                            // Make sure that you #define two constants ALNUM and NOT_ALNUM as 8 and 0, respectively.
                            //Return the #defined constant.
int number_alnums(char character, int current_number_alnums); // Determines if the character passed into the function is an alphanumeric character (use is_alnum ( )),
                                                             // if so the function adds 1 to the current_number_alnums and returns the value; 
                                                            //otherwise it returns the current_number_alnums without any modification.
int is_punct(char character); // Determines if the character is a punctuation character (i.e. '.', '!', ',', etc.) 
                              // if the character is a punctuation character an 9 is returned otherwise a 0 is returned. 
int number_puncts(char character, int current_number_puncts); //  Determines if the character passed into the function is a punctuation character (use is_punct ( )),
                                                              //if so the function adds 1 to the current_number_puncts and returns the value; 
                                                             //otherwise it returns the current_number_puncts without any modification.
void print_int(FILE *outfile, int number); //  Prints an integer to an output file.
void print_stats(FILE *outfile, char header[], int number); // Prints a line showing how many vowels it contains.

