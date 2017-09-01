/*
Programmer:    Jasdeep Singh
WSU ID:        011528942
Collaborator:  Edgar Perez
Class:         Computer Science 121, Fall 2016
Professor:     Mr. Andrew O' Fallon
Date:          September 5, 2016
Prgramming Assignment #1
Description:   Write a C program that evaluates the following equations in the program listed below,
1. Newton’s Second Law of Motion: force = mass * acceleration
2.Volume of a cylinder: volume_cylinder = PI * radius2 * height
3.Character encoding: encoded_character = (plaintext_character - 'A') + 'a' – shift
(note: what happens if plaintext_character is uppercase? What happens with various shift keys?)
4.Equivalent parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3), for 3 resistors.
R1, R2, and R3 are integers.
5.Resistive divider: vout = R2 / (R1 + R2) * vin
6.Distance between two points: distance = square root of ((x1 - x2)2 + (y1 - y2)2)
(note: you will need to use sqrt ( ) from <math.h>)
7. General equation: y = -x * (3 / 4) - z + a / (a % 2)
(recall: a is an integer; the 3 and 4 constants in the equation should be left as integers initially,
but explicitly type-casted as floating-point values)
*/

#include <stdio.h>
#include <math.h>
#define PI  3.14159f

int main(void) // starting point of program.
{
	/* 
	1. Newtons Second Law : Force = Mass * Acceleration.
	*/

	int Acceleration = 0; 
	int Mass = 0;
	int multiply;
	printf("******************************************************************\n");
	printf("Please enter the acceleration and mass\n"); // In parenthesis is what will be displayed to the user.
	scanf("%d%d", &Acceleration, &Mass);

	multiply = Acceleration * Mass;   // Program will calculate varibles. 

	printf("Force = Mass * Acceleration %d%d = %d\n",Acceleration, Mass, multiply); // Program will display value of acceleration * mass.
	printf("******************************************************************\n");

	/*
	2. Volume of a cylinder: volume_cylinder = PI* radius2 *height.
	*/

	double height;
	double radius;
	
	double volume;
	printf("******************************************************************\n");
	printf("This program is used to calculate the volume of a cylinder\n"); // what program will display to the user.

	printf("Please enter the height of the cylinder\n"); // User enters height of cylinder.
	scanf("%lf", &height);

	printf("Please enter the radius of the cylinder\n"); // User enters radius of cylinder.
	scanf("%lf", &radius);
	
	volume = height * pow(radius, 2) * PI;   // Program computes the solution.

	printf("Volume of a cylinder = PI* radius2 *height = %lf\n",volume);  // Volume of the cylinder is shown. 
	printf("********************************************************************\n");
	/*
	3. Character encoding: encoded_character = (plaintext_character - 'A') + 'a' – shift
(note: what happens if plaintext_character is uppercase? What happens with various shift keys?)
	*/

	char encoded_character = '\0';
	char plaintext_character = '\0';
	int shift = 0;
	printf("*********************************************************************\n");
	printf("Please enter a character\n"); // Program displays text to user.
	scanf(" %c", &plaintext_character);

	printf("Please enter an integer\n"); // Program asks user for an interger.
	scanf(" %d", &shift);
	
	encoded_character = (plaintext_character - 'A') + 'a' - shift; // Program uses this equation to solve for encoded character.

	printf("character = (plaintext_character - 'A') + 'a' – shift= %c\n", encoded_character);
	printf("**********************************************************************\n");
	/*
	4. Equivalent parallel resistance: parallel_resistance = 1 / (1 / R1 + 1 / R2 + 1 / R3), 
	for 3 resistors. R1, R2, and R3 are integers.
	*/

	int R1 = 0;
	int R2 = 0;
	int R3 = 0;
	double parallel_resistance;
	printf("***********************************************************************\n");
	printf("Please input the value for Resistor One (R1)\n"); // What program will display to the user. 
	scanf(" %d", &R1);

	printf("Please input the value for Resistor Two (R2)\n"); // What program will display to the user. 
	scanf(" %d", &R2);

	printf("Please input the value for Resistor Three (R3)\n"); // What program will display to the user. 
	scanf(" %d", &R3);
	
	parallel_resistance = 1 / (1 / (double)R1 + 1 / (double)R2 + 1 / (double)R3); 
	// Equation the program will use to calculate parallel resistence.

	printf("parallel_resistence = 1 / (1 / R1 + 1 / R2 + 1 / R3) = %lf\n",parallel_resistance);
	printf("**************************************************************************\n");
	/*
	5.Resistive divider: vout = R2 / (R1 + R2) * vin 
	(note: be sure to prompt for new R values; do not use the ones provided for equation 4)
	*/
	
	int R_1, R_2;
	double vout, vin;
	printf("*************************************************************************\n");
	printf("Please enter the value for Resistence One (R_1)\n"); //What program will prompt to the userfor Resistence 1.
	scanf(" %d", &R_1);

	printf("Please enter the value for Resistence Two (R_2)\n"); //What program will prompt to the user for Resistence 2.
	scanf(" %d", &R_2);

	printf("Please enter the value for the Volts In (vin)\n");  //What program will prompt to the user for Volts In.
	scanf(" %lf", &vin);

	vout =(double)R_2 / (double)(R_1 + R_2) * vin; // Program will use this formula to calculate the Volts Out. 
	
	printf("vout = R2 / (R1 + R2) * vin = %lf\n", vout);
	printf("**************************************************************************\n");
	/*
	6. Distance between two points: distance = square root of ((x1 - x2)2 + (y1 - y2)2)
(note: you will need to use sqrt ( ) from <math.h>)
	*/

	double x1=0, x2 = 0;
	double y1=0, y2 = 0;
	double distance;
	printf("***************************************************************************\n");
	printf("Please enter a x1 value\n");  // Program asks user for a x1 value.
	scanf(" %lf", &x1);

	printf("Please enter a x2 value\n");  // Program asks user for a x2 value.
	scanf(" %lf", &x2);

	printf("Please enter a y1 value\n");  // Program asks user for a y1 value.
	scanf(" %lf", &y1);

	printf("Please enter a y2 value\n");  // Program asks user for a y2 value.
	scanf(" %lf", &y2);

	distance = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2)); // Equation the program uses to find distance.
	printf("distance =square root of ((x1 - x2)2 + (y1 - y2)2) =  %lf\n", distance);
	printf("*************************************************************************\n");
/*
7. General equation: y = -x * (3 / 4) - z + a / (a % 2)
(recall: a is an integer; the 3 and 4 constants in the equation should be left as integers initially,
but explicitly type-casted as floating-point values)
*/

int  a = 0;
double x = 0, z = 0, y = 0;
printf("*****************************************************************************\n");
printf("Please enter an integer for a\n"); // Program asks user for value of a. 
scanf(" %d", &a);

printf("Please enter an integer for x\n"); // Program asks user for value of x. 
scanf(" %lf", &x);

printf("Please enter an integer for z\n"); // Program asks user for value of z. 
scanf(" %lf", &z);

y = -x * (3 / 4) - z + a / (double)(a % 2);
printf("%lf\n", y);
printf("*****************************************************************************\n");

return 0;



}