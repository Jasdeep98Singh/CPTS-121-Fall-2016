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

	int option = 0, a = 0, b = 0;

	do {
		printf("Press 1. To Learn How The Program Works.\n"
			   "Press 2. To Use Program.\n"
			   "Press 3. To Exit\n");
		scanf("%d", &option);
		while (option < 1 || option > 3) {
			printf("Press 1. To Learn How The Program Works.\n"
				   "Press 2. To Use Program.\n"
				   "Press 3. To Exit\n");
			scanf("%d", &option);
		}
		switch (option) {
		case 1:
			welcome_screen();
			break;
		case 2:
			addition_rec(a, b);
			subtraction_rec(a, b);
		    multiply_rec(a, b);
			division_rec(a, b);
			break;
		case 3:
			exit(0);
			break;
		}
	} while (option > 0 && option < 4);

	return 0;
}
