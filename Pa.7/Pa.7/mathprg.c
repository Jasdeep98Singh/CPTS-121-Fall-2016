/***************************************************************************************************************
*Name:				 Jasdeep Singh                                                                             *
*Collaborator:       Edgar Perez                                                                               *
*Professor:          Andrew O'Fallon                                                                           *
*T.A:                Sam Chen                                                                                  *
*Class:              Computer 121                                                                              *
*Assignment:         P.A #7                                                                                    *
*Date:               November 9, 2016                                                                          *
*Description:       Mathematics is one of the most important, yet most difficult, subjects to teach and learn. *
*					We have all heard of the saying "Practice makes perfect".	                               *
*					Well I'm a huge believer in this saying and would like a software program which can        *
*					generate various arithmetic problems and evaluate answers supplied by the user.            *
*					For this assignment you will need to design and construct a basic math program             *
*					which targets elementary school children.                                                  *
***************************************************************************************************************/

#include "mathprg.h"

/*********************************************************
*Function: Welcome_screen();                             *
*Date Created : 11 / 10 / 16                             *
*Date Modified : 11 / 10 / 16                            *
*Description : This function prints a menu for the user  *
*Input Parameter :   None                                *
*Returns :           None                                *
*Preconditions :     None                                *
*Post Conditions :   None                                *
*********************************************************/

void welcome_screen(void) {
	printf("                           WELCOME To The Math Learning Program!!!                     \n");
	printf("RULES OF THE PROGRAM:                                                                  \n");
	printf("1. This is a program that will help you improve your math skills.                      \n");
	printf("2. To start this program you must choose a math level from 1-5.                        \n");
	printf("   lvl 1: Addition + Subtraction                                                       \n");
	printf("   lvl 2: Multiplication                                                               \n");
	printf("   lvl 3: Division                                                                     \n");
	printf("   lvl 4: Mixtures of problems that include elements from levels 1-2                   \n");
	printf("   lvl 5: Mixtures of problems that include elements from levels 1-3                   \n");
	printf("3. Once you choose a level select how any problems you wish to do.                     \n");
	printf("4. If you passed the level go back to the menu and go onto another level.              \n");
	printf("5. The objective is to finish all the levels.                                          \n\n");
}


/*********************************************************************
*Function: Multiply_rec();                                           *
*Date Created : 11 / 10 / 16                                         *
*Date Modified : 11 / 10 / 16                                        *
*Description : This function is the lvl2 in program(Multiplication)  *
*Input Parameter :   None                                            *
*Returns :           None                                            *
*Preconditions :     None                                            *
*Post Conditions :   None                                            *
*********************************************************************/

int multiply_rec(int a, int b) {
	// int i = 0, a = 0, b = 0;

	int i;
	int response;
	int correctAnswers = 0; //right
	int incorrectAnswers = 0; //wrong

	printf("\Welcome to Level 3 (Fair)\n");
	printf("Please enter # of problems you would wish to try:");
	scanf("%d", &response);

	if (response == 0)
	{
		printf("\nThanks for playing!\n");
		return 0;
	}

	for (i = 0; i < response; i++)
	{
		int answer = 0;
		int a = rand() % 12;
		int b = rand() % 12;
		printf("\n%d * %d = ", a, b);
		scanf("%d", &answer);
		if ((a * b) == answer) {
			printf("\nLucky Faggot!\n");//Congratulations You are correct!
			correctAnswers++;
		}
		else {
			printf("Dumbass Bitch!\n"); //Sorry you were incorrect!
			incorrectAnswers++;
		}

	}
	printf("\n\nYour Results:\n\n\n");
	printf("Number Incorrect: %d\n", incorrectAnswers);
	printf("Number Correct: %d\n", correctAnswers);
	if (correctAnswers > incorrectAnswers) {
		printf("You Passed!\nGood work!\n\n");
	}
	else {
		printf("You did not pass!\nYou need more work!\n\n");
	}
}

/****************************************************************
*Function: addition_rec();                                      *
*Date Created : 11 / 10 / 16                                    *
*Date Modified : 11 / 10 / 16                                   *
*Description : This function is the lvl1 in program(Addition)   *
*Input Parameter :   None                                       *
*Returns :           None                                       *
*Preconditions :     None                                       *
*Post Conditions :   None                                       *
****************************************************************/

