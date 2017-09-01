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

#ifndef mathprg_H
#define mathprg_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

struct stat {
	int numCorrect;
	int numWrong;
};

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

void welcome_screen(void);

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

int addition_rec(int a, int b, struct stat *problems);

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

int subtraction_rec(int a, int b, struct stat *problems);

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

int threeaddition_rec(int a, int b, int c, struct stat *problems);

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

int multiply_rec(int a, int b, struct stat *problems);

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

int division_rec(int a, int b, struct stat *problems);

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

int levelfour_rec(int a, int b, int c, int d, struct stat *problems);

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

int levelfive_rec(int a, int b, int c, int d, struct stat *problems);

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

void file_input(struct stat *problems);

#endif
