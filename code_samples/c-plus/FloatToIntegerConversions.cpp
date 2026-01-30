#include <stdio.h>
#include <limits.h>
#include <math.h>

/*************************************************************************************
  Program Name: FloatToIntegerConversions.cpp
  Author: GT
  This program shows the constraints to convert floating point values to integers
**************************************************************************************/

int main(void) {

	signed int sInt;	         // A signed int variable for demostration
	unsigned int uInt;	         // An unsigned int variable for demostration
	float aFloat;                // A float type for demonstration
	double aDouble;              // A double type for demonstration

	printf(" ----------------------------------------------------------------------------\n");
	printf("    Way to Prevent Conversion Problems From Floating Point Types to Integers \n");
	printf(" ----------------------------------------------------------------------------\n");

	// 1. Converting a float onto a signed integer

	printf("     Converting a Float onto a Signed Integer\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" If a floating type is converted to a signed int check,\n");
	printf(" 1. If the float is a number\n");
	printf(" 2. If the float number can be represented by the precision of the integer\n");
	printf(" 3. If the float is within the range of the integer number\n\n");
	printf(" For example,\n");
	printf("           if ( isnan(aFloat) ||\n");
	printf("              (aFloat > (INT_MAX - 127)) ||\n");
	printf("              (aFloat < INT_MIN) )\n");

    // 1st Case
	aFloat = 2147483647.f;       // 1st Problem. This number (INT_MAX) is converted to 2147483648
								 // This is larger than INT_MAX and it should not be converted 

	printf("\nTrying to convert float (%f) into signed int ... \n", aFloat);

	if ( isnan(aFloat) ||
		 (aFloat > (INT_MAX - 127)) ||
		 (aFloat < INT_MIN) ){
		printf("    Conversion is not possible, even with casting to signed int.\n");
		sInt = (signed int) aFloat;
		printf("    If forced, %f is badly converted to : %d .\n", aFloat, sInt);
	}
	else {
		sInt = (signed int) aFloat;
		printf("    %f converted to signed integer: %d .\n", aFloat, sInt);
	}

	// 2nd Case
	aFloat = (INT_MAX - 127.f);  // Larger number that can be converted to signed int

	printf("\nTrying to convert float (%f) into signed int ... \n", aFloat);

	if (isnan(aFloat) ||
		(aFloat > (INT_MAX - 127)) ||
		(aFloat < INT_MIN)) {
		printf("    Conversion is not possible, even with casting to signed int.\n");
		sInt = (signed int)aFloat;
		printf("    If forced, %f is badly converted to : %d .\n", aFloat, sInt);
	}
	else {
		sInt = (signed int)aFloat;
		printf("    %f converted to signed integer: %d .\n", aFloat, sInt);
	}

	// 3rd Case
	aFloat = INT_MIN;  // Smallest number in for signed int (INT_MIN)

	printf("\nTrying to convert float (%f) into signed int ... \n", aFloat);

	if (isnan(aFloat) ||
		(aFloat > (INT_MAX - 127)) ||
		(aFloat < INT_MIN)) {
		printf("    Conversion is not possible, even with casting to signed int.\n");
		sInt = (signed int)aFloat;
		printf("    If forced, %f is badly converted to : %d .\n", aFloat, sInt);
	}
	else {
		sInt = (signed int)aFloat;
		printf("    %f converted to signed integer: %d .\n", aFloat, sInt);
	}

	printf(" ----------------------------------------------------------------------------\n\n");

	// 2. Converting a float onto a unsigned integer

	printf("     Converting a Float onto an Unsigned Integer\n");
	printf(" ----------------------------------------------------------------------------\n");
	printf(" If a floating type is converted to a unsigned int, check the same conditions,\n");
	printf(" 1. If the float is a number\n");
	printf(" 2. If the float number can be represented by the precision of the integer\n");
	printf(" 3. If the float is within the range of the integer number\n");
	printf("    (but the range does not include negative numbers)\n");
	printf(" For example,\n");
	printf("           if ( isnan(aFloat) ||\n");
	printf("           (aFloat < 0)  ||\n");
	printf("           (aFloat > (UINT_MAX - 255)))\n");

	// 5th case
	aFloat = 4294967295.0;   // 3rd Problem. This number (UINT_MAX) is converted to 4294967296
							 // This is larger than UINT_MAX and it should not be converted  

	printf("\nTrying to convert float (%f) into unsigned int ... \n", aFloat);
	if (isnan(aFloat) ||
		(aFloat < 0)  ||
		(aFloat > (UINT_MAX - 255))) {
		printf("    Conversion is not possible, even with casting to unsigned int.\n");
		uInt = (unsigned int) aFloat;
		printf("    If forced, %f is badly converted to : %u .\n", aFloat, uInt);
	}
	else {
		uInt = (unsigned int)aFloat;
		printf("    %f converted to unsigned integer: %u .\n", aFloat, uInt);
	}

	// 6th case
	aFloat = (UINT_MAX - 256.0f);   // Larger number that can be converted to unsigned int 

	printf("\nTrying to convert float (%f) into unsigned int ... \n", aFloat);

	if (isnan(aFloat) ||
		(aFloat < 0) ||
		(aFloat >(UINT_MAX - 128))) {
		printf("    Conversion is not possible, even with casting to unsigned int.\n");
		uInt = (unsigned int)aFloat;
		printf("    If forced, %f is badly converted to : %u .\n", aFloat, uInt);
	}
	else {
		uInt = (unsigned int)aFloat;
		printf("    %f converted to unsigned integer: %u .\n", aFloat, uInt);
	}


	printf(" ----------------------------------------------------------------------------\n");
	
	return 0;
}  // end of main
