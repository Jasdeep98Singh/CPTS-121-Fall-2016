/*****************************************************************************************************************************************
*Name:				 Jasdeep Singh                                                                                                       *
*Collaborator:       Edgar Perez                                                                                                         *
*Professor:          Andrew O'Fallon                                                                                                     *
*T.A:                Sam Chen                                                                                                            *
*Class:              Computer 121                                                                                                        *
*Assignment:         P.A #5                                                                                                              *
*Date:               October 12, 2016                                                                                                    *
*Description:        The program should be built such that the user is Player1 and the computer is Player2.                              *
*                    Two boards exist within the game. Hint: each board should be implemented as a 2-dimensional array.                  *
*                    Each 2-dimensional array should be 10 X 10. One represents Player1's board and one represents Player2's board.      *
*                    At the beginning of the game each Players' game board should be initialized to all '-' indicating                   *
*                    that no ships have been placed on either board. Before the game starts, Player1 should have the                     *
*                    option to either manually place each of the 5 ships in his/her fleet or to have them randomly                       *
*                    placed on the board. If Player1 decides to place the ships manually, then he/she should be prompted to              *
*                    place the Carrier first, Battleship second, Cruiser third, Submarine fourth, and the Destroyer last.                *
*                    Note that ships cannot be placed diagonally on the board, they can only be placed vertically or horizontally.       *
*                    You program must check to see if the user tries to place a ship outside the boundaries of the board or on top       *
*                    of a ship that has already been placed. Each cell on the board that contains part of the ship must be               *
*                    indicated by 'c' for Carrier, 'b' for Battleship, 'r' for Cruiser, 's' for Submarine, or 'd' for Destroyer.         *
*                    For example, if the Carrier was placed then the board should contain 5 'c' s for each cell on the board that        *
*                    has a piece of the Carrier, etc. Once Player1's ships have been placed, Player2's ships must be randomly placed.    *
*                    Note that the placement of Player2's ships must be unknown. Thus, Player2's board will only display '-'             *
*                    in each cell after the placement of each ship. The program should randomly select Player1 or Player2 to go first.   *
*****************************************************************************************************************************************/

#include "battleship.h"

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

void init_board(char board[][11], int rows, int cols)
{
	int row_index = 1, col_index = 1;

	for (row_index = 1; row_index < rows; ++row_index) // controls which row
	{
		for (col_index = 1; col_index < cols; ++col_index) // controls which column
		{
			board[row_index][col_index] = WATER;
		}
	}
	for (col_index = 1; col_index < cols; col_index++)
		board[0][col_index] = 47 + col_index;
	for (row_index = 1; row_index < rows; row_index++)
		board[row_index][0] = 47 + row_index;
}

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

void print_board(char board[][11], int rows, int cols)
{
	int row_index = 0, col_index = 0;

	printf("Player One\n");
	for (row_index = 0; row_index < rows; ++row_index) // controls which row
	{
		for (col_index = 0; col_index < cols; ++col_index) // controls which column
		{
			printf("%c ", board[row_index][col_index]);
		}
		printf("\n");
	}
	
}

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

void print_both_boards(char player[][11], char computer[][11], int rows, int cols) {
	int row_index = 0, col_index = 0;

	printf("Player One         \tComputer\n");
	for (row_index = 0; row_index < rows; ++row_index) // controls which row
	{
		for (col_index = 0; col_index < cols; ++col_index) // controls which column
		{
			printf("%c ", player[row_index][col_index]);
		}
		printf("\t");
		for (col_index = 0; col_index < cols; ++col_index)
		{
			printf("%c ", computer[row_index][col_index]);
		}
		printf("\n");
	}
} 

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

