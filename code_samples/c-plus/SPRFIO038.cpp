#include <stdio.h>
// Program Name: SPRFIO038.cpp
// Author: GT
// This program shows that a FILE object should not be copied

int copyingFile(void) {
  FILE f = *stdout;  // Trying to copy the standard output FILE to a local variable
  if (fputs("Accessing stdout thru a copied FILE\n", &f) == EOF) {
	  printf("An unexpected error just happened\n");
  }
  return 0;
}

int copyingPointertoFile(void) {
  FILE *f = stdout;
  if (fputs("Accessing stdout thru a copied pointer to a FILE\n", f) == EOF) {
       printf("An unexpected error just happened\n");
  }
  return 0;
}

int main(void) {
	copyingPointertoFile();
	// copyingFile();       // This function will hang the system if trying to run it

	return 0;
}
