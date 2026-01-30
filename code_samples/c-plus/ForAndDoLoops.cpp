#include <stdio.h>

// Program Name: ForAndDoLoops.cpp
// Author: GT
// This program uses a definitive loops to produce the power of numbers
// and present them in a table. It uses a for statement for calculations.
// It also uses do-whiles for validation

int main(void)
{
	const int minRange = 0;    // Minimum possible range number
	const int maxRange = 30;   // Maximum possible range number
	const int minExp = 1;      // Minimum exponent for a power
	const int maxExp = 5;      // Maximum exponent for a power

	int total1;        // Sum of all values in a range
	int total2;        // Sum of all values in a range
	int count;  	   // Counter of valuies in a range
    int small;         // The smallest number in range of integers
    int large;         // The largest number in range of integers
    int exponent;      // Exponent of the power to which numbers will be raised
    int power;         // The power of a number

    // initialization
    total1 = 0;
    total2 = 0;
    count = 0;

	printf("This program will ask you for a range of integer numbers.\n");
	printf("You will provide the smallest and the largest number in this range.\n");
	printf("You will also indicate to which power these numbers will be raised.\n");

	// Do loops are used effectively for validation as follows
	do {   // Using a do-while to validate the user's smallest number
		printf("\nTell us the smallest integer value in a range (between %d-%d): ", minRange, maxRange);
		scanf("%d",&small);
	} while (small< minRange || small > maxRange );   // The loop stops when an acceptable small number is provided.

	do {   // Using a do-while to validate the user's largest number
	    printf("\nTell us now the largest number in the range (bigger than %d up to %d): ", small, maxRange);
		scanf("%d",&large);
    } while (small > large || large > maxRange );   // The loop stops when an acceptable largest number is provided.

	do {   // Using a do-while to validate the range of the power number
		printf("\nTell us the exponent for the power (between %d thru %d): ", minExp, maxExp);
		scanf("%d",&exponent);
	} while (exponent<minExp || exponent>maxExp);  // this loop stops when an acceptable power is provided

    // Printing the table
	printf("\nThe table of numbers between %d thru %d to the power of %d is:\n", small, large, exponent);
	printf("------------------------------------\n");

	for (int i = small; i <= large; i++) {
		power = i;
		for (int j = 1; j < exponent; j++) { power *= i; } // Embedded loop to calculate the power
		printf(" %d\t| %d\n", i, power);
		total1 += i;
		total2 += power;
	}  // end of for
	printf("------------------------------------\n");
	printf(" %d \t| %d    <- Totals\n", total1, total2);
	printf("------------------------------------\n");

	return 0;
}  // end of main
