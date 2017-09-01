/*****************************************************************************************************************************************************
Name:           Jasdeep Singh
Professor:      Andrew O'Fallon
T.A:            Sam Chen
Class:          Computer Scence 121
Assignment:     Pa.4
Date:           September 28, 2016
Descriptions:   Write a program that implements a craps game according to the rules below.
                A player rolls two dice. Each die has six faces. These faces contain 1, 2, 3, 4, 5, and 6 spots.
				After the dice have come to rest, the sum of the spots on the two upward faces is calculated.
				If the sum is 7 or 11 on the first throw, the player wins. If the sum is 2, 3, or 12 on the first throw (called "craps"), 
				the player loses (i.e. the "house" wins).
				If the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes the player's "point."
				To win, you must continue rolling the dice until you "make your point." The player loses by rolling a 7 before making the point.
*****************************************************************************************************************************************************/

#ifndef Header_H
#define Header_H

#include <stdio.h>
#include <stdlib.h> // rand(), srand()
#include <time.h> // time()
#include <math.h> 

#define PLAY_AGAIN 1
#define NOT_PLAY_AGAIN 0 
#define RULES 1
#define PLAY 2
#define EXIT 3
#define WAGER_VALID 1
#define WAGER_INVALID 0
#define WIN 1
#define LOSS 0
#define POINT -1


double get_bank_balance(void);      // This function asks the user at the start of the program what there intial... 
								   //bank balance is that they want to because the game requires a money amount. 

double get_wager_amount(void);    // This function asks the user to ake a wager/gamble ooff there bank balance.

int check_wager_amount(double wager, double balance); // The program will read the users input and see if the value they... 
		                                             //entered is not higher than their bank balance... 
                                                    //if it is then it will and ask for another wager value.  

int roll_die(void);			// This function will let the program randomly roll a pair of dice. 

int calculate_sum_dice(int die1_value, int die2_value);

int is_win_loss_or_point(int sum_dice);  // This function sums up the pair of dice and displays in on the screen. 

int is_point_loss_or_neither(int sum_dice, int point_value); // This function lets the program see if the user wins...
                                                            //or losses if they win then they win there wager...
                                                           //if not then they lose money.

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract, int sum_dice); 
												  // After the program has...
                                                 //seen if the user won or lost it will either... 
                                                //add or subtract the wager stated by the user and make a new bank balance. 

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
							    // This function lets the program display random phrase to the user after they win or lose.
void play_game(void);			// Lets program run again.

#endif