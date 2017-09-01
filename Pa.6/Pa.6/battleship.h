/**********************************************************************************************************************************************
*Name:				Jasdeep Singh                                                                                                              *
*Collaborator:       Edgar Perez                                                                                                               *
*Professor:          Andrew O'Fallon                                                                                                           *  
*T.A:                Sam Chen                                                                                                                  *
*Class:              Computer 121                                                                                                              *
*Assignment:         P.A #5                                                                                                                    *
*Date:               October 12, 2016                                                                                                          *
*Description:        The program should be built such that the user is Player1 and the computer is Player2.                                    *
*					 Two boards exist within the game. Hint: each board should be implemented as a 2-dimensional array.                        *
*					 Each 2-dimensional array should be 10 X 10. One represents Player1's board and one represents Player2's board.            *
*					 At the beginning of the game each Players' game board should be initialized to all '-' indicating                         *
*					 that no ships have been placed on either board. Before the game starts, Player1 should have the                           *
*					 option to either manually place each of the 5 ships in his/her fleet or to have them randomly                             *
*					 placed on the board. If Player1 decides to place the ships manually, then he/she should be prompted to                    *
*					 place the Carrier first, Battleship second, Cruiser third, Submarine fourth, and the Destroyer last.                      *
*					 Note that ships cannot be placed diagonally on the board, they can only be placed vertically or horizontally.             *
*					 You program must check to see if the user tries to place a ship outside the boundaries of the board or on top             *
*					 of a ship that has already been placed. Each cell on the board that contains part of the ship must be                     *
*					 indicated by 'c' for Carrier, 'b' for Battleship, 'r' for Cruiser, 's' for Submarine, or 'd' for Destroyer.               *
*					 For example, if the Carrier was placed then the board should contain 5 'c' s for each cell on the board that              *
*					 has a piece of the Carrier, etc. Once Player1's ships have been placed, Player2's ships must be randomly placed.          *
*					 Note that the placement of Player2's ships must be unknown. Thus, Player2's board will only display '-'                   *
*					 in each cell after the placement of each ship. The program should randomly select Player1 or Player2 to go first.         * 
*					                                                                                                                           *
***********************************************************************************************************************************************/

#ifndef battleship_H
#define battleship_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <conio.h>

#define ROWS 11
#define COLS 11

#define TRUE 1
#define FALSE 0

#define NUM_OF_SHIPS  5

#define VERTICAL      1
#define HORIZONTAL    0

#define PLAYER_ONE    0
#define PLAYER_TWO    1

#define CARRIER       'c'
#define BATTLESHIP    'b'
#define CRUISER       'r'
#define SUBMARINE     's'
#define DESTROYER     'd'

#define CARRIERSIZE    5
#define BATTLESHIPSIZE 4
#define CRUSIERSUBSIZE 3
#define DESTOYERSIZE   2

#define MISS        'm'
#define HIT         '*'
#define WATER       '~'

typedef enum direction
{
	HOR, VER
} Dir;

/* STRUCT TYPES */


struct stats { 
	int        numHits;
	int        numMisses;
	int		   carrierHits;
	int		   battleshipHits;
	int		   crusierHits;
	int		   submarineHits;
	int		   destroyerHits;
	int        totalHits;
	double     hitMissRatio;
};

/*************************************************************
*Function: print_board();                                    *
*Date Created : 10 / 25 / 16                                 *
*Date Modified : 10 / 25 / 16                                *
*Description : This function prints a 10 by 10 grid size.    *
*Input Parameter : None                                      *
*Returns : None                                              *
*Preconditions : None                                        *
*Post Conditions : None                                      *
*************************************************************/

void print_board(char board[][11], int rows, int cols);

/*************************************************************
*Function: print_both_boards();                              *
*Date Created : 11 / 2 / 16                                  *
*Date Modified : 11 / 2 / 16                                 *
*Description : This function prints a 10 by 10 grid size.    *
*Input Parameter : None                                      *
*Returns : None                                              *
*Preconditions : None                                        *
*Post Conditions : None                                      *
*************************************************************/

void print_both_boards(char player[][11], char computer[][11], int rows, int cols);

/************************************************************************
*Function: welcome_screen();                                            *
*Date Created : 10 / 25 / 16                                            *
*Date Modified : 10 / 25 / 16                                           *
*Description : This function prints out the welcome screen for the user.*
*Input Parameter : None                                                 *
*Returns : None                                                         *
*Preconditions : None                                                   *
*Post Conditions : None                                                 *
************************************************************************/

