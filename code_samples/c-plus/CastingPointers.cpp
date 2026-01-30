#include <stdio.h>

// Program Name: CastingPointers.cpp
// Author: GT
// This program shows problems when casting incompatible pointer types

void g1(void) {
	int i = 0;
	int *ip =  &i;
	(*ip)++;
	printf("Inside g1 int i increased with int* is %d\n", i);
}

void g2(void) {
	int i = 0;
	// Casting int* to float* and writing through it is undefined behavior.
	printf("Inside g2 would cast int* to float*: i is still %d (cast skipped)\n", i);
}

void g3(void) {
	float f = 0.0f;
	// Casting float* to int* and writing through it is undefined behavior.
	printf("Inside g3 would cast float* to int*: f is still %f (cast skipped)\n", f);
}

void g4(void) {
	float f = 0.0f;
	float *ip = &f;
	(*ip)++;
	printf("Inside g4 float f increased with float* is %f\n", f);
}

int main(void)
{
	g1();
	g2();
	g3();
	g4();

	return 0;
}

