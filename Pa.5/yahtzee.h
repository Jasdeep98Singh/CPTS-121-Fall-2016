/*********************************************************************************************
Name:				Jasdeep Singh
Collaborator:       Edgar Perez
Professor:          Andrew O'Fallon
T.A:                Sam Chen
Class:              Computer 121
Assignment:         P.A #5
Date:               October 12, 2016
Description:        Develop and implement an interactive two-player Yahtzee game.
Yahtzee is a dice game that was invented by Milton Bradley and Edwin S. Lowe in 1956.
The challenge of the game is to outduel the other player by scoring the most points.
Points are obtained by rolling five 6-sided die across thirteen rounds.
During each round, each player may roll the dice up to three times to make one of the possible
scoring combinations. Once a combination has been achieved by the player, it may not be used again
in future rounds, except for the Yahtzee combination may be used as many times
as the player makes the combination. Each scoring combination has different point totals.
Some of these totals are achieved through the accumulation of points across rolls and some
are obtained as fixed sequences of values.
***********************************************************************************************/

#ifndef Yahtzee_H
#define Yahtzee_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


#define TRUE 1
#define FALSE 0

#define GAME_RULES 1
#define START_GAME 2
#define EXIT_GAME 3

#define NUMBER_OF_DICE 5

/*Categories*/
#define ONES 1
#define TWOS 2
#define THREES 3
#define FOURS 4
#define FIVES 5
#define SIXES 6
#define TWO_OF_A_KIND 14
#define THREE_OF_A_KIND 7
#define FOUR_OF_A_KIND 8
#define FULL_HOUSE 9 
#define SMALL_STRAIGHT 10
#define LARGE_STRAIGHT 11
#define YAHTZEE 12
#define CHANCE 13
#define NUMBER_OF_CATEGORIES 13

void game_menu(void);             // This function shows the user a game menu display.
void printGameRules(void);        // This function displays the user the set of rules need to know how to play Yahtzee.
void start_game(void);            // This function is the main to start the game of Yahtzee, it calls on all the functions in order to play.
int roll_die(int dice[]);          // This function will randomlly generate the die to give the user random numbers.
void computeCategoryScore(int dice[], int size, int category, int *score);  // This function computes the scores and puts the into cateories for the user.
int two_of_a_kind(int dice[]);    // This function checks for dice that are two of the same kind.
int three_of_a_kind(int dice[]);  // This function checks the dice to see if three of the dice are the same. 
int four_of_a_kind(int dice[]);   // This function checks the dice to see if four of the dice are the same.
int small_straight(int dice[]);   // This function checks the 6 dices to see if you have a small straight.
int large_straight(int dice[]);     // This function checks the 6 dices to see if you have a large straight.
int full_house(int dice[]);
int yahtzee(int dice[]);          // This function checks to see if the player has a Yahtzee.

#endif
