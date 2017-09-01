/*****************************************************************************************************
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
******************************************************************************************************/

#include "yahtzee.h"

/**********************************************************************************************
*Function: int game_menu()                                                                    *
*Date Created: 10/19/16                                                                       *
*Descriptions: This function shows a list to the user on the game options for the user.       *
*Input Parameters: NONE                                                                       *
*Returns:  NONE                                                                               *
*Preconditions:    NONE                                                                       *
*Postconditions:    NONE                                                                      *
**********************************************************************************************/

void game_menu(void)
{
	int choose = 0;
	do {
		printf("Yahtzee\n");
		printf("%d. 1. Print Game Rules.\n", GAME_RULES);
		printf("%d. 2. Start Game.\n", START_GAME);
		printf("%d. 3. Exit\n", EXIT_GAME);

		scanf("%d", &choose);
		while ((choose < GAME_RULES) || (choose > EXIT_GAME))
		{
			printf("Please input a valid option.\n");
			scanf("%d", &choose);
			system("cls");
		}
	} while ((choose >= GAME_RULES) && (choose <= EXIT_GAME));
}

/**********************************************************************************************
*Function: printGameRules()                                                                   *
*Date Created: 10/17/16                                                                       *
*Descriptions: This function shwos a list to the user on how to play Yahteez.                 *
*Input Parameters:  NONE                                                                      *
*Returns: menu                                                                                *
*Preconditions:   NONE                                                                        *
*Postconditions:  NONE                                                                        *
**********************************************************************************************/

void printGameRules(void)
{
	printf("\n\n");
	printf("       THE RULES OF YAHTZEE:             \n\n");
	printf("       The scorecard used for Yahtzee is composed of two sections.                     \n");
	printf("       A upper section and a lower section. A total of thirteen boxes or               \n");
	printf("       thirteen scoring combinations are divided amongst the sections.                 \n");
	printf("       The upper section consists of boxes that are scored by summing the              \n");
	printf("       value of the dice matching the faces of the box.If a player rolls               \n");
	printf("       four 3's, then the score placed in the 3's box is the sum of the dice           \n");
	printf("       which is 12. Once a player has chosen to score a box, it may not be changed     \n");
	printf("       and the combination is no longer in play for future rounds.                     \n");
	printf("       If the sum of the scores in the upper section is greater than or equal to 63,   \n");
	printf("       then 35 more points are added to the players overall score as a bonus.          \n");
	printf("       The lower section contains a number of poker like combinations.                 \n");
	printf("       See the table provided below :                                                  \n");
	printf("\n\n");
	printf("       PLEASE PRESS <ENTER> TO CONTINUE...                                             \n");

	printf("\n\n");

	printf("       NAME          |           COMBINATION           |       SCORE\n         ");
	printf("    -----------------+---------------------------------+------------------------------------------      \n");
	printf("    Three-Of-A-Kind  |  Three dice with the same face  | Sum of all face values on the 5 dice           \n");
	printf("    -----------------+---------------------------------+------------------------------------------      \n");
	printf("    Four-Of-A-Kind   |  Four dice with the same face   | Sum of all face values on the 5 dice           \n");
	printf("    -----------------+---------------------------------+------------------------------------------      \n");
	printf("    Full House       | One pair and a Three-Of-A-Kind  |         25                                     \n");
	printf("    -----------------+---------------------------------+------------------------------------------      \n");
	printf("    Small Straight   | A Sequence of four dice         |         30                                     \n");
	printf("    -----------------+---------------------------------+------------------------------------------      \n");
	printf("    Large Straight   | A sequence of five dice         |         40                                     \n");
	printf("    -----------------+---------------------------------+------------------------------------------      \n");
	printf("    Yahtzee          |  Five dice with the same face   |         50                                     \n");
	printf("    -----------------+---------------------------------+------------------------------------------      \n");
	printf("    Chance           | May be used for any sequence of |    Sum of all face value on the                \n");
	printf("                     | dice; (catch all combination)   |            5 dice                              \n");
	printf("    -----------------+---------------------------------+------------------------------------------      \n");
	printf("\n\n");
	printf("       PLEASE PRESS <ENTER> TO CONTINUE...                                                              \n");
}

/**********************************************************************************************
*Function: start_Game()                                                                       *
*Date Created: 10/17/16                                                                       *
*Descriptions: This function is the main function to start the game of Yahtzee.               *
*Input Parameters:                                                                            *
*Returns:                                                                                     *
*Preconditions:                                                                               *
*Postconditions:                                                                              *
**********************************************************************************************/

