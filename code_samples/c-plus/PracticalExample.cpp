#include <stdio.h>
/*
   Program Name: PracticalExample.cpp
   Author: GT
   This program calculates simple statistical values for a car usage
   and makes predictions for the next 10,000 miles based on these stats.
*/

int main(void) {
   // Constants
   const int DAYS_PER_WEEK = 7;
   const int WEEKS_PER_YEAR = 52;
   const float MILEAGE_GOAL = 10000.0f;

   // Variable Declarations
   int oldMileage;          // Old mileage
   int currentMileage;      // Current mileage
   int daysAgo;             // Number of days since last fill-up
   int daysToMore10K;       // Number of estimated days to reach next 10,000 miles under current conditions
   int weeksToMore10K;      // Number of estimated weeks to reach next 10,000 miles under current conditions
   int yearsToMore10K;      // Number of estimated years to reach next 10,000 miles under current conditions

   float mileDifference;    // Miles covered since last fill-up
   float milesRatio;        // Ratio of MILEAGE_GOAL over mileDifference. Used to do Pro-rata.
   float gallons;           // Price paid for the current fill-up in USD
   float price;             // Price paid for the current fill-up in USD
   float mpg;               // Miles per gallons since last fill-up
   float usdPerMile;        // USD per mile covered since last fill-up
   float priceToMore10K;    // Estimated USDs to reach next 10,000 miles under current conditions

   // Requesting Input from the user
   printf("How many days ago did you fill your car's tank? \n");
   scanf("%d", &daysAgo);
   printf("What was the mileage then? \n");
   scanf("%d", &oldMileage);
   printf("What is the current mileage? \n");
   scanf("%d", &currentMileage);
   printf("How many gallons did you take in this refilling? \n");
   scanf("%f", &gallons);
   printf("How much did you pay in USD? \n");
   scanf("%f", &price);

   printf("\nYou indicated that you filled your car %d days ago when it had %d miles.\n",daysAgo, oldMileage);
   printf("Now you are filling your car at %d miles with %.2f gallons for $%.2f.\n", currentMileage, gallons, price);

   // Performing calculations
   mileDifference = (float)(currentMileage - oldMileage);
   if (mileDifference <= 0.0f || gallons <= 0.0f) {
      printf("\nInvalid input: mileage must increase and gallons must be positive.\n");
      return 1;
   }
   milesRatio = MILEAGE_GOAL / mileDifference;

   mpg = mileDifference / gallons;
   usdPerMile = price / mileDifference;

   daysToMore10K = (int) (milesRatio * daysAgo);
   weeksToMore10K = daysToMore10K / DAYS_PER_WEEK ;
   yearsToMore10K = weeksToMore10K / WEEKS_PER_YEAR ;
   priceToMore10K = milesRatio * price;

   // Printing output
   printf("With this data we can say that:\n");
   printf("The current miles per gallon are %.2f.\n", mpg);
   printf("The approx. price per mile is $%.2f.\n", usdPerMile);
   printf("Under the current conditions, your next %.0f miles will be reached in %d days.\n", MILEAGE_GOAL, daysToMore10K);
   printf("This is approximately %d weeks, or %d years.\n", weeksToMore10K, yearsToMore10K);
   printf("And you may spend up to $%.2f to reach them.\n", priceToMore10K);

   return 0;
}  // end of main