int addition_rec(int a, int b) {
	// int i = 0, a = 0, b = 0;

	int i;
	int response;
	int correctAnswers = 0; //right
	int incorrectAnswers = 0; //wrong

	printf("\Welcome to Level 1 (Easy)\n");
	printf("Please enter # of problems you would wish to try:");
	scanf("%d", &response);

	if (response == 0)
	{
		printf("\nThanks for playing!\n");
		return 0;
	}

	for (i = 0; i < response; i++)
	{
		int answer = 0;
		int a = rand() % 12;
		int b = rand() % 12;
		printf("\n%d + %d = ", a, b);
		scanf("%d", &answer);
		if ((a + b) == answer) {
			printf("\nLucky Faggot!\n");//Congratulations You are correct!
			correctAnswers++;
		}
		else {
			printf("Dumbass Bitch!\n"); //Sorry you were incorrect!
			incorrectAnswers++;
		}

	}
	printf("\n\nYour Results:\n\n\n");
	printf("Number Incorrect: %d\n", incorrectAnswers);
	printf("Number Correct: %d\n", correctAnswers);
	if (correctAnswers > incorrectAnswers) {
		printf("You Passed!\nGood work!\n\n");
	}
	else {
		printf("You did not pass!\nYou need more work!\n\n");
	}
}

/*****************************************************************
*Function: subtraction_rec();                                    *
*Date Created : 11 / 10 / 16                                     * 
*Date Modified : 11 / 10 / 16                                    *
*Description : This function is the lvl1 in program(Subtraction) *
*Input Parameter :   None                                        *
*Returns :           None                                        *
*Preconditions :     None                                        *
*Post Conditions :   None                                        *
*****************************************************************/

int subtraction_rec(int a, int b) {
	// int i = 0, a = 0, b = 0;

	int i;
	int response;
	int correctAnswers = 0; //right
	int incorrectAnswers = 0; //wrong

	printf("\Welcome to Level 2 (Easy)\n");
	printf("Please enter # of problems you would wish to try:");
	scanf("%d", &response);

	if (response == 0)
	{
		printf("\nThanks for playing!\n");
		return 0;
	}

	for (i = 0; i < response; i++)
	{
		int answer = 0;
		int a = rand() % 12;
		int b = rand() % 12;
		printf("\n%d - %d = ", a, b);
		scanf("%d", &answer);
		if ((a - b) == answer) {
			printf("\nLucky Faggot!\n");//Congratulations You are correct!
			correctAnswers++;
		}
		else {
			printf("Dumbass Bitch!\n"); //Sorry you were incorrect!
			incorrectAnswers++;
		}

	}
	printf("\n\nYour Results:\n\n\n");
	printf("Number Incorrect: %d\n", incorrectAnswers);
	printf("Number Correct: %d\n", correctAnswers);
	if (correctAnswers > incorrectAnswers) {
		printf("You Passed!\nGood work!\n\n");
	}
	else {
		printf("You did not pass!\nYou need more work!\n\n");
	}
}

/*****************************************************************
*Function: division_rec();                                       *
*Date Created : 11 / 10 / 16                                     *
*Date Modified : 11 / 10 / 16                                    *
*Description : This function is the lvl3 in program(Division)    *
*Input Parameter :   None                                        *
*Returns :           None                                        *
*Preconditions :     None                                        *
*Post Conditions :   None                                        *
*****************************************************************/

int division_rec(int a, int b) {
	// int i = 0, a = 0, b = 0;

	int i;
	int response;
	int correctAnswers = 0; //right
	int incorrectAnswers = 0; //wrong

	printf("\Welcome to Level 4 (Intermediate)\n");
	printf("Please enter # of problems you would wish to try:");
	scanf("%d", &response);

	if (response == 0)
	{
		printf("\nThanks for playing!\n");
		return 0;
	}

	for (i = 0; i < response; i++)
	{
		int answer = 0;
		int a = rand() % 12;
		int b = rand() % 12;
		printf("\n%d / %d = ", a, b);
		scanf("%d", &answer);
		if ((a / b) == answer) {
			printf("\nLucky Faggot!\n");//Congratulations You are correct!
			correctAnswers++;
		}
		else {
			printf("Dumbass Bitch!\n"); //Sorry you were incorrect!
			incorrectAnswers++;
		}

	}
	printf("\n\nYour Results:\n\n\n");
	printf("Number Incorrect: %d\n", incorrectAnswers);
	printf("Number Correct: %d\n", correctAnswers);
	if (correctAnswers > incorrectAnswers) {
		printf("You Passed!\nGood work!\n\n");
	}
	else {
		printf("You did not pass!\nYou need more work!\n\n");
	}
}

/*****************************************************************
*Function:                                        *
*Date Created : 11 / 10 / 16                                     *
*Date Modified : 11 / 10 / 16                                    *
*Description :   *
*Input Parameter :   None                                        *
*Returns :           None                                        *
*Preconditions :     None                                        *
*Post Conditions :   None                                        *
*****************************************************************/



//int multiply_rec(int m, int n)
//{
//	// this is a recursive function!
//	int result = 0;
//	
//	if (n == 0) // simple case 1
//	{
//		result = 0;
//	}
//	else if (n == 1) // simple case 2
//	{
//		result = m;
//	}
//	else // recursive step
//	{
//		result = m + multiply_rec(m, n - 1); // need to change n
//	}
//	return result;
//}

