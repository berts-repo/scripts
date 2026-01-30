#include <stdio.h>
#include <limits.h>
//#define UINT_MAX 4294967290

/*************************************************************************************
  Program Name: WrappingwithUnsignedIntegers.cpp
  Author: GT
  This program shows the problem of wrapping in unsigned integers
**************************************************************************************/

int main(void) {

	unsigned int i;  	             // Counter of values in a range
    unsigned int start;              // The starting value in a loop
    unsigned int limit;              // The limit in a counting loop

	limit = UINT_MAX;
	printf(" -----------------------------------------------\n");
	printf("Numbers around the largest unsigned int\n");
	printf(" -----------------------------------------------\n");
	printf("Largest Unsigned integer value - 1: %u\n", limit - 1);
	printf("Largest Unsigned integer value    : %u\n", limit);
	printf("Largest Unsigned integer value + 1: %u\n", limit + 1);
	printf(" -----------------------------------------------\n");

	// The following loop works because it stops when i becomes UINT_MAX
	start = limit - 5;
	printf("Counting Up ...\n");
	printf(" -----------------------------------------------\n");
	for (i = start; i < limit; i++) {
		printf(" %u\n", i);
	}  // end of for
	printf(" -----------------------------------------------\n");

	// However the following is infinite because it checks if i <= UINT_MAX and
	// therefore adds 1 more to UINT_MAX wrapping around to 0,
	// and 0 is again smaller than UINT_MAX, so the loop persists.
	/*
	printf("Trying to count up ...\n");
	printf(" -----------------------------------------------\n");
	for (i = start; i <= limit; i++) {
		printf(" %u\n", i);
	}  // end of for
	printf(" -----------------------------------------------\n");
	*/

	// The same happens going backwards.
	// The following loop counts backwards until before 0
	start = limit + 5;
	printf("Counting Down ...\n");
	printf(" -----------------------------------------------\n");
	for (i = start; i > 0; i--) {
		printf(" %lu\n", i);
	}  // end of for
	printf(" -----------------------------------------------\n");

	// However it becomes infinite if we go further.
	// The loop checks if i >=0 and therefore subtract 1 more from 0
	// wrapping around to UINT_MAX, and UINT_MAX is again bigger than 0,
	// so the loop continues.
	/*
	printf("Trying to count down ...\n");
	printf(" -----------------------------------------------\n");
	for (i = start; i >= 0; i--) {
		printf(" %lu\n", i);
	}  // end of for
	printf(" -----------------------------------------------\n");
	*/

	return 0;
}  // end of main
