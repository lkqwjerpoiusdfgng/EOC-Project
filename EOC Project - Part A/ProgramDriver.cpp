/***************************************************
 ********** EOC - Part A: Vector Template **********
 ***************************************************
 *
 *      Filename: ProgramDriver.cpp
 *   Description: This driver is a testing program
 *				  designed to test the operation of
 *				  the SearchableVector and SimpleVector
 *				  template classes. 
 *
 *    Associated
 *		   files: SearchableVector.h	// Class header
 *				  SimpleVector.h		// Class header
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 23, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#include "SearchableVector.h"	// For SearchableVector class
#include "SimpleVector.h"		// For SimpleVector class
#include <stdlib.h>				// For exit, EXIT_SUCCESS

#include <iostream>				// For I/O operations
using namespace std;

/* Forward declarations */
			void showMenu();	// Displays program menu options
		 void showWelcome();	// Displays program information
	void testSimpleVector();	// Tests functions of SimpleVector class
void testSearchableVector();	// Tests functiosn of SearchableVector class
	void testAllFunctions();	// Tests functions of both classes
void pressEnterToContinue();	// Function to pause until ENTER is pressed

// Testing program's main function
int main() 
{
	// Display program information
	showWelcome();

	// Display program menu
	showMenu();

	// Indicate successful operation
	return 0;
}

// Function to display program information
void showWelcome()
{
	
	cout << "**************** TESTING PROGRAM ****************\n\n"
		 << "This program will provide the opportunity to test\n"
		 << "the implementation and operation of two template\n"
		 << "classes: SimpleVector and SearchableVector.\n\n"
		 << "Code by: Craig Medlin\n"
		 << "Last modified: Nov. 23, 2014\n"
		 << "Course: COSC 1437-P70\n"
		 << "Instructor: Charles Braun\n"
		 << "*****\n****\n***\n**\n*\n\n";

	pressEnterToContinue();
}

// Function to display menu of operations
void showMenu()
{
	// Declare local variables
	int menuSelection = 0;		// To hold user's menu selection

	// Loop to show menu
	do
	{
		cout << "Please select one of the following options: \n"
			<< "1. Demonstrate SimpleVector class \n"
			<< "2. Demonstrate SearchableVector class \n"
			<< "3. Demonstrate both Simple and Searchable vector classes \n"
			<< "4. Display program information\n"
			<< "5. Exit the program \n\n"
			<< "Your selection: ";

		cin >> menuSelection;

		cout << "\n\n";

		switch (menuSelection)
		{
		case 1:
			testSimpleVector();
			pressEnterToContinue();
			break;

		case 2:
			testSearchableVector();
			pressEnterToContinue();
			break;

		case 3 :
			testAllFunctions();
			pressEnterToContinue();
			break;

		case 4:
			showWelcome();
			break;

		case 5:
			exit(EXIT_SUCCESS);
			break;

		default:
			cout << "Please enter a valid menu selection \n\n";
			pressEnterToContinue();
			break;
		}

	} while (menuSelection != 5);
}

