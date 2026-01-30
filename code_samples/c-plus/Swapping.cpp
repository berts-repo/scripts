#include <stdio.h>

// Program Name: Swapping.cpp
// Author: GT
// This program shows the use of pointers to pass by reference

// badSwap uses copies of variables in main
void badSwap (int a, int b) {
	int t ;

	t = a ;
	a = b ;
	b = t ;

	printf("Inside badSwap after swapping x = %d, y = %d\n", a, b);
	return ;
}

// goodSwap uses references to variables in main by using the pointers
void goodSwap(int *a, int *b) {
	int t;

	t = *a;
	*a = *b;
	*b = t;

	printf("Inside goodSwap function after swapping x = %d, y = %d\n", *a, *b);
	return;
}

int main(void) {

	int x = 3, y = 5 ;

	printf("-----------------------------------------\n");
	printf("Before badSwap function       x = %d, y = %d\n", x, y);
	badSwap( x, y ) ;
	printf("After  badSwap function       x = %d, y = %d\n",x , y);
	printf("-----------------------------------------\n");

	printf("Before goodSwap function with pointers  x = %d, y = %d\n", x, y);
	goodSwap( &x, &y ) ;
	printf("After  goodSwap function with pointers  x = %d, y = %d\n", x, y);
	printf("-----------------------------------------\n");

	return 0;
}
