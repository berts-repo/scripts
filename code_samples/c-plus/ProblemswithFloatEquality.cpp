#include <stdio.h>
#include <math.h>
#define TOL 1.0e-15

/*************************************************************************************
  Program Name: ProblemswithFloatEquality.cpp
  Author: GT
  This program shows the problem comparing floating point values for equality
**************************************************************************************/

int main(void) {

	double value1 = 1./7.;         // first value
	double value2 = 2.-(13./7.);   // second value

	// The following sentencess show that floating point value variables
	// should not be compared for equality
	printf("-------------------------------------------------------------------\n");
	printf("          Problem checking equality with decimal values\n");
	printf("-------------------------------------------------------------------\n");
	printf("Value1 has 1/7, calculated by dividing 1 over 7.\n");
	printf("Value2 has also 1/7, calculated by subtracting 13/7 from 2.\n");
	printf("value1 = %.20lf\nvalue2 = %.20lf\n", value1, value2);
	if (value1 == value2) {
		printf("These values are equal.\n");
	}
	else {
	    printf("These values are NOT equal.\n");
	}

	// Using a Tolerance to evaluate equality in decimal values
	printf("-------------------------------------------------------------------\n");
	printf("          Solution\n");
	printf("-------------------------------------------------------------------\n");
	printf("\nUsing a tolerance of %e to calculate equality\n", TOL);
	printf("value1 = %.15lf\nvalue2 = %.15lf\n", value1, value2);
	if (fabs(value1- value2)<TOL) {
		printf("These values are equal.\n");
	}
	else {
		printf("These values are NOT equal.\n");
	}
	printf("-------------------------------------------------------------------\n");

	return 0;
}  // end of main
