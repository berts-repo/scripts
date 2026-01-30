#include <iostream>
using namespace std;

// Program Name: RelationalOperators.cpp
// Author: GT
// This program ahows the use of Relational Operators while creating truth tables 


int main()
{
	cout << boolalpha << "         Truth Tables" << endl;
	// Creates truth table for && (logical AND) operator
	cout << "---------------------------------" << endl;
	cout << boolalpha << "|      Logical AND (&&) \t|" << endl;
    //  The boolalpha command writes the name of a boolean variable as a String
	cout << "---------------------------------" << endl;
	cout << "|  false && false  |  " << (false && false ) << "\t|" << endl
	     << "|  false && true   |  " << (false && true ) << "\t|" << endl
	     << "|   true && false  |  " <<  (true && false ) << "\t|" << endl
	     << "|   true && true   |  " <<  (true && true ) << "\t|" << endl;

    // Creates truth table for || (logical OR) operator
	cout << "---------------------------------" << endl;
	cout << "|      Logical OR (||) \t\t|" << endl;
	cout << "---------------------------------" << endl;
	cout << "|  false || false  |  " << (false || false ) << "\t|" << endl
	     << "|  false || true   |  " << (false || true ) << "\t|" << endl
	     << "|   true || false  |  " <<  (true || false ) << "\t|" << endl
	     << "|   true || true   |  " <<  (true || true ) << "\t|" << endl;

    // Creates truth table for ! (logical negation) operator
	cout << "---------------------------------" << endl;
	cout << "|      Logical NOT (!) \t\t|" << endl;
	cout << "---------------------------------" << endl;
	cout << "|     !false       |  " << (!false) << "\t|" << endl
	     << "|     !true        |  " << (!true) << "\t|" << endl;
	cout << "---------------------------------" << endl;

	return 0;
}  // end of main

