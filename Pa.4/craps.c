/*************************************************************************************************************************************************
Name:           Jasdeep Singh
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
**************************************************************************************************************************************************/
#include "Header.h"

/*******************************************************************************
    Function: print_game_rules
	Date Created : 10 / 5 / 16
	Date Modified : 10 / 5 / 16
	Description : This function allows the user to open the game rule option and examine how to play the game
	Input Parameter : None
	Returns : None
	Preconditions : None
	Post Conditions : None
********************************************************************************/

void print_game_rules(void) {
	printf(" A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.\n\n");
	printf("After the dice have come to rest, the sum of the spots on the two upward faces is calculated.\n\n");
	printf("If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called Craps),\n\n");
	printf("the player loses (i.e. the house wins).\n\n");       // Print Game Rules Function.
	printf("If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's point.\n\n");
	printf("To win, you must continue rolling the dice until you make your point. The player loses by rolling a 7 before making the point.\n\n");
}

/*******************************************************************************
Function: get_bank_balance
Date Created : 10 / 5 / 16
Date Modified : 10 / 5 / 16
Description : This function allows the user to add a money amount into the game. 
Input Parameter : None
Returns : None
Preconditions : None
Post Conditions : None
********************************************************************************/

double get_bank_balance(void) {
	double bank_balance = 0.0;
	printf("Please enter a bank balance.\n");			// Asks user how much is on there bank 
	scanf("%lf", &bank_balance);

	return bank_balance;

}

/*******************************************************************************
Function: get_wager_amount
Date Created : 10 / 5 / 16
Date Modified : 10 / 5 / 16
Description : This function allows the user to enter any vale to gamble with.
Input Parameter : None
Returns : None
Preconditions : None
Post Conditions : None
********************************************************************************/

double get_wager_amount(void) {
	double wager = 0.0;
	printf("Please enter wager amount.\n");			// Asks user how much they want to gamble.
	scanf("%lf", &wager);
	
	return wager;
}

/*******************************************************************************
Function: check_wager_amount
Date Created : 10 / 5 / 16
Date Modified : 10 / 5 / 16
Description : This function checks to see if the amount the user put in does not exceed their bank balence.
Input Parameter : None
Returns : None
Preconditions : None
Post Conditions : None
********************************************************************************/

int check_wager_amount(double wager, double balance)
{
	// Function checks to see if wager does not exceed bak balance amount.

	if (wager > balance)
	{
		return WAGER_INVALID;
	}
	else
	{
		return WAGER_VALID;
	}
}

/*******************************************************************************
Function: roll_die
Date Created : 10 / 5 / 16
Date Modified : 10 / 5 / 16
Description : This function allows the program to randomly rool a pair of dice
Input Parameter : None
Returns : None
Preconditions : None
Post Conditions : None
********************************************************************************/

int roll_die(void) 
{
	int die_value = 0;
	die_value = rand() % 6 + 1;				// Roll Die Function.

	return die_value;
}

/*******************************************************************************
Function: calculate_sum_dice
Date Created : 10 / 5 / 16
Date Modified : 10 / 5 / 16
Description : This function adds the sum of both the dice.
Input Parameter : None
Returns : None
Preconditions : None
Post Conditions : None
********************************************************************************/

int calculate_sum_dice(int die1_value, int die2_value)
{
	int sum = die1_value + die2_value;
	printf("sum: %d\n", sum);
	return sum;
}

/*******************************************************************************
Function: is_win_loss_or_point
Date Created : 10 / 5 / 16
Date Modified : 10 / 5 / 16
Description : This function allows the program to see if the user won or lost. 
Input Parameter : None
Returns : None
Preconditions : None
Post Conditions : None
********************************************************************************/

int is_win_loss_or_point(int sum_dice)
{
	int result;
	if ((sum_dice == 7) || (sum_dice == 11))
	{
		result = WIN;
		printf("You Win!\n");
	}
	else if ((sum_dice == 2) || (sum_dice == 3) || (sum_dice == 12))
	{
		result = LOSS;
		printf("Sorry, You Lose!\n");
	}
	else
	{
		result = POINT;
		printf("This is now your point\n");
	}
	return result;
}