void welcome_screen(void) {
	printf("                                    WELCOME TO BATTLESHIP!!!\n");
	printf("RULES OF THE GAME:\n");
	printf("1. This is a two player game.\n");
	printf("2. Player 1 is you and Player 2 is the computer.\n");
	printf("3. Player 1 will be prompted if user wants to manually input coordinates\n");
	printf("   for the game board or have the computer randomly generate a game board\n");
	printf("4. There are five types of ships to be placed by longest length to the\n");
	printf("   shortest; Carrier has 5 cells, Battleship has 4 cells, Cruiser\n");
	printf("   has 3 cells, Submarine has 3 cells, Destroyer has 2 cells\n");
	printf("5. The computer randomly selects which player goes first\n");
	printf("6. The game begins as each player tries to guess the location of the ships\n");
	printf("   of the opposing player's game board; [*] hit and [m] miss\n");
	printf("7. First player to guess the location of all ships wins\n\n");
}

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
// srand((unsigned int)time(NULL)); // Random function
int select_who_starts_first(void)
{
	return rand() % 2 + 1;			// Chooses who goes first in function.
}

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

Dir generate_dir(void)
{
	Dir direction = HOR;

	direction = (Dir)(rand() % 2);

	return direction;
}

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

void manually_place_ships_on_board(char board[ROWS][COLS], char ship_type, int ship_size)
{
	int row = 0, col = 0, up = 0, down = 0, left = 0, right = 0;

	print_board(board, ROWS, COLS);
	printf("Type in the starting coordinate for your %s:\n", nameOfShip(ship_type));
	do {
		printf("Please enter within 0-9 for rows and columns: ");
		scanf("%d %d", &row, &col);
	} while ((row < 0 || row > 9) || (col < 0 || col > 9) || board[row + 1][col + 1] != WATER);

	row += 1;
	col += 1;

	for (int i = 0; i < ship_size; i++) {
		if (board[row - i][col] == WATER)
			up++;
		if (board[row + i][col] == WATER)
			down++;
		if (board[row][col - i] == WATER)
			left++;
		if (board[row][col + i] == WATER)
			right++;
	}

	if (up == ship_size)
		printf("Press the 'up' key to set at (%d, %d)\n", (row - up), col - 1);
	if (down == ship_size)
		printf("Press the 'down' key to set at (%d, %d)\n", (row + down) - 2, col - 1);
	if (left == ship_size)
		printf("Press the 'left' key to set at (%d, %d)\n", row - 1, (col - left));
	if (right == ship_size)
		printf("Press the 'right' key to set at (%d, %d)\n", row - 1, (col + right) - 2);

	int loop = 0;
	char a = 0;
	while (loop == 0) {
		a = getch();
		if (a == 0 || a == 0xE0) 
			a = getch();
			if (a == 72 && up == ship_size) {
				for (int j = 0; j < ship_size; j++)
					board[row - j][col] = ship_type;
				loop = 1;
			}
			else if (a == 80 && down == ship_size) {
				for (int j = 0; j < ship_size; j++)
					board[row + j][col] = ship_type;
				loop = 1;
			}
			else if (a == 75  && left == ship_size) {
				for (int j = 0; j < ship_size; j++)
					board[row][col - j] = ship_type;
				loop = 1;
			}
			else if (a == 77 && right == ship_size) {
				for (int j = 0; j < ship_size; j++)
					board[row][col + j] = ship_type;
				loop = 1;
			}
			else
				loop = 0;
	}
}

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

void randomly_place_ships_on_board(char board[ROWS][COLS], char ship_type, int ship_size) {
	int row = 0, col = 0, up = 0, down = 0, left = 0, right = 0, boolean = 0;

	while (board[row][col] != WATER) {
		row = rand() % 10 + 1;
		col = rand() % 10 + 1;
	}
	
	for (int i = 0; i < ship_size; i++) {
		if (board[row - i][col] == WATER)
			up++;                            // if vertical up||down
		if (board[row + i][col] == WATER)
			down++;
		if (board[row][col - i] == WATER)
			left++;                          // if horizontal left || right 
		if (board[row][col + i] == WATER)
			right++;
	}

	while (boolean == 0) {
		switch (rand() % 4 + 1) {
		case 1:
			if (up == ship_size) {
				for (int j = 0; j < ship_size; j++)
					board[row - j][col] = ship_type;
				boolean = 1;
			}
			else
				boolean = 0;
			break;
		case 2:
			if (down == ship_size) {
				for (int j = 0; j < ship_size; j++)
					board[row + j][col] = ship_type;
				boolean = 1;
			}
			else
				boolean = 0;
			break;
		case 3:
			if (left == ship_size) {
				for (int j = 0; j < ship_size; j++)
					board[row][col - j] = ship_type;
				boolean = 1;
			}
			else
				boolean = 0;
			break;
		case 4:
			if (right == ship_size) {
				for (int j = 0; j < ship_size; j++)
					board[row][col + j] = ship_type;
				boolean = 1;
			}
			else
				boolean = 0;
			break;
		default:
			boolean = 0;
			break;
		}
	}
}

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

