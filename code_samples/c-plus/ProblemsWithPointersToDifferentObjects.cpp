#include <stdio.h>
#include <stddef.h>
#define SIZE 10

// Program Name: ProblemsWithPointersToDifferentObjects.cpp
// Author: GT
// This program shows the problems of
//gt assuming that pointers are dec;ared next to each other in memeory

// enum { SIZE = 32 };

int main(void)
{
  int a[SIZE];
  int supposedlyAfterA = 10;   // This variable is not necessarily
                               // allocated after variable a in RAM
  int *begin = &a[0];          // Pointer to first element of array a
  size_t arrayLength;          // size of the array


  printf("The size of an array is %d. We show a correct way to calculate it.\n", SIZE);
  printf("Note: subtracting pointers to different objects is undefined in C.\n");
  printf("Correct calculation of array length that subtracts related pointers,\n");
  arrayLength = &(a[SIZE]) - begin;
  printf(" &(a[SIZE]) - &a[0] produces = %zu\n", arrayLength);

  return 0;
}


