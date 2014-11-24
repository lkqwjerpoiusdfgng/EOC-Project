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
			<< "4. Display program information"
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
	SimpleVector<int> simVectorA(10); // = new SimpleVector<int>(10);

	// Output creation confirmation
	cout << "New SimpleVector<int> created, simVectorA.\n";
	
	// Create SimpleVector for double elements
//	SimpleVector<double> *simVectorB = new SimpleVector<double>();

	// Output creation confirmation
	cout << "New SimpleVector<double> created simVectorB.\n";

	// Fill arrays with data
	cout << "We will now fill the arrays with data.";

//	for (int index = 0, value = 1; index < 10; index++, value++)
//	{
//		simVectorA[index] = value;
//	}
}

void testSearchableVector()
{

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