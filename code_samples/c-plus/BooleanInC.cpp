#include <stdio.h>
/*************************************************************************************
Program Name: BooleaninC.cpp
Author: GT
This program shows the how C deals with Boolean and Logical Operations
**************************************************************************************/

int main(void) {
	int first;               // First number entered by an user
	int second;              // Second number entered by an user
	int myBoolResult;        // An integer value used as a proxy for a boolen variable
							 // In C, 0 means false, any other value means true

	printf("Please enter a first integer value : ");
	scanf("%d",&first);
	printf("Please enter a second integer value: ");
	scanf("%d", &second);
	printf("\n");

	// Creates a table with logical operations performed on first and second
	printf("-------------------------------------------------\n");
	printf("  Logical Operators Table\n");
	printf("  In C:  0->false, 1 (or anything else) -> true.\n");
	printf("-------------------------------------------------\n");
	printf("  ( %d  ==  %d ) \t|  %d \n", first, second, (first == second));
	printf("  ( %d  !=  %d ) \t|  %d \n", first, second, (first != second));
	printf("  ( %d  <   %d ) \t|  %d \n", first, second, (first <  second));
	printf("  ( %d  <=  %d ) \t|  %d \n", first, second, (first <= second));
	printf("  ( %d  >   %d ) \t|  %d \n", first, second, (first >  second));
	printf("  ( %d  >=  %d ) \t|  %d \n", first, second, (first >= second));
	printf("-------------------------------------------------\n\n");

	// Evaluating and printing a boolean expression as an integer
	myBoolResult = ((first + second) > 100);
	printf("Is the sum of %d plus %d bigger than 100? %d\n\n", first, second, myBoolResult);

	return 0;
}  // end of main
