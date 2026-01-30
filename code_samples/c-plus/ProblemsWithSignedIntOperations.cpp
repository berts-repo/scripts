#include <stdio.h>
#include <limits.h>

/*************************************************************************************
  Program Name: ProblemsWithSignedIntOperations.cpp
  Author: GT
  This program shows how to prevent problems with operations on signed integers
**************************************************************************************/

int main(void) {

	signed int sInt1;      // First signed int variable for demostration
	signed int sInt2;      // Second signed int variable for demostration
	signed int result;     // Variable for result of operations as signed integer

	printf(" ----------------------------------------------------------------------------\n");
	printf("    Ways to Prevent Overflow in Operations with Signed Integers \n");
	printf(" ----------------------------------------------------------------------------\n");

	// 1. Preventing Overflow in Addition of Signed Integers

    // The following are large values that will give problems on addition
	sInt1  = INT_MAX;
	sInt2  = INT_MAX;

	printf("  1. Preventing Overflow in Addition of Signed Integers\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" If two signed integers are to be added, (sInt1+sInt2), check that \n");
	printf(" adding sInt2 will not go beyond the limits, considering the sign.\n");
	printf(" For example:\n");
	printf("           if ( ( (sInt2 > 0) && (sInt1 > (INT_MAX - sInt2)) ) || \n");
	printf("                ( (sInt2 < 0) && (sInt1 < (INT_MIN - sInt2)) ) ) \n\n");
	printf(" Trying to add signed int (%d) plus signed int (%d) ... \n", sInt1, sInt2);

	if ( ( (sInt2 > 0) && (sInt1 > (INT_MAX - sInt2)) ) ||
	     ( (sInt2 < 0) && (sInt1 < (INT_MIN - sInt2)) ) ) {
		printf("    Addition is not possible. It goes beyond the limits.\n");
	}
	else {
		result = sInt1 + sInt2;
		printf("    %d + %d = %d \n", sInt1, sInt2, result);
	}
	printf(" ----------------------------------------------------------------------------\n");

    // The following are values that will give problems on subtraction
	sInt1  = INT_MIN;
	sInt2  = INT_MAX;

	printf("  2. Preventing Overflow in Subtraction of Signed Integers\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" If a signed integer is to be subtracted from other, (sInt1-sInt2), check that \n");
	printf(" subtracting sInt2 will not go beyond the limits, considering the sign.\n");
	printf(" For example:\n");
	printf("           if ( ( (sInt2 > 0) && (sInt1 < (INT_MIN + sInt2)) ) || \n");
	printf("                ( (sInt2 < 0) && (sInt1 > (INT_MAX + sInt2)) ) ) \n\n");
	printf(" Trying to subtract signed int (%d) from signed int (%d) ... \n", sInt2, sInt1);

	if ( ( (sInt2 > 0) && (sInt1 < (INT_MIN + sInt2)) ) ||
	     ( (sInt2 < 0) && (sInt1 > (INT_MAX + sInt2)) ) ) {
		printf("    Subtraction is not possible. It goes beyond the limits.\n");
	}
	else {
		result = sInt1 - sInt2;
		printf("    %d - %d = %d \n", sInt1, sInt2, result);
	}
	printf(" ----------------------------------------------------------------------------\n");

    // The following are large values that will give problems on multiplication
	sInt1  = INT_MAX;
	sInt2  = INT_MAX;

	printf("  3. Preventing Overflow in Multiplication of Signed Integers\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" If two signed integers are to be multiplied, (sInt1 * sInt2), check that their\n");
	printf(" values will not make the result go beyond the limits, considering the sign.\n");
	printf(" For example:\n");
	printf("  if ( ( (sInt1 > 0) && (sInt2 > 0) && (sInt1 > (INT_MAX / sInt2) ) ) || \n");
	printf("       ( (sInt1 > 0) && (sInt2 < 0) && (sInt2 < (INT_MIN / sInt1) ) ) || \n");
	printf("       ( (sInt1 < 0) && (sInt2 > 0) && (sInt1 < (INT_MIN / sInt2) ) ) || \n");
	printf("       ( (sInt1 < 0) && (sInt2 < 0) && (sInt2 < (INT_MAX / sInt1) ) ) )\n\n");
	printf(" Trying to multiply signed int (%d) by signed int (%d) ... \n", sInt1, sInt2);

	if ( ( (sInt1 > 0) && (sInt2 > 0) && (sInt1 > (INT_MAX / sInt2) ) ) ||
	     ( (sInt1 > 0) && (sInt2 < 0) && (sInt2 < (INT_MIN / sInt1) ) ) ||
	     ( (sInt1 < 0) && (sInt2 > 0) && (sInt1 < (INT_MIN / sInt2) ) ) ||
	     ( (sInt1 < 0) && (sInt2 < 0) && (sInt2 < (INT_MAX / sInt1) ) ) ) {
		printf("    Multiplication is not possible. It goes beyond the limits.\n");
	}
	else {
		result = sInt1 * sInt2;
		printf("    %d * %d = %d \n", sInt1, sInt2, result);
	}
	printf(" ----------------------------------------------------------------------------\n");

	return 0;
}  // end of main
