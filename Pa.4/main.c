/****************************************************************************************************************************************************
Name:           Jasdeep Singh
Collaborator:   Edgar Perez
Professor:      Andrew O'Fallon
T.A:            Sam Chen
Class:          Computer Scence 121 
Assignment:     Pa.4
Date:           September 28,2016
Description:    Write a program that implements a craps game according to the rules below.
                A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.
				After the dice have come to rest, the sum of the spots on the two upward faces is calculated.
				If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called "craps"), 
				the player loses (i.e. the "house" wins).
				If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point."
				To win, you must continue rolling the dice until you "make your point." The player loses by rolling a 7 before making the point.
******************************************************************************************************************************************************/
#include "Header.h"

int main(void)
{
	int option = 0;// die1 = 0, die2 = 0, count = 1, sum = 0, point = 0, add_or_sub = 0;
	//double balance = 0.0, wager = 0.0;

	srand((unsigned int)time(NULL)); // Random function
	printf("Welcome To Craps!!!\n\n"); // Title
	do
	{
		printf("Please choose one of the options below\n\n"); // Begin game option menu.
		printf("1. Print game rules\n");			// Displays to user.
		printf("2. Play game\n");					// Displays to user.
		printf("3. Exit game\n");					// Displays to user.
		scanf("%d", &option);
		switch (option)				// Switch statement.
		{
		case RULES:
			print_game_rules();			// Case opens game rules.
			break;
		case PLAY:
			play_game();				// Case opens the play game function.
			break;
		case EXIT:
			printf("See ya later.\n");		// Case ends the program and displays message.
			break;
		default:
			break;
		}
		//system("cls"); // clear the console window
	} while ((option >= 1) && (option < 3));
}

