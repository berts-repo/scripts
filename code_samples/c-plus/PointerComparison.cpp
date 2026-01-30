#include <stdio.h>

// Program Name: PointerComparison.cpp
// Author: GT
// This program shows correct and incorrect ways to perform pointer comparisons

int main(void)
{
	char a[] = "aiuyno9oscsuxXawdaohoiYacjklasdaasd";     // first string
	char b[] = "aa9mjakajYssadaszdcdasdsdaXasdsadas";  // second string
	char *pA = &a[0];   // pointer to the first element of string a
	char *pB = &b[0];   // pointer to the first element of string b
	char *pXa, *pYa;     // Pointers to the last letters X and Y in string a

	// searching for the letters X and Y in string a
    pXa = NULL;
    pYa = NULL;
	for (char *p = pA; *p!='\0'; p = p + 1) {
		if (*p == 'X') {
			pXa = p;
		}
		else if (*p == 'Y') {
			pYa = p;
		}
	}

	// Correct pointer comparison. Both pXa and pYA refer to the same string a
	if (pXa == NULL || pYa == NULL) {
		printf("Either X or Y were not found in \n[%s]\n", a);
	}
	else if (pYa < pXa) {
		printf ("The last letter Y was found before the last letter X in \n[%s]\n",a);
	}
	else {
		printf ("The last letter X was found before the last letter Y in \n[%s]\n",a);
	}

	// Comparing pointers from different arrays is undefined.
	printf("Note: comparing pointers from different arrays is undefined in C.\n");

	return 0;
}

