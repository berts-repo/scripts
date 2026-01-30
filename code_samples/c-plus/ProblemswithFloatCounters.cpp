#include <stdio.h>

/*************************************************************************************
  Program Name: ProblemswithFloatCounters.cpp
  Author: GT
  This program shows the problem of using floating point counters in loops
**************************************************************************************/

int main(void) {

  int i = 1; // counter of loop steps

  // The following loops show that the precision of floating point 
  // numbers in a computer is less than ideal.

  printf("-------------------------------------------------------------\n");
  printf("  Problems using floating point values for counters in loops\n");
  printf("-------------------------------------------------------------\n");
  // The following loop loop does not end with a value of 1.0f for x 
  // as mathematically expected:
  printf(" The following loop uses x as a counter,\n");
  printf(" hoping to stop exactly when x == 1.0f and print it,\n");
  printf(" but it cannot reach this value exactly (it goes beyond 1.0f).\n");
  printf("  for (float x = 0.1f; x <= 1.0f; x += 0.1f)\n\n");
  for (float x = 0.1f; x <= 1.0f; x += 0.1f) {
	  printf(" In loop step %d \tx=%f\n", i, x);
	  i++;
  }
  printf("-------------------------------------------------------------\n");
  // The following loop should stop after 10 steps, but it becomes 
  // an infinite loop because the floating point counter of x is imprecise. 
  // It stops because of the added variable i 

  printf(" The following loop cannot rely on the value of its counter x,\n");
  printf(" to stop after 10 loop steps because the increment is too small\n");
  printf(" to increment x significatively at each step.\n");
  printf(" It stops because of the added variable i.\n");
  printf("  for (float x = 100000000.0f; x <= 100000010.0f; x += 1.0f)\n\n");
  i = 1;
  for (float x = 100000000.0f; (x <= 100000010.0f)&&(i<=20); x += 1.0f) {
	printf(" In loop step %d \tx=%f\n",i,x);
	i++;
  }
  printf("-------------------------------------------------------------\n");

	return 0;
}  // end of main