void start_game(void) {
	int player1_dice[5] = { 0 };
	int player2_dice[5] = { 0 };
	char input = '\0';
	int roll = 0, change = 0, die = 0, category = 0;
	int score1 = 0;
	int score2 = 0;
	for (int i = 0; i < 14; i++);
	{
		printf("Player 1's Turn:\n");
		roll_die(player1_dice);
		input = '\0';
		while (input != 'n' && roll < 2)
		{
			roll++;
			printf("Dice 1   Dice 2   Dice 3   Dice 4   Dice 5 \n");
			printf("  %d       %d      %d       %d        %d\n", player1_dice[0], player1_dice[1], player1_dice[2], player1_dice[3], player1_dice[4]);
			printf("Do you want to change any of the dice? (Y/N) \n");
			scanf(" %c", &input);
			if (input == 'y')
			{
				printf("How many dice do you want to roll?\n");
				scanf("%d", &change);
				for (int c = 0; c < change; c++)
				{
					printf("What do you want to change?\n");
					scanf("%d", &die);
					player1_dice[die - 1] = rand() % 6 + 1;
				}
			}
		}
		printf("Dice 1   Dice 2   Dice 3   Dice 4   Dice 5 \n");
		printf("  %d       %d      %d       %d        %d\n", player1_dice[0], player1_dice[1], player1_dice[2], player1_dice[3], player1_dice[4]);
		printf("1. Sum of 1's\n"
			"2. Sum of 2's\n"
			"3. Sum of 3's\n"
			"4. Sum of 4's\n"
			"5. Sum of 5's\n"
			"6. Sum of 6's\n"
			"7. Three-of-a-kind\n"
			"8. Four-of-a-kind\n"
			"9. Full house\n"
			"10. Small straight\n"
			"11. Large straight\n"
			"12. Yahtzee\n"
			"13. Chance)\n"
			"Enter a catagory:\n");
		scanf("%d", &category);
		computeCategoryScore(player1_dice, 4, category, &score1);
		printf("Player 1 Score: %d\n\n", score1);


		/*Player 2's Turn */

		printf("Player 2's Turn:\n");
		roll_die(player2_dice);
		input = '\0';
		roll = 0;
		while (input != 'n' && roll < 2)
		{
			roll++;
			printf("Dice 1   Dice 2   Dice 3   Dice 4   Dice 5 \n");
			printf("  %d       %d      %d       %d        %d\n", player2_dice[0], player2_dice[1], player2_dice[2], player2_dice[3], player2_dice[4]);
			printf("Do you want to change any of the dice? (Y/N) \n");
			scanf(" %c", &input);
			if (input == 'y')
			{
				printf("How many dice do you want to roll?\n");
				scanf("%d", &change);
				for (int c = 0; c < change; c++)
				{
					printf("What do you want to change?\n");
					scanf("%d", &die);
					player2_dice[die - 1] = rand() % 6 + 1;
				}
			}
		}
		printf("1. Sum of 1's\n"
			"2. Sum of 2's\n"
			"3. Sum of 3's\n"
			"4. Sum of 4's\n"
			"5. Sum of 5's\n"
			"6. Sum of 6's\n"
			"7. Three-of-a-kind\n"
			"8. Four-of-a-kind\n"
			"9. Full house\n"
			"10. Small straight\n"
			"11. Large straight\n"
			"12. Yahtzee\n"
			"13. Chance)\n"
			"Enter a catagory:\n");
		scanf("%d", &category);
		computeCategoryScore(player2_dice, 4, category, &score2);
		printf("Player 2 Score: %d\n\n", score2);

	}
}
/**********************************************************************************************
*Function: roll_die ()                                                                        *
*Date Created: 10/17/16                                                                       *
*Descriptions: This function rolls a dice and gives out a random number.                      *
*Input Parameters:     NONE                                                                   *
*Returns:       die_value                                                                     *
*Preconditions:      NONE                                                                     *
*Postconditions:     NONE                                                                     *
**********************************************************************************************/

