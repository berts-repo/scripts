#include <stdio.h>
/*
   Program Name: ArithmeticOperations.cpp
   Author: GT
   This program shows arithmetic operations performed in C/C++
*/

int main(void) {
   // Variables for the demostration of calculations
   int i;
   int j = 6;
   int k;
   double a;

   // The print statements in the following commands replaced documentation
   // printf statements were indented to aid readability of commands

          printf("\nInteger Operations\n");
          printf("--------------------\n");
          printf("Initializing a integer variable i with a value of 5   [i=5;]     ");
   i = 5;
          printf("i=%d\n",i);
          printf("Integer variable j initialized at declaration to a value of 6    j=%d\n", j);
          printf("Updating of integer variable j using addition       [j=j+3;]     ");
   j = j + 3;
          printf("j=%d\n", j);
          printf("Variable k is initialized by the subtraction of variables i from j \n");
   k = j - i;
          printf("                                                    [k=j-i;]     k=%d\n", k);
          printf("Multiplication of k by 2                            [k=2*k;]     ");
   k = 2 * k;
          printf("k=%d\n",k);
          printf("Updating of k by integer division of j by i.        [k=j/i;]     ");
   k = j / i;
          printf("k=%d\n",k);
          printf("Modulus Operation. Updating of k by the remainder of j when divided by i\n");
   k = j % i;
          printf("                                                    [k=j%%i;]     k=%d\n", k);

          printf("Adding the value of k by 2                           [k+=2;]     ");
   k += 2;
          printf("k=%d\n",k);
          printf("Decrementing the value of k by 3                     [k-=3;]     ");
   k -= 3;
          printf("k=%d\n",k);
          printf("Multiplying the value of k by 7                      [k*=7;]     ");
   k *= 7;
          printf("k=%d\n",k);
          printf("Dividing the value of k by 2                         [k/=2;]     ");
   k /= 2;
          printf("k=%d\n",k);
          printf("Replacing the value of k with the remainder after dividing it by 4\n");
   k %= 4;
          printf("                                                     [k%%=4;]     k=%d\n", k);

          printf("Incrementing the value of k by 1                      [k++;]     ");
   k++;
          printf("k=%d\n",k);
          printf("Decrementing the value of k by 1                      [k--;]     ");
   k--;
          printf("k=%d\n",k);

          printf("Decrementing the value of k by 1                      [--k;]     ");
   --k;
          printf("k=%d\n",k);
          printf("Incrementing the value of k by 1                      [++k;]     ");
   ++k;
          printf("k=%d\n",k);

          printf("k is incremented by 2 and then the i is updated to k + k \n");
   i = (++k)+(++k);
          printf("                                            [i=(++k)+(++k);]     k=%d, i=%d\n", k, i);
          printf("j is updated to k + k and then  k is again incremented by 2\n");
   j = (k++)+(k++);
          printf("                                            [j=(k++)+(k++);]     j=%d, k=%d\n", j, k);

          printf ("The variable k is updated with the result of the following formulaas:\n");
          printf("No use of parentheses.              [k=15 - 4 * 2 + 13 / 4;]     ");
   k = 15 - 4 * 2 + 13 / 4;
          printf("k=%d\n",k);
          printf("Parentheses prioritize + and -  [k=(15 - 4) * (2 + 13) / 4;]     ");
   k = (15 - 4) * (2 + 13) / 4;
          printf("k=%d\n",k);
          printf("In addition, parentheses prioritize / over *\n");
          printf("                              [k=(15 - 4) * ((2 + 13) / 4);]     ");
   k = (15 - 4) * ((2 + 13) / 4);
          printf("k=%d\n",k);

          printf("\nFloating Point Operations\n");
          printf("-------------------------\n");
          printf("Notice, the following operations use the decimal value of 13.0\n");
          printf("The value of k is updated with type casting \n");
          k = (int)(15 - 4  * 2 + 13.0 / 4);
          printf("                          [k=(int)(15 - 4  * 2 + 13.0 / 4);]     k=%d\n",k);
          printf("Same operation updating double variable a. No type casting needed.\n");
   a = 15 - 4 * 2 + 13.0 / 4;
          printf("                              [a= (15 - 4  * 2 + 13.0 / 4);]     a=%f\n", a);
          printf("Parentheses prioritize + and -  \n");
   a = (15 - 4) * (2 + 13.0) / 4;
          printf("                              [a=(15 - 4) * (2 + 13.0) / 4;]     a=%f\n", a);
          printf("Parentheses prioritize / over *, but does not change result\n");
   a = (15 - 4) * ((2 + 13.0) / 4);
          printf("                            [a=(15 - 4) * ((2 + 13.0) / 4);]     a=%f\n", a);

   return 0;
} //end of main
