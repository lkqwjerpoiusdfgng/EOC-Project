/***************************************************
 ***** EOC - Part C: Recursive/Iterative Rollup ****
 ***************************************************
 *
 *      Filename: ProgramDriver.cpp
 *   Description: This program driver will test
 *				  the implementation of the 
 *				  recursive and iterative rollups
 *				  designed for a linked list structure
 *				  of two data members: value and sum.
 *
 *    Associated
 *		   files: Rollup.h		\\ Rollup class
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 28, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#include "Rollup.h"		// For rollup class
#include "GenValue.h"	// For random value generation
#include <iostream>		// For outputs (cout)
#include <stdlib.h>		// For exit function
using namespace std;

// Forward declarations (function prototypes)
void showWelcome();
void showMenu();
void testRollups();
void pressEnterToContinue();

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
		<< "the implementation and operation of a recursive and\n"
		<< "iterative rollup using linked lists.\n"
		<< "Code by: Craig Medlin\n"
		<< "Last modified: Nov. 28, 2014\n"
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
			<< "1. Demonstrate Rollups \n"
			<< "2. Display program information\n"
			<< "3. Exit the program \n\n"
			<< "Your selection: ";

		cin >> menuSelection;

		cout << "\n\n";

		switch (menuSelection)
		{
		case 1:
			testRollups();
			pressEnterToContinue();
			break;

		case 2:
			showWelcome();
			break;

		case 3:
			exit(EXIT_SUCCESS);
			break;

		default:
			cout << "Please enter a valid menu selection \n\n";
			pressEnterToContinue();
			break;
		}

	} while (menuSelection != 3);
}

void testRollups()
{
	// Seed random number generator
	srand(static_cast<int>(time(NULL)));

	cout << "\nWe will now test the Rollup class for both \n"
		<< "iterative and recursive BOM rollups.\n"
		<< "First we need to create a new Rollup object.\n\n";

	// Create a new rollup object
	Rollup<int> rollupBOM;

	cout << "*** NEW Rollup<int> object created\n\n";

	cout << "We will now populate the object with randomly generated values.\n\n";

	// Variable to hold generated values
	int value = 0;

	// Populate the list with 20 values
	for (int index = 0; index < 20; index++)
	{
		// Generate random value
		value = GenValue(10, 50);

		// Add value as node to list
		rollupBOM.newNode(value);

		// Print confirmation

		cout << value << " was added to the Rollup<int> list\n";
	}

	cout << endl;

	// Pause for keypress
	pressEnterToContinue();

	cout << "\nNext we will test the iterative rollup and display the results.\n\n";

	// Test iterative rollup
	rollupBOM.iterativeRollup();

	// Print list
	rollupBOM.displayList();

	// Pause for keypress
	pressEnterToContinue();

	cout << "\nNow we will test the recursive rollup and display the results.\n\n";

	// Test recursive rollup
	rollupBOM.recursiveRollup();

	// Print list
	rollupBOM.displayList();

	cout << "\nWe have finished testing the Rollup class.\n";

}

// Function to pause until user presses ENTER
void pressEnterToContinue()
{

	cin.sync();
	cout << "Press ENTER to continue... " << flush;
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	cout << "\n";

} /* PRESS_ENTER_TO_CONTINUE */