void manual_shot(char board[][11], char player_board[][11], char screen[][11], struct stats *player, FILE *battlelog) {
	int row = 0, col = 0;
	printf("\nEnter your target:\n");
	
	do {
		printf("Please enter valid coordinates: ");
		scanf("%d %d", &row, &col);
		row += 1;
		col += 1;
	} while ((row < 1 || row > 10 || col < 1 || col > 10) ||
			board[row][col] == MISS ||
			board[row][col] == HIT);

	if (board[row][col] == CARRIER) {
		player->numHits++;
		player->totalHits++;
		player->carrierHits++;
		board[row][col] = HIT;
		screen[row][col] = HIT;
		system("cls");
		print_both_boards(player_board, screen, ROWS, COLS);
		if (player->carrierHits < CARRIERSIZE) {
			printf("Enemy has been hit!\n");
			fprintf(battlelog, "Player One: (%d, %d) \"hit\"\n", row - 1, col - 1);
		}
		else {
			printf("Enemy Carrier has sunk!\n");
			fprintf(battlelog, "Player One: (%d, %d) \"hit\" Sunk Carrier!\n", row - 1, col - 1);
		}
	}
	else if (board[row][col] == BATTLESHIP) {
		player->numHits++;
		player->totalHits++;
		player->battleshipHits++;
		board[row][col] = HIT;
		screen[row][col] = HIT;
		system("cls");
		print_both_boards(player_board, screen, ROWS, COLS);
		if (player->battleshipHits < BATTLESHIPSIZE) {
			printf("Enemy has been hit!\n");
			fprintf(battlelog, "Player One: (%d, %d) \"hit\"\n", row-1, col-1);
		}
		else {
			printf("Enemy Battleship has sunk!\n");
			fprintf(battlelog, "Player One: (%d, %d) \"hit\" Sunk Battleship!\n", row-1, col-1);
		}
	}
	else if (board[row][col] == CRUISER) {
		player->numHits++;
		player->totalHits++;
		player->crusierHits++;
		board[row][col] = HIT;
		screen[row][col] = HIT;
		system("cls");
		print_both_boards(player_board, screen, ROWS, COLS);
		if (player->crusierHits < CRUSIERSUBSIZE) {
			printf("Enemy has been hit!\n");
			fprintf(battlelog, "Player One: (%d, %d) \"hit\"\n", row-1, col-1);
		}
		else {
			printf("Enemy Cruiser has sunk!\n");
			fprintf(battlelog, "Player One: (%d, %d) \"hit\" Sunk Cruiser!\n", row-1, col-1);
		}
	}
	else if (board[row][col] == SUBMARINE) {
		player->numHits++;
		player->totalHits++;
		player->submarineHits++;
		board[row][col] = HIT;
		screen[row][col] = HIT;
		system("cls");
		print_both_boards(player_board, screen, ROWS, COLS);
		if (player->submarineHits < CRUSIERSUBSIZE) {
			printf("Enemy has been hit!\n");
			fprintf(battlelog, "Player One: (%d, %d) \"hit\"\n", row-1, col-1);
		}
		else {
			printf("Enemy Submarine has sunk!\n");
			fprintf(battlelog, "Player One: (%d, %d) \"hit\" Sunk Submarine!\n", row-1, col-1);
		}
	}
	else if (board[row][col] == DESTROYER) {
		player->numHits++;
		player->totalHits++;
		player->destroyerHits++;
		board[row][col] = HIT;
		screen[row][col] = HIT;
		system("cls");
		print_both_boards(player_board, screen, ROWS, COLS);
		if (player->destroyerHits < DESTOYERSIZE) {
			printf("Enemy has been hit!\n");
			fprintf(battlelog, "Player One: (%d, %d) \"hit\"\n", row-1, col-1);
		}
		else {
			printf("Enemy Destroyer has sunk!\n");
			fprintf(battlelog, "Player One: (%d, %d) \"hit\" Sunk Destroyer!\n", row-1, col-1);
		}
	}
	else {
		player->numMisses++;
		player->totalHits++;
		board[row][col] = MISS;
		screen[row][col] = MISS;
		system("cls");
		print_both_boards(player_board, screen, ROWS, COLS);
		printf("Target has been a miss.\n");
		fprintf(battlelog, "Player One: (%d, %d) \"miss\"\n", row-1, col-1);
	}
}

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

