#include <stdio.h>

// Program Name: ForAndDoLoopsUnsigned.cpp
// Author: GT
// This program shows the problem of wrapping on unsigned integers

int main(void)
{
	const unsigned int minRange = 0;    // Minimum possible range number
	const unsigned int maxRange = 100;   // Maximum possible range number
	const unsigned int minExp = 1;      // Minimum exponent for a power
	const unsigned int maxExp = 5;      // Maximum exponent for a power

	unsigned int total1;        // Sum of all values in a range
	unsigned int total2;        // Sum of all values in a range
	unsigned int count;  	   // Counter of valuies in a range
    unsigned int small;         // The smallest number in range of integers
    unsigned int large;         // The largest number in range of integers
    unsigned int exponent;      // Exponent of the power to which numbers will be raised
    unsigned int power;         // The power of a number

    // initialization
    total1 = 0;
    total2 = 0;
    count = 0;

	printf("This program will ask you for a range of integer numbers.\n");
	printf("You will provide the smallest and the largest number in this range.\n");
	printf("You will also indicate to which power these numbers will be raised.\n");

	// Do loops are used effectively for validation as follows
	do {   // Using a do-while to validate the user's smallest number
		printf("\nTell us the smallest integer value in a range (between %u-%u ): ", minRange, maxRange);
		scanf("%u", &small);
	} while (small< minRange || small > maxRange );   // The loop stops when an acceptable small number is provided.

	do {   // Using a do-while to validate the user's largest number
	    printf("\nTell us now the largest number in the range (bigger than %u up to %u ): ", small, maxRange)  ;
		scanf("%u", &large);
    } while (small > large || large > maxRange );   // The loop stops when an acceptable largest number is provided.

	do {   // Using a do-while to validate the range of the power number
		printf("\nTell us the exponent for the power (between %u thru %u ): ", minExp, maxExp) ;
		scanf("%u", &exponent);
	} while (exponent<minExp || exponent>maxExp);  // this loop stops when an acceptable power is provided

    // Printing the table
	printf("\nThe table of numbers between %u thru %u to the power of %u is: ", small, large, exponent);
	printf("\n------------------------------------\n");

	for (unsigned int i = small; i <= large; i++) {
		power = i;
		for (unsigned int j = 1; j < exponent; j++) { power *= i; } // Embedded loop to calculate the power
		printf(" %u\t| %u\n", i, power);
		total1 += i;
		total2 += power;
	}  // end of for
	printf("------------------------------------\n");
	printf(" %u\t| %u    <- Totals\n", total1, total2);
	printf("------------------------------------\n");

	return 0;
}  // end of main
