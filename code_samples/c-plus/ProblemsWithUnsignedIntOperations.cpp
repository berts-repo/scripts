#include <stdio.h>
#include <limits.h>

/*************************************************************************************
  Program Name: ProblemsWithUnsignedIntOperations.cpp
  Author: GT
  This program shows How to prevent problems adding, subtracting or multiplying
  unsigned integers
**************************************************************************************/

int main(void) {

	unsigned int aUInt;	         // A temporary unsigned int variable for demostration
    unsigned int bUInt;          // A temporary unsigned int variable for demostration

	// 1. Problems with Addition of Unsigned Integers
	aUInt = UINT_MAX -  10000;
	bUInt = UINT_MAX - 100000;
	printf(" ----------------------------------------------------------------------------\n");
	printf("    Ways to Check Wrap around in Unsigned Integer Operations \n");
	printf(" ----------------------------------------------------------------------------\n");
	printf("     Addition: (aUINT + bUInt)\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf("If there is a chance this addition will wrap around check:\n");
	printf("           if (UINT_MAX - aUInt < bUInt)\n\n" );
	printf("Trying to Add : (%u + %u) ... \n", aUInt, bUInt);

	if (UINT_MAX - aUInt < bUInt) {
		printf("Addition will exceed the limit of %u and wrap around to %u .\n", UINT_MAX, aUInt + bUInt);
	}
	else {
		printf("Addition within limits: %u + %u = %u .\n", aUInt, bUInt, aUInt + bUInt);
	}
	printf(" ----------------------------------------------------------------------------\n");

	// 2. Problems with Subtraction of Unsigned Integers
	printf("     Subtraction: (aUINT - bUInt)\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf("If there is a chance this subtraction may wrap backwards, check:\n");
	printf("           if (aUInt < bUInt)\n\n");
	printf("Trying to Subtract : (%u - %u) ... \n", bUInt, aUInt);

	if (bUInt < aUInt) {
		printf("Subtraction will wrap around to %u - %u = %u .\n", bUInt, aUInt, bUInt - aUInt);
	}
	else {
		printf("Subtraction within limits: %u - %u = %u .\n", bUInt, aUInt, bUInt - aUInt);
	}
	printf(" ----------------------------------------------------------------------------\n");

	// 3. Problems with Multiplication of Unsigned Integers
	printf("     Multiplication: (aUINT * bUInt)\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf("If there is a chance this multiplication will wrap around check:\n");
	printf("           if (UINT_MAX / aUInt < bUInt)\n\n");
	printf("Trying to Multiply : (%u * %u) ... \n", aUInt, bUInt);

	if (UINT_MAX / aUInt < bUInt) {
		printf("Multiplication will exceed the limit of %u and wrap around to %u .\n", UINT_MAX, aUInt * bUInt);
	}
	else {
		printf("Multiplication within limits: %u * %u = %u .\n", aUInt, bUInt, aUInt * bUInt);
	}
	printf(" ----------------------------------------------------------------------------\n");


	return 0;
}  // end of main
