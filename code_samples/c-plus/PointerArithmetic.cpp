#include <stdio.h>

// Program Name: PointerArithmetic.cpp
// Author: GT
// This program shows basic pointer arithmetic with arrays and strings.

int main(void)
{
	int A[] = { 55, 45, 35, 25, 15 };  // An array of integers
	int *pA = &A[0];   // pointer to the first element of array A
	int *qA = pA + 4;  // pointer to the last element of array A

	char s[30] = "Hello and Bye!"; // A string
	char *qS = &s[0];   // Pointer to the first character of string s

	printf("A[2] = %d\n",*(pA+2));
	printf("A[2] = %d\n\n", *(qA - 2));

	for (int i = 0; i < 5; i++) {
		printf("A[%d]=%d\n", i, A[i]);
	}

	printf("\n");

	for (int i=0, *p = &A[0]; i < 5; i++, p = p + 1) {
		printf("A[%d]=%d\n", i, *p);
	}

	printf("\n");

	for (char *p = qS; *p!='\0'; p = p + 1) {
		printf("%c\n", *p);
	}

	return 0;
}

