#include <stdio.h>
#include <float.h>
#include <math.h>
#define TOL 1.0e-15

/*************************************************************************************
  Program Name: ProblemswithPrecision.cpp
  Author: GT
  This program shows the problem of precision with floating point values
**************************************************************************************/

int main(void) {

	float  largeFloat;    // A large float value
	float  diffFloat;     // Difference of FLT_MAX minus large float value
	double largeDouble;   // A large double value
	double diffDouble;    // Difference of DBL_MAX minus large float value

	// The following sentences show that floating point values
	// with large magnitude differences may not compute properly
	printf("-------------------------------------------------------------------\n");
	printf("      Large values cannot differentiate \"small\" value differences\n");
	printf("-------------------------------------------------------------------\n");

	largeFloat = 1.e31;

	printf("Largest float value (FLT_MAX) = \n%lf\n",FLT_MAX);
	printf("A large float value (1.e31)   = \n%lf\n", largeFloat);
	diffFloat = FLT_MAX - largeFloat;
	printf("Their difference = \n%lf\n", diffFloat);
	if (FLT_MAX == diffFloat) {
		printf("Difference was not properly computed.\n\n");
	}
	else {
		printf("Difference was evaluated.\n\n");
	}

	largeFloat = 1.e32;   // Changing to higher order of magnitude

	printf("Largest float value (FLT_MAX) = \n%lf\n", FLT_MAX);
	printf("A large float value (1.e32)   = \n%lf\n", largeFloat);
	diffFloat = FLT_MAX - largeFloat;
	printf("Their difference = \n%lf\n", diffFloat);
	if (FLT_MAX == diffFloat) {
		printf("Difference was not properly computed.\n\n");
	}
	else {
		printf("Difference was evaluated.\n\n");
	}

	largeDouble = 1.e291;

	printf("Largest double value (DBL_MAX) = \n%lf\n", DBL_MAX);
	printf("A large double value (1.e291)  = \n%lf\n", largeDouble);
	diffDouble = DBL_MAX - largeDouble;
	printf("Their difference = \n%lf\n", diffDouble);
	if (DBL_MAX == diffDouble) {
		printf("Difference was not properly computed.\n\n");
	}
	else {
		printf("Difference was evaluated.\n\n");
	}

	largeDouble = 1.e292;   // Changing to higher order of magnitude

	printf("Largest double value (DBL_MAX) = \n%lf\n", DBL_MAX);
	printf("A large double value (1.e292)  = \n%lf\n", largeDouble);
	diffDouble = DBL_MAX - largeDouble;
	printf("Their difference = \n%lf\n", diffDouble);
	if (DBL_MAX == diffDouble) {
		printf("Difference was not properly computed.\n\n");
	}
	else {
		printf("Difference was evaluated.\n\n");
	}

	return 0;
}  // end of main