int roll_die(int dice[])
{
	for (int i = 0; i < 5; i++)
	{
		dice[i] = rand() % 6 + 1;			// Roll Die Function.
	}
}
// srand((unsigned int)time(NULL)); // Random function
/**********************************************************************************************
*Function: computeCategoryScore()                                                             *
*Date Created: 10/17/16                                                                       *
*Descriptions: This function computes the scores in the categories.                           *
*Input Parameters:        (int dice[], int size, int category, int *score)                    *
*Returns:       multiple values                                                               *
*Preconditions:         NONE                                                                  *
*Postconditions:        NONE                                                                  *
**********************************************************************************************/

void computeCategoryScore(int dice[], int size, int category, int *score)
{

	int i = 0, ones = 0, twos = 0, threes = 0, fours = 0, fives = 0, sixes = 0, three_kind = 0, four_kind = 0, chance = 0, true_house = 0, int_small = 0, int_large = 0, int_yahtzee = 0;
	*score = 0;

	switch (category)
	{
	case ONES:
		if (ones == 0) {
			for (int j = 0; j < size; j++) {
				if (dice[j] == 1) {
					*score += 1;
				}
			}
			ones = 1;
		}
		break;
	case TWOS:
		if (twos == 0) {
			for (int j = 0; j < size; j++) {
				if (dice[j] == 2)
					*score += 2;
			}
			twos = 1;
		}
		break;
	case THREES:
		if (threes == 0) {
			for (int j = 0; j < size; j++) {
				if (dice[j] == 3)
					*score += 3;
			}
			threes = 1;
		}
		break;
	case FOURS:
		if (fours == 0) {
			for (int j = 0; j < size; j++) {
				if (dice[j] == 4) {
					*score += 4;
				}
			}
			fours = 1;
		}
		break;
	case FIVES:
		if (fives == 0) {
			for (int j = 0; j < size; j++) {
				if (dice[j] == 5)
					*score += 5;
			}
			fives = 1;
		}
		break;
	case SIXES:
		if (sixes == 0) {
			for (int j = 0; j < size; j++) {
				if (dice[j] == 6)
					*score += 6;
			}
			sixes = 1;
		}
		break;
	case THREE_OF_A_KIND:
		if (three_of_a_kind(dice) == THREE_OF_A_KIND && three_kind == 0) {
			for (i = 0; i < size; i++)
			{
				*score += dice[i];
			}
			three_kind = 1;
		}
		break;
	case FOUR_OF_A_KIND:
		if (four_of_a_kind(dice) == FOUR_OF_A_KIND && four_kind == 0) {
			for (i = 0; i < size; i++)
			{
				*score += dice[i];
			}
			four_kind = 1;
		}
		break;
	case CHANCE:
		if (chance == 0)
		{
			for (i = 0; i < NUMBER_OF_DICE; i++)
			{
				*score += dice[i];
			}
			chance = 1;
		}
		break;
	case FULL_HOUSE:
		if (full_house(dice) == FULL_HOUSE && true_house == 0)
		{
			*score += 25;
			true_house = 1;
		}
		break;
	case SMALL_STRAIGHT:
		if (small_straight(dice) == SMALL_STRAIGHT && int_small == 0)
		{
			*score += 30;
			int_small = 1;
		}
		break;
	case LARGE_STRAIGHT:
		if (large_straight(dice) == LARGE_STRAIGHT && int_large == 0)
		{
			*score += 40;
			int_large = 1;
		}
		break;

	case YAHTZEE:
		if (yahtzee(dice) == YAHTZEE && int_yahtzee == 0)
		{
			*score += 50;
			int_yahtzee = 1;
		}
		break;
	}
	
}

/**********************************************************************************************
*Function: int two_of_a_kind                                                                  *
*Date Created: 10/20/16                                                                       *
*Descriptions: This function calculates if two of the dice are the same                       *
*Input Parameters: (int dice[])                                                               *
*Returns:   TWO_OF_A_KIND                                                                     *
*Preconditions:  NONE                                                                         *
*Postconditions: NONE                                                                         *
**********************************************************************************************/

int two_of_a_kind(int dice[]) {
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (dice[j] == i)
				count++;
		}
		if (count == 2)
			i = 6;
		else
			count = 0;
	}
	if (count == 2)
		return TWO_OF_A_KIND;
	else
		return FALSE;
}

/**********************************************************************************************
*Function: int three_of_a_kind                                                                *
*Date Created: 10/20/16                                                                       *
*Descriptions: This function indicates if three of the dice are the same or not.              *
*Input Parameters: (int dice[]                                                                *
*Returns:  THREE_OF_A_KIND                                                                    *
*Preconditions:  NONE                                                                         *
*Postconditions: NONE                                                                         *
**********************************************************************************************/

