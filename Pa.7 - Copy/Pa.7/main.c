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

int main(void) {

	struct stat problems[5] = { 0 };
	srand((unsigned int)time(NULL));      // Randomizer 
	
	int option = 0, a = 0, b = 0, c = 0, d = 0;

	do {
		printf("Press 1. To Learn How The Program Works.\n"
			   "Press 2. Level One (Addition + Subtraction).\n"
			   "Press 3. Level Two (Multiplication).\n"
			   "Press 4. Level Three (Division).\n"
			   "Press 5. Level Four (Hard).\n"
			   "Press 6. Level Five (Impossible).\n"
			   "Press 7. To Save and Quit\n");
		scanf("%d", &option);
		while (option < 1 || option > 7) {
			printf("Press 1. To Learn How The Program Works.\n"
				   "Press 2. Level One (Addition + Subtraction).\n"
				   "Press 3. Level Two (Multiplication).\n"
				   "Press 4. Level Three (Division).\n"
				   "Press 5. Level Four (Hard).\n"
				   "Press 6. Level Five (Impossible).\n"
				   "Press 7. To Save and Quit\n");
			scanf("%d", &option);
		}
		switch (option) {				// Switch statement allows each function to a case.
		case 1:
			welcome_screen();
			break;
		case 2:
			addition_rec(a, b, problems);
			subtraction_rec(a, b, problems);
			threeaddition_rec(a, b, c, problems);
			break;
		case 3:
			multiply_rec(a, b, problems);
			break;
		case 4:
			division_rec(a, b, problems);
			break;
		case 5:
			levelfour_rec(a, b, c, d, problems);
			break;
		case 6:
			levelfive_rec(a, b, c, d, problems);
			break;
		case 7:
			file_input(problems);
			exit(0);
			break;
		}
	} while (option > 0 && option < 8);				// Stops user from entering a number lower than 0 or greater than 7.

	return 0;
}
