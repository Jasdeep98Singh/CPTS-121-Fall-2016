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
/*
Function: FILE
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function opens a .dat file.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None 
*/
FILE * open_input_file(void) {                     // This function opens a .dat file.
	FILE *infile = NULL;
	infile = fopen("input.dat", "r");
	return infile;
}

FILE * open_output_stats(void) {                     // This function opens a .dat file.
	FILE *output_stats = NULL;
	output_stats = fopen("output_stats.dat", "w");
	return output_stats;
}

FILE * open_output_ascii(void) {                     // This function opens a .dat file.
	FILE *output_ascii = NULL;
	output_ascii = fopen("output_ascii.dat", "w");
	return output_ascii;
}

void file_check(FILE *ONE, FILE *TWO, FILE *THREE) {
	if ((ONE == NULL) || (TWO == NULL) || (THREE == NULL)) {
		printf ("WARNING!");
	}
}

/*
Function: read_character
Date Created: 9/20/16
Date Modified: 9/20/16
Description: Reads the file and scans the characters within the file.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
char read_character(FILE *infile) {                 // Reads the file and scans the characters within the file.
	char input = '\0';
	fscanf(infile, "%c", &input);
	return input;
}

/*
Function: determine_ascii_value
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function is used to determine the ascii values within the file.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int determine_ascii_value(char character) {    // This function is used to determine the ascii values within the file.
	int ascii_value = 0;
	ascii_value = character;
	return ascii_value;
}

/*
Function: is_line 
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function scans the file and counts the number of lines used in the text.
             If the text differs from the if statement then the porgram will refer to the else statement.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int is_line(char character) {    // This function scans the file and counts the number of lines used in the text.
	int line = 0;
	if (character == '\n') {
		line = NEWLINE;
	}
	else{                    // If the text differs from the if statement then the porgram will refer to the else statement.
		line = NOT_NEWLINE;
	}
	return line;
}

/*
Function: number_lines
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function calculates how many lines are present.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int number_lines(char character, int current_number_lines) { // This function calculates how many lines are present.
	if (is_line(character) == NEWLINE) {
		++current_number_lines;
	}
	return current_number_lines;
}

/*
Function: is_vowel
Date Created: 9/20/16
Date Modified: 9/20/16
Description: function sees how many vowels a tect contains, both upper and lower case.
             Else statement to help guide function if if it cannot find  vowel.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int is_vowel(char character) { // function sees how many vowels a tect contains, both upper and lower case.
	int vowel = 0;
	if (((character == 'a') || (character == 'A')) 
	|| ((character == 'e') || (character == 'E'))
    || ((character == 'i') || (character == 'I'))
    || ((character == 'o') || (character == 'O'))
    || ((character == 'u') || (character == 'U')))
	{
		vowel = VOWEL;
	}
	else {                     // Else statement to help guide function if if it cannot find  vowel.
		vowel = NOT_VOWEL;
	}
	return vowel;
}

/*
Function: number_vowels
Date Created: 9/20/16
Date Modified: 9/20/16
Description: Function calculates the number of vowels present in the text
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int number_vowels(char character, int current_number_vowels) {    
	if (is_vowel(character) == VOWEL) {            // Function calculates the number of vowels present in the text. 
		++current_number_vowels;
	}
	return current_number_vowels;
}

/*
Function: is_digit
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function calculates how many digits there are in a text from 0-9.
             Else statement tells the function what to do if the text does not have any numbers.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int is_digit(char character) {     // This function calculates how many digits there are in a text from 0-9. 
	int digit = 0;
	if ((character >= '0') && (character <= '9')) {
		digit = DIGIT;
	}
	else {                      // Else statement tells the function what to do if the text does not have any numbers. 
		digit = NOT_DIGIT;
	}
	return digit;
}

/*
Function: number_digits
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function tells the program to calculate how many digits a text conatins. 
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int number_digits(char character, int current_number_digits) {
	if (is_digit(character) == DIGIT) {   // This function tells the program to calculate how many digits a text conatins. 
		++current_number_digits;
	}
	return current_number_digits;
}

/*
Function: is_alpha
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function tells how many letters a text contains from upper case to lower case.
             Else statement tells the function what to do in case of non letters.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int is_alpha(char character) {     // This function tells how many letters a text contains from upper case to lower case. 
	int result = 0;
	if (((character >= 'a') && (character <= 'z')) ||
		((character >= 'A') && (character <= 'Z'))) {
		result = ALPHA;
	}
	else {              // Else statement tells the function what to do in case of non letters.
		result = NOT_ALPHA;
	}
	return result;
}

/*
Function: number_alphas 
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function tells how many letters a text conatins
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int number_alphas(char character, int current_number_alphas) { // This function tells how many letters a text conatins.
	if (is_alpha(character) == ALPHA) {
		++current_number_alphas;
	}
	return current_number_alphas;
}

/*
Function: is_lower
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function calculates how any lower case letter  a text contains.
             Else statement tells program what to do when faced with a non lower case letter.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int is_lower(char character) {  // This function calculates how any lower case letter  a text contains. 
	int lower = 0;
	if ((character >= 'a') && (character <= 'z')) {
		lower = LOWER;
	}
	else {           // Else statement tells program what to do when faced with a non lower case letter. 
		lower = NOT_LOWER;
	}
	return lower;
}

/*
Function: number_lowers
Date Created: 9/20/16
Date Modified: 9/20/16
Description: Functions tells program how any lower case letters were in the file.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int number_lowers(char character, int current_number_lowers) {  // Functions tells program how any lower case letters were in the file.
	if (is_lower(character) == LOWER) {
		++current_number_lowers;
	}
	return current_number_lowers;
}

/*
Function: is_upper
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function calculates how many upper case letters a text in the file contains.
             Else statement tells the progra what to do if the character is not upper case.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int is_upper(char character) {   // This function calculates how many upper case letters a text in the file contains.
	int upper = 0;
	if ((character >= 'A') && (character <= 'Z')) {
		upper = UPPER;
	}
	else {              // Else statement tells the progra what to do if the character is not upper case. 
		upper = NOT_UPPER;
	}
	return upper;
}

/*
Function: number_uppers
Date Created: 9/20/16
Date Modified: 9/20/16
Description: The function calculates the total number of upper case letters. 
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int number_uppers(char character, int current_number_uppers) { // The function calculates the total number of upper case letters. 
	if (is_upper(character) == UPPER) {
		++current_number_uppers;
	}
	return current_number_uppers;
}

/*
Function: is_space 
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function calculates how many spaces a text in the file contains. 
              Else statement shows the program what to do it it comes arcoss a character with no space.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int is_space(char character) { // This function calculates how many spaces a text in the file contains. 
	int space = 0;
	
	if ((character == ' ' || (character = '\f') || (character = '\n') ||
		(character = '\r') || (character = '\t') || (character = '\v'))) {
		space = WHITESPACE;
	}
	else {     // Else statement shows the program what to do it it comes arcoss a character with no space. 
		space = NOT_WHITESPACE;
	}
	return space;
}

/*
Function: number_spaces
Date Created: 9/20/16
Date Modified: 9/20/16
Description: Function calculates the total number of spaces.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int number_spaces(char character, int current_number_spaces) { // Function calculates the total number of spaces. 
	if (is_space(character) == WHITESPACE) {
		++current_number_spaces;
	}
	return current_number_spaces;
}

/*
Function: is_alnum
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function calculates how many letters and numbers were used in the file.
              Else statement tells the program what to do when it comes across a non-almun character.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int is_alnum(char character) { // This function calculates how many letters and numbers were used in the file. 
	int alnum = 0;

	if (((character >= 'a') && (character <= 'z')) ||
		((character >= 'A') && (character <= 'Z')) ||
		((character >= '0') && (character <= '9'))) {
		 alnum = ALNUM;
	} 
	else {     // Else statement tells the program what to do when it comes across a non-almun character.
		alnum = NOT_ALNUM;
	}
	return alnum;
}

/*
Function: number_alnums 
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function calculates the total number of alnums in a file.
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int number_alnums(char character, int current_number_alnums) { // This function calculates the total number of alnums in a file.
	if (is_alnum(character) == ALNUM) {
		++current_number_alnums;
	}
	return current_number_alnums;
}

/*
Function: is_punct
Date Created: 9/20/16
Date Modified: 9/20/16
Description: This function can compute the number of punctuations in a text from a file. 
             The else statement shows what characters are punctations and what are not. 
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
int is_punct(char character) {
	int punct = 0;

	if (((character >= '!') && (character <= '/'))) {
		punct = PUNCT;
	}
	else {     // Else statement tells the program what to do when it comes across a non-punctuation character.
		punct = NOT_PUNCT;
	}
	return punct;
}

int number_puncts(char character, int current_number_puncts) {
	if (is_punct(character) == PUNCT) {      // Program calculates the total number of punctation in a text in a file.  
		++current_number_puncts;
	}
	return current_number_puncts;
}

/*
Function: void
Date Created: 9/20/16
Date Modified: 9/20/16
Description: 
Input Parameter: None
Returns: None
Preconditions: None
Post Conditions: None
*/
void print_int(FILE *outfile, int number) {
	fprintf(outfile, "%d\n", number);
}

void print_stats(FILE *outfile, char header[], int number) {
	fprintf(outfile, "number of %s: %d\n", header, number);
}