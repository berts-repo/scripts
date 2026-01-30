#include <stdio.h>
/*
    Program: CharTable.cpp
    Author: GT
    Description: Table of characters
*/
int main(void) {
    unsigned char c;
    printf("----------------------------------------------------------------------\n");
    printf("                        Printable ASCII code\n");
    printf("----------------------------------------------------------------------\n");
    for (int j = 0; j < 4; j++) {
        printf(" Code | Char |");
    }
    printf("\n");
    printf("----------------------------------------------------------------------\n");
    for (int i = 32; i <= 126; ) {
        for (int j = 0; (i <= 126) && (j < 4); j++) {
            c = (unsigned char)i;
            printf("  %3d |   %c  |", i, c);
            i++;
        }
        printf("\n");
    }
    printf("----------------------------------------------------------------------\n");
    return 0;
}