void welcome_screen(void);

/*********************************************************
*Function: initialize_game_board();                      *
*Date Created : 10 / 25 / 16                             *
*Date Modified : 10 / 25 / 16                            *
*Description : This function initializes he game board.  *
*Input Parameter : None                                  *
*Returns : None                                          *
*Preconditions : None                                    *
*Post Conditions : None                                  *
*********************************************************/

void init_board(char board[][11], int rows, int cols);

/*********************************************************************************************
*Function: select_who_starts_first();                                                        *
*Date Created : 10 / 25 / 16                                                                 *
*Date Modified : 10 / 25 / 16                                                                *
*Description : This function allows the program to randomlly select which person goes first. *
*Input Parameter : None                                                                      *
*Returns : None                                                                              *
*Preconditions : None                                                                        *
*Post Conditions : None                                                                      *
*********************************************************************************************/

int select_who_starts_first(void);

/****************************************************************
*Function: Dir generate_dir();                                  *
*Date Created : 10 / 28 / 16                                    *
*Date Modified : 10 / 28 / 16                                   *
*Description : This function gives the direction to the user,   *
*  			   wheather they what it horizontal or vertical.    *
*Input Parameter : None                                         *
*Returns : None                                                 *
*Preconditions : None                                           *
*Post Conditions : None                                         *
****************************************************************/

Dir generate_dir(void);

/********************************************************************
*Function: manually_place_ships_on_board();                         *
*Date Created : 10 / 25 / 16                                        *
*Date Modified : 10 / 25 / 16                                       *
*Description : This function lets the user manually place thier     *
*   		   ships on to the board where ever they want to.       *
*Input Parameter : None                                             *
*Returns : None                                                     *
*Preconditions : None                                               *
*Post Conditions : None                                             *
********************************************************************/

void manually_place_ships_on_board(char board[ROWS][COLS], char ship_type, int ship_size);

/*****************************************************************************************
*Function: randomly_place_ships_on_board()                                               *
*Date Created : 10 / 25 / 16                                                             *
*Date Modified : 10 / 25 / 16                                                            *
*Description : This function allows the program to randoml place ships around the borad. *
*Input Parameter : None                                                                  *
*Returns : None                                                                          *
*Preconditions : None                                                                    *
*Post Conditions : None                                                                  *
*****************************************************************************************/

void randomly_place_ships_on_board(char board[ROWS][COLS], char ship_type, int ship_size);

/************************************************************************************
*Function: char *names[];                                                           *
*Date Created : 10 / 25 / 16                                                        *
*Date Modified : 10 / 25 / 16                                                       *
*Description : This function helps print the name of ships throughout the function. *
*Input Parameter : None                                                             *
*Returns : None                                                                     *
*Preconditions : None                                                               *
*Post Conditions : None                                                             *
************************************************************************************/

char *nameOfShip(char ship_type);

/********************************************************************************
*Function: manual_shot();                                                       *
*Date Created : 10 / 25 / 16                                                    *
*Date Modified : 10 / 25 / 16                                                   *
*Description :  This function gives the user the ablility to take a random shot.*
*Input Parameter : None                                                         *
*Returns : None                                                                 *
*Preconditions : None                                                           *
*Post Conditions : None                                                         *
********************************************************************************/

void manual_shot(char board[][11], char player_board[][11], char screen[][11], struct stats *player, FILE *battlelog);

/******************************************************************************
*Function: random_shot();                                                     *
*Date Created : 10 / 25 / 16                                                  *
*Date Modified : 10 / 25 / 16                                                 *
*Description :  This function gives the AI the ablility to take a random shot.*
*Input Parameter : None                                                       *
*Returns : None                                                               *
*Preconditions : None                                                         *
*Post Conditions : None                                                       *
******************************************************************************/

void random_shot(char board[][11], char screen[][11], struct stats *computer, FILE *battlelog);

/************************************************************************************
*Function: play_game()																*
*Date Created : 10 / 25 / 16                                                        *
*Date Modified : 10 / 25 / 16                                                       *
*Description : This function starts the game									    *
*Input Parameter : None                                                             *
*Returns : None                                                                     *
*Preconditions : None                                                               *
*Post Conditions : None                                                             *
************************************************************************************/
void play_game(char player_board[][11], char computer_board[][11], char screen[11], struct stats *player, struct stats *computer, FILE *battlelog);

#endif