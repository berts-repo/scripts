#include <iostream>
using namespace std;
/*************************************************************************************
   Program Name: SwitchSample.cpp
   Author: GT
   This program demonstartes the use of switch statements.
**************************************************************************************/

int main() {
    int rate;   // User's rating of a business

    cout << "Please rate your experience with a number between 1 (Bad) thru 10 (Good): ";
    cin >> rate;

    switch (rate) {
		case 5: case 4: case 3: case 2: case 1:
      // All these cases share the same actions
 			cout << "Sorry to disappoint you. We will try to do better next time.\n";
      // Notice these cases do not have a break, so they continue to the next one
		case 7: case 6:
		    cout << "Please tell our Manager what we could do better.\n";
		    break;   // break to stop all cases above
		case 9: case 8:
		    cout << "Please tell our Representative what we could do better.\n";
      // Notice this case does not have a break, so it continues to the next one
		case 10:
		    cout << "We appreciate your opinion!\n";
		    break;   // break to stop last two cases above
		default:
 			cout << "I am sorry. This is not a valid response.\n";
		    break;   // Optional break. The switch will end anyway.
	}
   return 0;
}  // end of main
