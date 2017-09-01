/**********************************************************************************************************************************************
*Name:				Jasdeep Singh                                                                                                              *
*Collaborator:       Edgar Perez                                                                                                               *
*Professor:          Andrew O'Fallon                                                                                                           *
*T.A:                Sam Chen                                                                                                                  *
*Class:              Computer 121                                                                                                              *
*Assignment:         P.A #5                                                                                                                    *
*Date:               October 12, 2016                                                                                                          *
*Description:        The program should be built such that the user is Player1 and the computer is Player2.                                    *
*                    Two boards exist within the game. Hint: each board should be implemented as a 2-dimensional array.                        *
*                    Each 2-dimensional array should be 10 X 10. One represents Player1's board and one represents Player2's board.            *
*                    At the beginning of the game each Players' game board should be initialized to all '-' indicating                         *
*                    that no ships have been placed on either board. Before the game starts, Player1 should have the                           *
*                    option to either manually place each of the 5 ships in his/her fleet or to have them randomly                             *
*                    placed on the board. If Player1 decides to place the ships manually, then he/she should be prompted to                    *
*                    place the Carrier first, Battleship second, Cruiser third, Submarine fourth, and the Destroyer last.                      *
*                    Note that ships cannot be placed diagonally on the board, they can only be placed vertically or horizontally.             *
*                    You program must check to see if the user tries to place a ship outside the boundaries of the board or on top             *
*                    of a ship that has already been placed. Each cell on the board that contains part of the ship must be                     *
*                    indicated by 'c' for Carrier, 'b' for Battleship, 'r' for Cruiser, 's' for Submarine, or 'd' for Destroyer.               *
*                    For example, if the Carrier was placed then the board should contain 5 'c' s for each cell on the board that              *
*                    has a piece of the Carrier, etc. Once Player1's ships have been placed, Player2's ships must be randomly placed.          *
*                    Note that the placement of Player2's ships must be unknown. Thus, Player2's board will only display '-'                   *
*                    in each cell after the placement of each ship. The program should randomly select Player1 or Player2 to go first.         *
*                                                                                                                                              *
***********************************************************************************************************************************************/

#include "battleship.h"

int main(void)
{
	srand((unsigned int)time(NULL));
	printf("Welcome To Battleship!!!\n\n"); // Title
	FILE *battlelog = fopen("battleship.log", "w");
	char p1_board[11][11] = { { '\0', '~' },{ '~' } }, p2_board[11][11] = { '\0' }, screen[11][11] = { '\0' };

	struct stats player = { 0, 0, 0, 0.0 };
	struct stats computer = { 0, 0, 0, 0.0 };
	struct stats *player_ptr = &player;
	struct stats *computer_ptr = &computer;

	int option = 0;

	do {
		printf("Press 1. for rules.\n"
			"Press 2. to play.\n"
			"Press 3. to exit\n");
		scanf("%d", &option);
		while (option < 1 || option > 3) {
			printf("Press 1. for rules.\n"
				"Press 2. to play.\n"
				"Press 3. to exit\n");
			scanf("%d", &option);
		}
		switch (option) {
		case 1:
			welcome_screen();
			break;
		case 2:
			play_game(p1_board, p2_board, screen, player_ptr, computer_ptr, battlelog);
			break;
		case 3:
			fclose(battlelog);
			exit(0);
			break;
		}
	} while (option > 0 && option < 4);

	return 0;
}
