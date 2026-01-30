#include <stdio.h>
#include <math.h>
#include <errno.h>

/*************************************************************************************
  Program Name: UseOfMathFunctions.cpp
  Author: GT
  This program shows the use of several math functions from math.h
  Their correct use requires the testing of values before they are
  submitted as parameters. Some of these functions may not take
  all possible floating point values
**************************************************************************************/

int main(void) {

  double aDouble;   // a parameter for functions
  float aPower;     // a power for the pow function
  double result;    // a temporary result of an operation

  // sqrt function
  printf("-------------------------------------------------------------------\n");
  printf("          Correct Testing of domain for square root\n");
  printf("-------------------------------------------------------------------\n");
  printf("The function sqrt only receives non-negative values\n\n");
  printf("Before using sqrt(x) check that x >= 0.0 .\n\n");
  aDouble = pow(2, 10);
  printf("   Trying to calculate sqrt(%f) ... \n", aDouble);
  if (aDouble < 0.0) {
      printf(" ... Not possible. sqrt requires non-negative values.\n");
  }
  else {
      printf(" ... sqrt(%f) = %f\n", aDouble, sqrt(aDouble));
  }
  printf("-------------------------------------------------------------------\n\n");

  // log functions
  printf("-------------------------------------------------------------------\n");
  printf("          Correct Testing of domain for logarithms\n");
  printf("-------------------------------------------------------------------\n");
  printf("The functions log, log10 and log2 only receive positive values\n\n");
  printf("Before using log(x), log10(x) or log2(x) check that x > 0.0 .\n\n");
  aDouble = pow(2, 10);
  printf("   Trying to calculate log, log10 and log2 of (%f) ... \n", aDouble);
  if (aDouble < 0.0) {
      printf(" ... Not possible. logarithms requires non-negative values.\n");
  }
  else {
      printf(" ... log(%f)   = %f\n", aDouble, log(aDouble));
      printf("     log10(%f) = %f\n", aDouble, log10(aDouble));
      printf("     log2(%f)  = %f\n", aDouble, log2(aDouble));
  }
  printf("-------------------------------------------------------------------\n\n");

  // pow function
  printf("-------------------------------------------------------------------\n");
  printf("          Correct Testing of domain for power\n");
  printf("-------------------------------------------------------------------\n");
  printf("The function pow receives values x &,y to raise x to the yth power\n\n");
  printf(" pow can be used if:\n");
  printf("    (x>0) for all y,  OR\n");
  printf("    (x = 0) && (y > 0)  (produces 0.0), OR\n");
  printf("    (x < 0.0) && y is integer.\n");
  aDouble = pow(2, 10);
  aPower = 2.5;
  printf("   Trying to calculate pow(%f,%f) ... \n", aDouble,aPower);
  if (aDouble < 0.0)  {
      printf(" ... Not possible. first parameter cannot be negative.\n");
  }
  else {
      printf(" ... pow(%f,%f) = %f\n", aDouble, aPower, pow(aDouble,aPower));
  }

  // Handling of results out of range
  printf("\n If a function produces a result too large to be represented\n");
  printf(" The variable errno in <errno.h> has a value different than zero.\n");
  printf(" This value should be checked after the operation with:\n");
  printf("    if (errno)\n");
  aPower = 1000.0;
  printf("\n   Trying to calculate pow(%f,%f) ... \n", aDouble, aPower);
  if (aDouble < 0.0) {
	  printf(" ... Not possible. first parameter cannot be negative.\n");
  }
  else {
	  errno = 0;
	  result = pow(aDouble, aPower);
	  if (errno) {
		  printf(" ... Not possible. Result is too large.\n");
	  }
	  else {
		  printf(" ... pow(%f,%f) = %f\n", aDouble, aPower, result);
	  }
  }
  printf("-------------------------------------------------------------------\n\n");

  return 0;
}  // end of main