int three_of_a_kind(int dice[]) {
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (dice[j] == i)
				count++;
		}
		if (count == 3)
			i = 6;
		else
			count = 0;
	}
	if (count == 3)
		return THREE_OF_A_KIND;
	else
		return FALSE;
}

/**********************************************************************************************
*Function: int four_of_a_kind                                                                 *
*Date Created: 10/20/16                                                                       *
*Descriptions: This function sees if four of the dice are the same.                           *
*Input Parameters: (int dice[])                                                               *
*Returns:  FOUR_OF_A_KIND                                                                     *
*Preconditions:    NONE                                                                       *
*Postconditions:   NONE                                                                       *
**********************************************************************************************/

int four_of_a_kind(int dice[]) {
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (dice[j] == i)
				count++;
		}
		if (count == 4)
			i = 6;
		else
			count = 0;
	}
	if (count == 4)
		return FOUR_OF_A_KIND;
	else
		return FALSE;
}

/**********************************************************************************************
*Function: int small_straight ()                                                              *
*Date Created: 10/20/16                                                                       *
*Descriptions: This function looks at the dice to see the dice had a 4 consecutive order.     *
*Input Parameters:  (int dice[])                                                              *
*Returns:         Small_Straight                                                              *
*Preconditions:   NONE                                                                        *
*Postconditions:  NONE                                                                        *
**********************************************************************************************/

int small_straight(int dice[])
{
	int count = 0;
	int sort_array[5] = { 0 };
	if (large_straight(dice) != LARGE_STRAIGHT
		&& two_of_a_kind(dice) != TWO_OF_A_KIND
		&& three_of_a_kind(dice) != THREE_OF_A_KIND
		&& four_of_a_kind(dice) != FOUR_OF_A_KIND
		&& yahtzee(dice) != YAHTZEE)
	{
		for (int i = 0; i < 4; i++) {
			if (sort_array[i] < sort_array[i + 1])
				count++;
		}
	}
}

/**********************************************************************************************
*Function: int large_straight ()                                                              *
*Date Created: 10/20/16                                                                       *
*Descriptions: This function sees if the dice have a 5 consecutive order                      *
*Input Parameters:   (int dice[])                                                             *
*Returns:          Large_Straight                                                             *
*Preconditions:      NONE                                                                     *
*Postconditions:     NONE                                                                     *
**********************************************************************************************/

int large_straight(int dice[])
{
	int sum = dice[0] + dice[1] + dice[2] + dice[3] + dice[4] + dice[5];
	if (two_of_a_kind(dice) != TWO_OF_A_KIND 
		&& three_of_a_kind(dice) != THREE_OF_A_KIND
		&& four_of_a_kind(dice) != FOUR_OF_A_KIND
		&& yahtzee(dice) != YAHTZEE
		&& ((sum == 15) || sum == 20))
		return LARGE_STRAIGHT;
	else
		return FALSE;
}

/**********************************************************************************************
*Function: int  full_house ()                                                                 *
*Date Created: 10/20/16                                                                       *
*Descriptions: This function calculates if the user gets 50 points(5 of the same dice         *
*Input Parameters: (int dice[])                                                               *
*Returns:        Yahteez                                                                      *
*Preconditions:   NONE                                                                        *
*Postconditions:  NONE                                                                        *
**********************************************************************************************/

int full_house(int dice[])
{
	if (three_of_a_kind(dice) == THREE_OF_A_KIND && two_of_a_kind(dice) == TWO_OF_A_KIND)
		return FULL_HOUSE;
	else 
		return FALSE;
}

/**********************************************************************************************
*Function: int  yahteez ()                                                                    *
*Date Created: 10/20/16                                                                       *
*Descriptions: This function calculates if the user gets 50 points(5 of the same dice         *
*Input Parameters: (int dice[])                                                               *
*Returns:        Yahteez                                                                      *
*Preconditions:   NONE                                                                        *
*Postconditions:  NONE                                                                        *
**********************************************************************************************/

int yahtzee(int dice[]) {
	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (dice[j] == i)
				count++;
		}
		if (count == 5)
			i = 6;
		else
			count = 0;
	}
	if (count == 5)
		return YAHTZEE;
	else
		return FALSE;
}
