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

void welcome_screen(void);
int addition_rec(int a, int b);
int subtraction_rec(int a, int b);
int multiply_rec(int a, int b);
int division_rec(int a, int b);
//int multiply_rec(int m, int n);



#endif
