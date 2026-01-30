#include <stdio.h>
#define MAX_HOUR_PER_DAY 8.0f
// The two lines above show how to create constants using macros
/*
   Program Name: Constants.cpp
   Author: GT
   This program shows the three ways to create Constants in C/C++ and their use
*/

int main(void) {
   // The previous line uses a previously defined macro

   // Declaring a constant with the const keyword
   const int DAYS_IN_A_WEEK = 7;

   // Declaring an enumeration constant
   enum days {MON = 1, TUE, WED, THU, FRI, SAT, SUN};

   // Other declarations
   int day;     // User selected day
   float hoursWorked;   // Number of hours working in a week
   double avgHoursWorkedPerDay;  // Average number of hours worked per day

   printf("How many hours did you work this week?\n");
   scanf("%f",&hoursWorked);

   avgHoursWorkedPerDay = hoursWorked/ DAYS_IN_A_WEEK;   // Using a constant

   printf("You worked on average %5.2f hours per day this week.\n", avgHoursWorkedPerDay);

   if (avgHoursWorkedPerDay > MAX_HOUR_PER_DAY) {                     // Using a constant from a macro
           printf("You worked more than %5.2f hours per day.\n", MAX_HOUR_PER_DAY);     // Using a constant from a macro
           printf("You will need to take off one day next week.\n");
           printf("Choose the day you will take off [MON=1, TUE=2,etc] \n");
           scanf("%d", &day);
           while ( day < MON || day > SUN ) {          // Using some of the enumeration constants
                printf("You selected an invalid number for a day.Use only 1 to 7.\n");
                printf("Choose the day you will take off [MON=1, TUE=2,etc] \n");
                scanf("%d", &day);
           }
           printf("You selected not to work the day number %d.\n",day);
   }
   else {
           printf("Good. You did not exceed the allowed maximum of %5.2f hours per day\n",MAX_HOUR_PER_DAY); // Using a constant from a macro
   }

   return 0;
} //end of main
