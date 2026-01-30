#include <stdio.h>
#include <limits.h>

/*************************************************************************************
  Program Name: ProblemsWithIntDivandRemainder.cpp
  Author: GT
  This program shows how to prevent problems with integer division
  and remainder operations
**************************************************************************************/

int main(void) {

    int divisor = 0;            // bad integer divisor
	signed long int sInt1;      // First signed long int variable for demostration
	signed long int sInt2;      // Second signed long int variable for demostration
	signed long int result;     // Variable for result of operations as signed long int

	printf(" ----------------------------------------------------------------------------\n");
	printf("                     Preventing Division byZero  \n");
	printf(" ----------------------------------------------------------------------------\n");

	// 1. Correct testing of division operation

    sInt1  = LONG_MAX;   // Large value to be divided

	printf("  1. Correct testing of division and remainder operations\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" When dividing, the divisor must always be tested that is not zero,\n");
	printf(" REGARDLESS OF THE DATA TYPE.\n");
	printf(" For example: before dividing by divisor, check:\n");
	printf("        if ( divisor == 0) \n");
	printf("\n ... Trying to divide (%ld) by (%d) ... \n", sInt1, divisor);

	if ( divisor == 0) {
		printf("    Division by zero is impossible.\n\n");
	}
	else {
		result = sInt1 / divisor;
		printf("    %ld / %d = %ld \n\n", sInt1, divisor, result);
	}
	printf(" The same goes for the remainder: before using %% divisor, check:\n");
	printf("        if ( divisor == 0) \n");
	printf("\n ... Trying to obtain the remainder of (%ld) by (%d) ... \n", sInt1, divisor);

	if ( divisor == 0) {
		printf("    Remainder of division by zero is not computable.\n\n");
	}
	else {
		result = sInt1 % divisor;
		printf("    %ld %% %d = %ld \n\n", sInt1, divisor, result);
	}
	printf(" ----------------------------------------------------------------------------\n");

    sInt1  = LONG_MIN;   // Small value to be divided
    sInt2  = -1;         // divisor

	printf("  2. Avoiding Overflow on the Division of Signed Integers\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" In addition, if the smallest signed long integer is to be divided by -1,\n");
	printf(" an overflow will occur, so this needs also to be prevented.\n");
	printf(" For example: before dividing a signed long int sInt1 by sInt2 check\n");
	printf("        if (   (sInt2 ==  0) ||\n");
	printf("             ( (sInt2 == -1) && (sInt1 == LONG_MIN) ) ) \n\n");
	printf("\n ... Trying to divide LONG_MIN (%ld) by signed int (%ld) ... \n", sInt1, sInt2);

	if (   (sInt2 ==  0) ||
	     ( (sInt2 == -1) && (sInt1 == LONG_MIN) ) ) {
		printf("    Division is not possible. It overflows.\n\n");
	}
	else {
		result = sInt1 / sInt2;
		printf("    %ld / %ld = %ld \n\n", sInt1, sInt2, result);
	}
	printf(" ----------------------------------------------------------------------------\n");


	return 0;
}  // end of main
