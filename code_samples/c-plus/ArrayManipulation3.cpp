#include <stdio.h>
#define SIZE 5
// the variable above is the size of an array in this program

// Program Name: ArrayManipulation3.cpp
// Author: GT
// Program to create an array of integers and find minimum, maximum,
//         total and average of its elements.
//         This program also shows the use of an additional variable (realSize)
//         to keep track of the number of elements in the array


int main(void)
{
	int elements[SIZE];		 // An array of integers
    int min;                 // the smallest element of the array
    int max;                 // the largest element of the array
	int total=0;             // this is the total of all the numbers
	int realSize=0;          // the real size of the array

	do {
		printf("Which is the real size of the array? (between 0 and %d): ",SIZE);
		scanf("%d",&realSize);
	} while((realSize<=0)||(realSize>SIZE));

	// Reading values from the user to the array
	for (int i=0; i<realSize; i++) {
		printf(" Enter number %d of %d: ", i+1, realSize);
		scanf("%d", &elements[i]);
	}

	// printing values from the array back to the user
	for (int i=0; i<realSize; i++) {
		printf(" Number [%d]= %d\n",i+1,elements[i]);
	}

	// Evaluating the smallest element in the array
    min = elements[0];
	for (int i=1; i<realSize; i++) {
		if (elements[i] < min ) {
			min = elements[i];
		}
	}
	printf(" The smallest element is %d\n", min);

	// Evaluating the largest element in the array
	max = elements[0];
	for (int i=1; i<realSize; i++) {
		if (elements[i] > max ) {
			max = elements[i];
		}
	}
	printf(" The largest element is %d\n", max);

	// Evaluating the addition of all elements in the array
	for (int i=0; i<realSize; i++) {
			total = total + elements[i];
	}
	printf(" The total of the elements is %d\n", total);

	// Evaluating and printing the average of all elements in the array
	printf(" The average of all the elements is %f\n", total/(1.0 * realSize));

	return 0;
}
