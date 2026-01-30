#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 1001

// Program Name: AppendingASCIIFile.cpp
// Author: GT
// This program shows how to append data to an ASCII file
// It assumes that the maximum size of a line is 1001 with a place for '\0'

int main(void) {
	char fileIn[] = "c-plus/Input4.txt";
	FILE *f = NULL;        // Pointer to a sequential ASCII input file
    char buffer[MAXSIZE] = "";      // buffer to receive lines from the file and user

	// Trying to open sequential input file
	f = fopen(fileIn,"a+");  // "a+" opens for read/append; we will rewind to read from start
	if (f == NULL) {
		fprintf(stderr, "File %s was not found in current directory\n",fileIn);
		return -1;
	}
	rewind(f);
	// Reading lines from the file one by one and
	// displaying in the standard output
	//Reading lines from the file one by one and printing them to the screen as they come
	while (fgets(buffer, sizeof(buffer), f) != NULL) {
		printf("%s",buffer);
	}

	// Input data to append from user
	printf("\nType a line to append and press Enter:\n");
	if (fgets(buffer, MAXSIZE, stdin) != NULL) {
		// Append data to file (file is already in append mode)
		fputs(buffer, f);
	}

	// Trying to close the sequential input file
	if (fclose(f) == EOF) {
		fprintf(stderr, "There is an error at closing %s\n", fileIn);
		return -2;
	}
	return 0;

}