// This function tests the SimpleVector
void testSimpleVector()
{
	// Output information about testing process
	cout << "\n\n\n\n\n" 
		 << "We will now test the SimpleVector template class.\n"
		 << "First, we will create a SimpleVector object to store int elements,\n"
		 << "and also one to store double elements. We will then assign values\n"
		 << "to the vectors and demonstrate the different functions that are possible.\n\n\n";

	// Create SimpleVector for int elements
	SimpleVector<int> simVectorA(10);

	// Output creation confirmation
	cout << "New SimpleVector<int> created, simVectorA.\n";
	
	// Create SimpleVector for double elements
	SimpleVector<double> simVectorB(15);

	// Output creation confirmation
	cout << "New SimpleVector<double> created simVectorB.\n\n";

	// Fill arrays with data
	cout << "We will now fill the arrays with data.\n";

	double val2 = 1.11;	// To hold values for double vector

	for (int index = 0, val1 = 1; index < 10; index++, val1++)
	{
		simVectorA[index] = val1;
		cout << "simVectorA[" << index << "]: " << simVectorA[index] << endl;

		simVectorB[index] = val2;
		cout << "simVectorB[" << index << "]: " << simVectorB[index] << endl;

		val2 += 1.11;
	}

	// Pause for keypress
	pressEnterToContinue();

	// Test accessors for simVectorA
	cout << "\n\nWe will now test the accessor functions for each of the vectors,\n"
		 << "starting with simVectorA.\n\n";

	cout << "simVectorA.size(): " << simVectorA.size() << ", expected value is 10.\n"
		 << "simVectorA.capacity(): " << simVectorA.capacity() << ", expected value is 10.\n"
		 << "simVectorA.front(): " << simVectorA.front() << ", expected value is 1.\n"
		 << "simVectorA.back(): " << simVectorA.back() << ", expected value is 10.\n"
		 << "simVectorA.getElement(5): " << simVectorA.getElement(5) << ", expected value is 6.\n\n";
		 
	// Pause for keypress
	pressEnterToContinue();

	// Test accessors for simVectorB
	cout << "simVectorB.size(): " << simVectorB.size() << ", expected value is 10.\n"
		 << "simVectorB.capacity(): " << simVectorB.capacity() << ", expected value is 15.\n"
		 << "simVectorB.front(): " << simVectorB.front() << ", expected value is 1.11.\n"
		 << "simVectorB.back(): " << simVectorB.back() << ", expected value is 11.1.\n"
		 << "simVectorB.getElement(5): " << simVectorB.getElement(5) << ", expected value is 6.66.\n\n";

	// Pause for keypress
	pressEnterToContinue();

	// Test subscript operators
	cout << "We will now test the subscript operators for the vectors.\n\n"
		 << "simVectorA[3]: " << simVectorA[3] << " , the expected value is 4.\n"
		 << "simVectorB[3]: " << simVectorB[3] << " , the expected value is 4.44.\n\n";

	simVectorA[3] = simVectorA[5];

	cout << "simVectorA[3] = simVectorA[5]\n"
		 << "simVectorA[3]: " << simVectorA[3] << ", the expected value is 6.\n\n";

	simVectorB[3] = 1294.32;

	cout << "simVectorB[3] = 1294.32\n"
		 << "simVectorB[3]: " << simVectorB[3] << ", the expected value is 1294.32.\n\n";

	// Pause for keypress
	pressEnterToContinue();

	// Test Modifiers
	cout << "We will now test the modifier functions push_back and pop_back.\n"
		 << "simVectorA.size(): " << simVectorA.size() << "\n"
		 << "simVectorA.capacity(): " << simVectorA.capacity() << "\n"
		 << "simVectorA.back(): " << simVectorA.back() << "\n\n"
		 << "simVectorA.push_back(24)\n\n";

	simVectorA.push_back(24);

	cout << "simVectorA.size(): " << simVectorA.size() << "\n"
		<< "simVectorA.capacity(): " << simVectorA.capacity() << "\n"
		<< "simVectorA.back(): " << simVectorA.back() << "\n\n";

	// Pause for keypress
	pressEnterToContinue();

	cout << "simVectorB.size(): " << simVectorB.size() << "\n"
		 << "simVectorB.capacity(): " << simVectorB.capacity() << "\n"
		 << "simVectorB.back(): " << simVectorB.back() << "\n\n"
		 << "simVectorB.push_back(54.32)\n\n";

	simVectorB.push_back(54.32);

	cout << "simVectorB.size(): " << simVectorB.size() << "\n"
		<< "simVectorB.capacity(): " << simVectorB.capacity() << "\n"
		<< "simVectorB.back(): " << simVectorB.back() << "\n\n";

	cout << "simVectorB.pop_back()\n\n";

	simVectorB.pop_back();

	cout << "simVectorB.size(): " << simVectorB.size() << "\n"
		 << "simVectorB.capacity(): " << simVectorB.capacity() << "\n"
	     << "simVectorB.back(): " << simVectorB.back() << "\n\n";


	// Pause for keypress
	pressEnterToContinue();

	cout << "We have now tested all functions for the SimpleVector class.\n";
}

void testSearchableVector()
{
	cout << "We will now test the searchable vector class. We'll start by\n"
		<< "creating a new serachable vector and populating it with data.\n\n";

	// Create new searchable vector
	SearchableVector<int> vector(10);

	cout << "SearchableVector<int> vector(10)\n\n"
		<< "\nvector[0] = 26;"
		<< "\nvector[1] = 32;"
		<< "\nvector[2] = 1;"
		<< "\nvector[3] = 1983;"
		<< "\nvector[4] = 2;"
		<< "\nvector[5] = 0;"
		<< "\nvector[6] = 12;"
		<< "\nvector[7] = 99;"
		<< "\nvector[8] = 31;"
		<< "\nvector[9] = 21;\n\n";

	// Populate with values
	vector[0] = 26;
	vector[1] = 32;
	vector[2] = 1;
	vector[3] = 1983;
	vector[4] = 2;
	vector[5] = 0;
	vector[6] = 12;
	vector[7] = 99;
	vector[8] = 31;
	vector[9] = 21;

	// Attempt to locate value 12
	cout << "We will now run a search for value 12 within this vector.\n\n";

	bool exists = vector.doesExist(12);

	cout << "vector.doesExist(12): " << (exists ? "true" : "false") << "\n\n";

	cout << "We have now finished testing the searchable vector.\n\n";

}

void testAllFunctions()
{
	// Test SimpleVector
	testSimpleVector();

	// Test SearchableVector
	testSearchableVector();
}

// Function to pause until user presses ENTER
void pressEnterToContinue()
{

	cin.sync();
	cout << "Press ENTER to continue... " << flush;
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	cout << "\n";

} /* PRESS_ENTER_TO_CONTINUE */