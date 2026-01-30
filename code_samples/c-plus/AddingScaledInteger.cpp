#include <stdio.h>
#define SIZE  5

// Program Name: AddingScaledInteger.cpp
// Author: GT
// This program shows problems when casting incompatible pointer types


int main(void)
{
	int array[SIZE];
	int *pA = array;
	int count = 0;

	printf("size of array: %zu\n", sizeof(array));
//  Wrong while loop commented out
//	  while (pA < (array + sizeof(array))) {
// The previous command sizeof(array) is obtaining the number of elements of the array
// multiplied (scaled) by the size of int (5x4bytes=20).
// By adding it to array (a pointer to itself) it says add 20 positions of size int
// because that addition in pointer arithmetic is of the size of the data type we are pointing to.
// Having a pointer to int means that by adding 20 to array we are adding add 20 positions of size of int
// or equivalently 80 bytes = (20 positions x 4 bytes = 80 bytes).

	while (pA < (array + (sizeof(array)/sizeof(array[0])))) {
		*pA = count;
		printf("%d\n", *pA);
		pA++;
		count += 1;
	}

	return 0;
}

