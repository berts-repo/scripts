#include <stdio.h>
#include <math.h>

// Program Name: Hypotenuse.cpp
// Author: GT
// This program shows de-referencing by calculating the hypotenuse of a right angled triangle

int main(void)
{
	float a, b;  //sides of the right angled triangle
	float c;     //hypotenuse of the right angled triangle
	float* pA, *pB, *pC;  //pointers to all sides of the triangle

	// Initializing the pointers
	pA = &a;
	pB = &b;
	pC = &c;

	// Reading the values of the sides from the user
	// Notice that scanf expects a pointer to a variable
	printf("Please enter the length of the first side of the right angled triangle:");
	scanf("%f", pA);
	printf("Now, please enter the length of the second side of the right angled triangle:");
	scanf("%f", pB);

	// Calculating the hypotenuse
	*pC = sqrtf((*pA) * (*pA) + (*pB) * (*pB));

	printf("The sides of the right angle triangle are: (%f, %f)\n", a, b);
	printf("The hypotenuse is: %f\n", c);

	return 0;
}