void random_shot(char board[][11], char screen[][11], struct stats *computer, FILE *battlelog) {
	int row = 0, col = 0;
	do {
		row = rand() % 10 + 1;
		col = rand() % 10 + 1;
	} while (board[row][col] == MISS || board[row][col] == HIT);

	if (board[row][col] == CARRIER) {
		computer->numHits++;
		computer->totalHits++;
		computer->carrierHits++;
		board[row][col] = HIT;
		print_both_boards(board, screen, ROWS, COLS);
		if (computer->carrierHits < CARRIERSIZE) {
			printf("You have been hit!\n");
			fprintf(battlelog, "Computer: (%d, %d) \"hit\"\n", row - 1, col - 1);
		}
		else {
			printf("Your Carrier has sunk!\n");
			fprintf(battlelog, "Computer: (%d, %d) \"hit\" Sunk Carrier!\n", row - 1, col - 1);
		}
	}
	else if (board[row][col] == BATTLESHIP) {
		computer->numHits++;
		computer->totalHits++;
		computer->battleshipHits++;
		board[row][col] = HIT;
		print_both_boards(board, screen, ROWS, COLS);
		if (computer->battleshipHits < BATTLESHIPSIZE) {
			printf("You have been hit!\n");
			fprintf(battlelog, "Computer: (%d, %d) \"hit\"\n", row - 1, col - 1);
		}
		else {
			printf("Your Battleship has sunk!\n");
			fprintf(battlelog, "Computer: (%d, %d) \"hit\" Sunk Battleship!\n", row - 1, col - 1);
		}
	}
	else if (board[row][col] == CRUISER) {
		computer->numHits++;
		computer->totalHits++;
		computer->crusierHits++;
		board[row][col] = HIT;
		print_both_boards(board, screen, ROWS, COLS);
		if (computer->crusierHits < CRUSIERSUBSIZE) {
			printf("You have been hit!\n");
			fprintf(battlelog, "Computer: (%d, %d) \"hit\"\n", row - 1, col - 1);
		}
		else {
			printf("Your Crusier has sunk!\n");
			fprintf(battlelog, "Computer: (%d, %d) \"hit\" Sunk Cruiser!\n", row - 1, col - 1);
		}
	}
	else if (board[row][col] == SUBMARINE) {
		computer->numHits++;
		computer->totalHits++;
		computer->submarineHits++;
		board[row][col] = HIT;
		print_both_boards(board, screen, ROWS, COLS);
		if (computer->submarineHits < CRUSIERSUBSIZE) {
			printf("You have been hit!\n");
			fprintf(battlelog, "Computer: (%d, %d) \"hit\"\n", row - 1, col - 1);
		}
		else {
			printf("Your Submarine has sunk!\n");
			fprintf(battlelog, "Computer: (%d, %d) \"hit\" Sunk Submarine!\n", row - 1, col - 1);
		}
	}
	else if (board[row][col] == DESTROYER) {
		computer->numHits++;
		computer->totalHits++;
		computer->destroyerHits++;
		board[row][col] = HIT;
		print_both_boards(board, screen, ROWS, COLS);
		if (computer->destroyerHits < DESTOYERSIZE) {
			printf("You have been hit!\n");
			fprintf(battlelog, "Computer: (%d, %d) \"hit\"\n", row - 1, col - 1);
		}
		else {
			printf("Your Destroyer has sunk!\n");
			fprintf(battlelog, "Computer: (%d, %d) \"hit\" Sunk Destroyer!\n", row - 1, col - 1);
		}
	}
	else {
		computer->numMisses++;
		computer->totalHits++;
		board[row][col] = MISS;
		print_both_boards(board, screen, ROWS, COLS);
		printf("You have avoided enemy fire!\n");
		fprintf(battlelog, "Computer: (%d, %d) \"miss\"\n", row - 1, col - 1);
	}
}

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

