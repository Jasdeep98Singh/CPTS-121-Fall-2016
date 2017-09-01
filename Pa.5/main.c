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

#include "yahtzee.h"

int main(void)
{
	int option = 0, press = 0, count = 0, menu = 0, roll = 0, number = 0, combination = 0;
	int die1 = 0, die2 = 0, die3 = 0, die4 = 0, die5 = 0, die_value = 0, chioce = 0;
	char yes = '\0', no = '\0';

	srand((unsigned int)time(NULL)); // Random function
	printf("Welcome To Yahtzee!!!\n\n"); // Title
	do
	{
		printf("Please choose one of the options below\n\n"); // Begin game option menu.
		printf("1. Print game rules\n");			// Displays to user.
		printf("2. Play game\n");					// Displays to user.
		printf("3. Exit game\n");					// Displays to user.
		scanf("%d", &option);
		switch (option)				// Switch statement.
		{
		case GAME_RULES:
			printGameRules();			// Case opens game rules.
			break;
		case START_GAME:
			start_game();				// Case opens the play game function.
			break;
		case EXIT_GAME:
			printf("See ya later.\n");		// Case ends the program and displays message.
			exit(0);
			break;
		default:
			break;
		}
		//system("cls"); // clear the console window
	} while ((option >= 1) && (option < 3));
}//return 0;