/*******************************************************************************
Function: is_point_loss_or_niether
Date Created : 10 / 5 / 16
Date Modified : 10 / 5 / 16
Description : This function allows the program to see if you lost a point. 
Input Parameter : None
Returns : None
Preconditions : None
Post Conditions : None
********************************************************************************/

int is_point_loss_or_neither(int sum_dice, int point_value)
{
	int result = 0;
	if (point_value == POINT) {
		if (sum_dice == 7)
		{
			result = LOSS;
			printf("Sorry you lost.\n");
			return result;
		}
		else if (sum_dice == calculate_sum_dice(roll_die(), roll_die()))
		{
			result = WIN;
			printf("You Win\n");
			return result;
		}
		else
		{
			printf("Keep on going.\n");
			result = LOSS;
			return result;
		}
	}
	else{
		return point_value;
	}

}

/*******************************************************************************
Function: adjust_bank_balance
Date Created : 10 / 5 / 16
Date Modified : 10 / 5 / 16
Description : This function allows the program to adjust the users bank balance.
Input Parameter : None
Returns : None
Preconditions : None
Post Conditions : None
********************************************************************************/

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract, int sum_dice)
{
	double  balance = 0;
	while (check_wager_amount(wager_amount, bank_balance) == WAGER_INVALID) {
		printf("Retry: ");
		wager_amount = get_wager_amount();
	}
	if (add_or_subtract == WIN)
		balance = bank_balance + (wager_amount * 2);
	else
		balance = bank_balance - wager_amount;

	return balance;
}


/*******************************************************************************
Function: chatter_message
Date Created : 10 / 5 / 16
Date Modified : 10 / 5 / 16
Description : This function allows the program to intreact with the user if they win or loss with phrases.
Input Parameter : None
Returns : None
Preconditions : None
Post Conditions : None
********************************************************************************/

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance)
{
	int chatter_value = 0;
	chatter_value = rand() % 4 + 1;

	if (win_loss_neither == WIN)
	{
		switch (chatter_value)
		{
		case 1:
			printf("Congraulations, now keep gambling so you can loss your money again.\n");
			break;
		case 2:
			printf("Nice, you got lucky, bet you cant win again. \n");
			break;
		case 3:
			printf("Wow, your cool. \n");
			break;
		case 4:
			printf("Danggggggggggggggggggggg. \n");
			break;
		}
	}

	else
	{
		switch (chatter_value)
		{
		case 1:
			printf("Oh yeaha you lost, more green paper for me :)\n");
			break;
		case 2:
			printf("HA you lost fam. \n");
			break;
		case 3:
			printf("Dont play yourself fam. \n");
			break;
		case 4:
			printf("Harambe would be ashamed of you. \n");
			break;
		}
	}
	printf("Rolls: %d, Starting Balance: %lf, Current Balance: %lf\n", number_rolls, initial_bank_balance, current_bank_balance);
}

/*******************************************************************************
Function: Play game again function
Date Created : 10 / 5 / 16
Date Modified : 10 / 5 / 16
Description : This function allows the program to restart.
Input Parameter : None
Returns : None
Preconditions : None
Post Conditions : None
********************************************************************************/

void play_game(void)
{
	double balance = 0, new_balance = 0, wager = 0, sum = 0, result = 0;
	int die1 = 0, die2 = 0, count = 0, play = 1;

	balance = get_bank_balance();
	do
	{
		wager = get_wager_amount();
		check_wager_amount(wager, balance);
		die1 = roll_die();
		die2 = roll_die();
		count++;
		sum = calculate_sum_dice(die1, die2);
		result = is_point_loss_or_neither(sum, is_win_loss_or_point(sum));
		new_balance = adjust_bank_balance(balance, wager, result, sum);
		chatter_messages(count, result, balance, new_balance);

		if (balance > 0)
		{
			printf("Would you like to play again?\n");
			printf("Please enter '1' for yes or '0' for no. \n");
			scanf("%d", &play);
		}
		else 
		{
			printf("You lost bruh!");
			play = NOT_PLAY_AGAIN;
		}
	} while (play != NOT_PLAY_AGAIN);
}