void play_game(char player_board[][11], char computer_board[][11], char screen[11], struct stats *player, struct stats *computer, FILE *battlelog) {
	init_board(player_board, ROWS, COLS);
	init_board(computer_board, ROWS, COLS);
	init_board(screen, ROWS, COLS);
	
	randomly_place_ships_on_board(computer_board, CARRIER, CARRIERSIZE);
	randomly_place_ships_on_board(computer_board, BATTLESHIP, BATTLESHIPSIZE);
	randomly_place_ships_on_board(computer_board, CRUISER, CRUSIERSUBSIZE);
	randomly_place_ships_on_board(computer_board, SUBMARINE, CRUSIERSUBSIZE);
	randomly_place_ships_on_board(computer_board, DESTROYER, DESTOYERSIZE);

	manually_place_ships_on_board(player_board, CARRIER, CARRIERSIZE);
	manually_place_ships_on_board(player_board, BATTLESHIP, BATTLESHIPSIZE);
	manually_place_ships_on_board(player_board, CRUISER, CRUSIERSUBSIZE);
	manually_place_ships_on_board(player_board, SUBMARINE, CRUSIERSUBSIZE);
	manually_place_ships_on_board(player_board, DESTROYER, DESTOYERSIZE);
	
	if (rand() % 2 == 0) {
		while (player->numHits != 17 && computer->numHits != 17) {
			manual_shot(computer_board, player_board, screen, player, battlelog);
			random_shot(player_board, screen, computer, battlelog);
		}
	}
	else {
		while (player->numHits != 17 && computer->numHits != 17) {
			random_shot(player_board, screen, computer, battlelog);
			manual_shot(computer_board, player_board, screen, player, battlelog);
		}
	}

	if (player->numHits == 17) {
		printf("You Won!\n");
		fprintf(battlelog, "Player One Won, Computer Lost\n");
	}
	else if (computer->numHits == 17) {
		printf("You Lost!\n");
		fprintf(battlelog, "Computer Won, Player One Lost\n");
	}
	fprintf(battlelog, "Player One Stats:\n"
		"Number of Hits: %d\n"
		"Number of Miss: %d\n"
		"Hit/Miss Ratio: %.2lf%%\n"
		"Computer Stats:\n"
		"Number of Hits: %d\n"
		"Number of Miss: %d\n"
		"Hit/Miss Ratio: %.2lf%%\n",
		player->numHits, player->numMisses, ((double)(player->numHits) / ((double)player->numMisses + (double)player->numHits)) * 100,
		computer->numHits, computer->numMisses, ((double)(computer->numHits) / ((double)computer->numMisses + (double)computer->numHits)) * 100);
}

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

char *nameOfShip(char ship_type) {
	char *names[5] = { "carrier", "battleship", "cruiser", "submarine", "destroyer" };
	switch (ship_type) {
	case CARRIER:
		return names[0];
		break;
	case BATTLESHIP:
		return names[1];
		break;
	case CRUISER:
		return names[2];
		break;
	case SUBMARINE:
		return names[3];
		break;
	case DESTROYER:
		return names[4];
		break;
	}
}
