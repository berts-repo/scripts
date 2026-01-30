#include <stdio.h>
/*
   Program Name: PrintFormats.cpp
   Author: GT
   This program shows the various placeholder formats for printf in C.
*/

int main(void) {
   // Example variables with values to print
   int i = 123;
   double x = 3.21;

   printf("Integer value:[%d]\n",i);
   printf("Integer value with size 10:[%10d]\n", i);
   printf("Integer value with requested size 1 is ignored:[%1d]\n", i);
   printf("Integer value with size 10 and padding zeroes in front:[%010d]\n", i);
   printf("Left aligned integer value with size 10:[%-010d]\n", i);
   printf("Positive and negative integer values with default format :[%d] [%d]\n", i, -i);
   printf("Positive and negative integer values with requested sign :[%+d] [%+d]\n", i, -i);
   printf("Positive and negative integer values with requested space :[% d] [% d]\n", i, -i);

   printf("Decimal value:\n[%f]\n", x);
   printf("Decimal value with size 10 and 2 decimals:\n[%10.2f]\n", x);
   printf("Decimal value with size 1 that is ignored and 2 decimals:\n[%1.2f]\n", x);
   printf("Decimal value with size 10, 2 decimals, and padding zeroes in front:\n[%010.2f]\n", x);
   printf("Left aligned decimal value with size 10 and 2 decimals:\n[%-010.2f]\n", x);
   printf("Positive and negative decimal values with default format :\n[%f] [%f]\n", x, -x);
   printf("Positive and negative decimal values with requested sign :\n[%+f] [%+f]\n", x, -x);
   printf("Positive and negative decimal values with requested space :\n[% f] [% f]\n", x, -x);

   return 0;
} //end of main
