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
	printf("                           WELCOME To The Math Learning Program!!!                    \n");
	printf("RULES OF THE PROGRAM:                                                                 \n");
	printf("1. This is a program that will help you improve your math skills.                     \n");
	printf("2. To start this program you must choose a math level from 1-5.                       \n");
	printf("   lvl 1:   Addition (Easy Part 1)                                                    \n");
	printf("   lvl 1.2: Subtraction (Easy Part 2)                                                 \n");
	printf("   lvl 1.3: Addition + Subtraction (Easy Part 3)                                      \n");
	printf("   lvl 2:   Multiplication (Fair)                                                     \n");
	printf("   lvl 3:   Division (Intermediate)                                                   \n");
	printf("   lvl 4:   Mixtures of problems that include elements from levels 1-3 (Hard)         \n");
	printf("   lvl 5:   Mixtures of problems that includes elements from levels 1-3 (Impossible)  \n");
	printf("3. Once you choose a level select how any problems you wish to do.                    \n");
	printf("4. If you passed the level go back to the menu and go onto another level.             \n");
	printf("5. The objective is to finish all the levels.                                         \n\n");
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

int addition_rec(int a, int b, struct stat *problems) {
	// int i = 0, a = 0, b = 0;

	int i;
	int response;
	int correctAnswers = 0; //right
	int incorrectAnswers = 0; //wrong

	printf("\Welcome to Level 1.1 (Easy Part 1)\n");
	printf("Please enter # of problems you would wish to try:");
	scanf("%d", &response);

	if (response == 0)
	{
		printf("\nThanks for playing!\n");
		return 0;
	}
	do {
		for (i = 0; i < response; i++)
		{
			int answer = 0;
			int a = rand() % 10;   // randomizes variable a 
			int b = rand() % 10;   // randomizes variable b
			printf("\n%d + %d = ", a, b);
			scanf("%d", &answer);
			if ((a + b) == answer) {
				printf("\nCongratulations You are correct!\n");//Congratulations You are correct!
				correctAnswers++;
				problems[0].numCorrect++;
			}
			else {
				printf("Sorry you were incorrect!\n"); //Sorry you were incorrect!
				incorrectAnswers++;
				problems[0].numWrong++;
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
		while (correctAnswers < incorrectAnswers);
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

int subtraction_rec(int a, int b, struct stat *problems) {
	// int i = 0, a = 0, b = 0;

	int i;
	int response;
	int correctAnswers = 0; //right
	int incorrectAnswers = 0; //wrong

	printf("\Welcome to Level 1.2 (Easy Part 2)\n");
	printf("Please enter # of problems you would wish to try:");
	scanf("%d", &response);

	if (response == 0)
	{
		printf("\nThanks for playing!\n");
		return 0;
	}
	do {
		for (i = 0; i < response; i++)
		{
			int answer = 0;
			int a = rand() % 10;   // randomizes variable a 
			int b = rand() % 3;   // randomizes variable b
			printf("\n%d - %d = ", a, b);
			scanf("%d", &answer);
			if ((a - b) == answer) {
				printf("\nCongratulations You are correct!!\n");//Congratulations You are correct!
				correctAnswers++;
				problems[0].numCorrect++;
			}
			else {
				printf("Sorry you were incorrect!\n"); //Sorry you were incorrect!
				incorrectAnswers++;
				problems[0].numWrong++;
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
		while (correctAnswers < incorrectAnswers);
}

/****************************************************************
*Function: threeaddition_rec();                                 *
*Date Created : 11 / 10 / 16                                    *
*Date Modified : 11 / 10 / 16                                   *
*Description : This function is the lvl1 in program and         *
*              is a mixture of addition and subtraction         *
*Input Parameter :   None                                       *
*Returns :           None                                       *
*Preconditions :     None                                       *
*Post Conditions :   None                                       *
****************************************************************/

int threeaddition_rec(int a, int b, int c, struct stat *problems) {
	// int i = 0, a = 0, b = 0;

	int i;
	int response;
	int correctAnswers = 0; //right
	int incorrectAnswers = 0; //wrong

	printf("\Welcome to Level 1.3 (Easy Part 3)\n");
	printf("Please enter # of problems you would wish to try:");
	scanf("%d", &response);

	if (response == 0)
	{
		printf("\nThanks for playing!\n");
		return 0;
	}
	do {
		for (i = 0; i < response; i++)
		{
			int answer = 0;
			int a = rand() % 10;   // randomizes variable a 
			int b = rand() % 10;   // randomizes variable b
			int c = rand() % 3;    // randomizes variable c
			printf("\n%d + %d - %d = ", a, b, c);
			scanf("%d", &answer);
			if ((a + b - c) == answer) {
				printf("\nCongratulations You are correct!!\n");//Congratulations You are correct!
				correctAnswers++;
				problems[0].numCorrect++;
			}
			else {
				printf("Sorry you were incorrect!\n");
				incorrectAnswers++;
				problems[0].numWrong++;
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
	while (correctAnswers < incorrectAnswers);
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

int multiply_rec(int a, int b, struct stat *problems) {
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
	do {
		for (i = 0; i < response; i++)
		{
			int answer = 0;
			int a = rand() % 10;   // randomizes variable a 
			int b = rand() % 10;   // randomizes variable b
			printf("\n%d * %d = ", a, b);
			scanf("%d", &answer);
			if ((a * b) == answer) {
				printf("\nCongratulations You are correct!!\n");//Congratulations You are correct!
				correctAnswers++;
				problems[1].numCorrect++;
			}
			else {
				printf("Sorry you were incorrect!\n"); //Sorry you were incorrect!
				incorrectAnswers++;
				problems[1].numWrong++;
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
	} while (correctAnswers < incorrectAnswers);
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

int division_rec(int a, int b, struct stat *problems) {
	// int i = 0, a = 0, b = 0;

	int i;
	int response;
	int correctAnswers = 0; //right
	int incorrectAnswers = 0; //wrong

	printf("\Welcome to Level 3 (Intermediate)\n");
	printf("To solve these problems, the answer is NUMBER SPACE REMAINDER\n");
	printf("Example: 1/3 = 0 1 or 6/3 = 2 0\n");
	printf("Please enter # of problems you would wish to try:");
	scanf("%d", &response);

	if (response == 0)
	{
		printf("\nThanks for playing!\n");
		return 0;
	}
	do {
		for (i = 0; i < response; i++)
		{
			int remainder = 0;
			int answer = 0;
			int a = rand() % 10;   // randomizes variable a 
			int b = rand() % 3 + 1;   // randomizes variable b
			printf("\n%d / %d = ", a, b);
			scanf("%d%d", &answer, &remainder);
			//printf("Enter remainder");

			if (((a / b) == answer) && ((a % b) == remainder)) { // && a%b == remainder
				printf("\nCongratulations You are correct!!\n");//Congratulations You are correct!
				correctAnswers++;
				problems[2].numCorrect++;
			}
			else {
				printf("Sorry you were incorrect!\n"); //Sorry you were incorrect!
				incorrectAnswers++;
				problems[2].numWrong++;
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
	} while (correctAnswers < incorrectAnswers);
}

/*****************************************************************
*Function: levelfour_rec();                                      *
*Date Created : 11 / 14 / 16                                     *
*Date Modified : 11 / 14 / 16                                    *
*Description : This function is the lvl4 in program(Hard)        *
*Input Parameter :   None                                        *
*Returns :           None                                        *
*Preconditions :     None                                        *
*Post Conditions :   None                                        *
*****************************************************************/

int levelfour_rec(int a, int b, int c, int d, struct stat *problems) {
	// int i = 0, a = 0, b = 0;

	int i;
	int response;
	int correctAnswers = 0; //right
	int incorrectAnswers = 0; //wrong

	printf("\Welcome to Level 4 (Hard)\n");
	printf("Please enter # of problems you would wish to try:");
	scanf("%d", &response);

	if (response == 0)
	{
		printf("\nThanks for playing!\n");
		return 0;
	}
	do {
		for (i = 0; i < response; i++)
		{
			//int remainder = 0;
			int answer = 0;
	
			    int a = rand() % 100;    // randomizes variable a 
				int b = rand() % 100;    // randomizes variable b
				int c = rand() % 2 + 1; // randomizes variable c
			    int d = rand() % 100;    // randomizes variable d
			printf("\n%d * %d / %d + %d = ", a, b, c, d);
			scanf("%d", &answer);
			//printf("Enter remainder");

			if ((a * b / c + d) == answer) { // && a%b == remainder
				printf("\nCongratulations You are correct!!\n");//Congratulations You are correct!
				correctAnswers++;
				problems[3].numCorrect++;
			}
			else {
				printf("Sorry you were incorrect!\n"); //Sorry you were incorrect!
				incorrectAnswers++;
				problems[3].numWrong++;
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
	} while (correctAnswers < incorrectAnswers);
}

/*****************************************************************
*Function: levelfive_rec();                                      *
*Date Created : 11 / 14 / 16                                     *
*Date Modified : 11 / 14 / 16                                    *
*Description : This function is the lvl5 in program(Impossible)  *
*Input Parameter :   None                                        *
*Returns :           None                                        *
*Preconditions :     None                                        *
*Post Conditions :   None                                        *
*****************************************************************/

// dd1 + -ddd2 x ddd3 / dd4 = );
int levelfive_rec(int a, int b, int c, int d, struct stat *problems) {
	// int i = 0, a = 0, b = 0;

	int i;
	int response;
	int correctAnswers = 0; //right
	int incorrectAnswers = 0; //wrong

	printf("\Welcome to Level 5 (Impossible)\n");
	printf("Please enter # of problems you would wish to try:");
	scanf("%d", &response);

	if (response == 0)
	{
		printf("\nThanks for playing!\n");
		return 0;
	}
	do {
		for (i = 0; i < response; i++)
		{
			//int remainder = 0;
			int answer = 0;
			int a = rand() % 100;    // randomizes variable a 
			int b = rand() % 100;    // randomizes variable b
			int c = rand() % 2 + 1; // randomizes variable c
			int d = rand() % (9+1) - 10;    // randomizes variable d
			printf("\n%d * %d / %d + %d = ", a, b, c, d);		//dd1 + -ddd2 x ddd3 / dd4 = );
			scanf("%d", &answer);
			//printf("Enter remainder");

			if ((a * b / c + d) == answer) { // && a%b == remainder
				printf("\nCongratulations You are correct!!\n");//Congratulations You are correct!
				correctAnswers++;
				problems[4].numCorrect++;
			}
			else {
				printf("Sorry you were incorrect!\n"); //Sorry you were incorrect!
				incorrectAnswers++;
				problems[4].numWrong++;
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
	} while (correctAnswers < incorrectAnswers);
}

/*****************************************************************
*Function: file_input();                                         *
*Date Created : 11 / 15 / 16                                     *
*Date Modified : 11 / 15 / 16                                    *
*Description : This function creates a file into the program.    *
*Input Parameter :   None                                        *
*Returns :           None                                        *
*Preconditions :     None                                        *
*Post Conditions :   None                                        *
*****************************************************************/

void file_input(struct stat *problems) {
	FILE* infile = NULL;
	char initials[4] = { 0 };
	printf("Please enter your initials without any delimiters:\n");
	scanf(" %c%c%c",
		&initials[0], &initials[1], &initials[2]);
	char name[10] = { 0 };
	strcpy(name, initials);
	strcat(name, ".log");
	infile = fopen(name, "w");
	int totalCorrect = 0;
	int totalWrong = 0;
	for (int i = 0; i < 4; i++) {
		totalCorrect += problems[i].numCorrect;
		totalWrong += problems[i].numWrong;
	}
	fprintf(infile,
		"Level 1 Right: %d\n"
		"Level 1 Wrong: %d\n"
		"Level 2 Right: %d\n"
		"Level 2 Wrong: %d\n"
		"Level 3 Right: %d\n"
		"Level 3 Wrong: %d\n"
		"Level 4 Right: %d\n"
		"Level 4 Wrong: %d\n"
		"Level 5 Right: %d\n"
		"Level 5 Wrong: %d\n"
		"Total Correct: %d\n"
		"Total Wrong: %d\n",
		problems[0].numCorrect, problems[0].numWrong,
	    problems[1].numCorrect, problems[1].numWrong,
	    problems[2].numCorrect, problems[2].numWrong,
	    problems[3].numCorrect, problems[3].numWrong,
	    problems[4].numCorrect, problems[4].numWrong,
		totalCorrect, totalWrong);
	fclose(infile);
}


