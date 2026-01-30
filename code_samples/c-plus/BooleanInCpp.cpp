#include <iostream>
using namespace std;
/*************************************************************************************
   Program Name: BooleaninCpp.cpp
   Author: GT
   This program shows the creation and use of boolean variables,
   and Logical Operations in C++
**************************************************************************************/

int main() {
	int first;               // First number entered by an user
	int second;              // Second number entered by an user
	bool big100 = false;     // boolean variable indicating whether
	                         // the sum of first and second number
	                         // is bigger than 100

    cout << "Please enter a first integer value : ";
    cin >> first;
	cout << endl << "Please enter a second integer value: ";
	cin >> second;
	cout << endl;

	// Creates a table with logical operations performed on first and second
	cout << "---------------------------------" << endl;
	cout << boolalpha << "   Logical Operators Table" << endl;
	//  The boolalpha command writes the name of a boolean variable as a String
	cout << "---------------------------------" << endl;
	cout << "  ( " << first << " == " << second << " )\t|  " << (first == second) <<  endl;
	cout << "  ( " << first << " != " << second << " )\t|  " << (first != second) <<  endl;
	cout << "  ( " << first << " <  " << second << " )\t|  " << (first <  second) <<  endl;
	cout << "  ( " << first << " <= " << second << " )\t|  " << (first <= second) <<  endl;
	cout << "  ( " << first << " >  " << second << " )\t|  " << (first >  second) <<  endl;
	cout << "  ( " << first << " >= " << second << " )\t|  " << (first >= second) <<  endl;
	cout << "---------------------------------" << endl << endl;

	// Initializing a boolean variable and using it
	big100 = (first + second > 100);
	cout << "Is the sum of " << first << " plus " << second << " bigger than 100? " << big100 << endl << endl;

	return 0;
}  // end of main
