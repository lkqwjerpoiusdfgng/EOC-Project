/***************************************************
********** EOC - Part B: Basic Link List **********
***************************************************
*
*      Filename: ProgramDriver.cpp
*   Description: This program will test the operation
*				 of the classes created for the 
*				 Basic Link List assignment. This
*				 includes the Basic Link List class,
*				 the Sorted Link List class, and the
*				 List Analysis class.
*
*    Associated
*		   files: BasicLinkList.h
*				  SortedLinkList.h
*				  ListAnalysis.h
*
*       Code by: Craig Medlin
* Last Modified: Nov. 27, 2014
*
*        Course: COSC 1437-P70 — M 6-9:45 p.m.
*     Professor: Charles Braun
*/

#include "BasicLinkList.h"		// For Basic Link List class
#include "SortedLinkList.h"		// For Sorted Link List class
#include "ListAnalysis.h"		// For List Analysis class
#include "GenValue.h"			// For data population
#include <stdlib.h>				// For exit function
#include <iostream>				// For output operations (cout)
using namespace std;

// Forward declarations (function prototypes)
void showWelcome();
void showMenu();
void testBasicList();
void testSortedList();
void testListAnalysis();
void testAllLinkedLists();
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
		<< "the implementation and operation of classes related to\n"
		<< "linked lists. These include a Basic Link List class,\n"
		<< "Sorted Link List class, and List Analysis class.\n"
		<< "Code by: Craig Medlin\n"
		<< "Last modified: Nov. 27, 2014\n"
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
			<< "1. Demonstrate BasicLinkList class \n"
			<< "2. Demonstrate SortedLinkList class \n"
			<< "3. Demonstrate ListAnalysis class \n"
			<< "4. Demonstrate all linked list classes\n"
			<< "5. Display program information\n"
			<< "6. Exit the program \n\n"
			<< "Your selection: ";

		cin >> menuSelection;

		cout << "\n\n";

		switch (menuSelection)
		{
		case 1:
			testBasicList();
			pressEnterToContinue();
			break;

		case 2:
			testSortedList();
			pressEnterToContinue();
			break;

		case 3:
			testListAnalysis();
			pressEnterToContinue();
			break;

		case 4:
			testAllLinkedLists();
			break;

		case 5:
			showWelcome();
			break;

		case 6:
			exit(EXIT_SUCCESS);
			break;

		default:
			cout << "Please enter a valid menu selection \n\n";
			pressEnterToContinue();
			break;
		}

	} while (menuSelection != 6);
}

// Function to test Basic Link List class
void testBasicList()
{
	// Seed random number generator
	srand(static_cast<int>(time(NULL)));

	// Inform user of testing
	cout << "***********************************************\n"
		<< "********************TESTING********************\n"
		<< "***********************************************\n\n\n";

	cout << "We will now test the Basic Link List class.\n"
		<< "We will start by creating a new Basic Link List and\n"
		<< "populating it with 50 random integers between 30 and 95.\n"
		<< "This operation will also test the Append function of\n"
		<< "the class.\n\n\n";

	// Pause for keypress
	pressEnterToContinue();

	// Create new linked list
	BasicLinkList<int> basicList;

	cout << "*** New BasicLinkList<int> created successfully\n";

	// Variable to hold random values
	int value = 0;

	// Populate list with random values
	for (int index = 0; index < 50; index++)
	{
		// Store generated value
		value = GenValue(30, 95);
		
		// Append generated value
		basicList.append(value);

		// Display confirmation to user
		cout << "*** " << value << " appeneded to BasicLinkList<int>\n";
	}

	// Pause for keypress
	pressEnterToContinue();

	cout << "\n\nTo verify the success of the list creation,\n"
		<< "we will now display the entire list in rows of 10.\n"
		<< "Please verify that the values match those presented\n"
		<< "when the list was created.\n\n";

	// Test printList function
	basicList.printList();

	cout << endl;

	// Pause for keypress
	pressEnterToContinue();

	cout << "\n\nWe will now remove the first node in the list.\n\n";

	// Test removeFront function
	basicList.removeFront();

	cout << "*** First node removed\n";
	cout << "*** NEW LIST: \n";

	// Test printList function
	basicList.printList();

	cout << endl;

	// Pause for keypress
	pressEnterToContinue();

	cout << "\n\nWe will now remove the last node in the list.\n\n";

	// Test removeBack function
	basicList.removeBack();

	cout << "*** Last node removed\n";
	cout << "*** NEW LIST: \n";

	// Test printList function
	basicList.printList();

	cout << endl;

	// Pause for keypress
	pressEnterToContinue();

	// Set new value to be added
	value = GenValue(30, 95);

	cout << "\n\nWe will now add a value to the beginning of the list.\n"
		<< "The value to be added is: " << value << endl;

	// Test prepend function
	basicList.prepend(value);

	cout << "*** " << value << " added to front of linked list\n";
	cout << "*** NEW LIST: \n";

	// Test printList function
	basicList.printList();

	cout << endl;

	// Pause for keypress
	pressEnterToContinue();

	cout << "\n\nWe will now clear the list completely.\n\n";

	// Test clearList function
	basicList.clearList();

	// Test printList function with empty list
	basicList.printList();

	cout << "\n\n\nWe have finished testing the BasicLinkList class.\n\n";

}

void testSortedList()
{
	// Seed random number generator
	srand(static_cast<int>(time(NULL)));

	// Inform user of testing
	cout << "***********************************************\n"
		<< "********************TESTING********************\n"
		<< "***********************************************\n\n\n";

	cout << "We will now test the Sorted Linked List class.\n"
		<< "First, we will create a new sorted list and populate\n"
		<< "it with values. The values are to be generated randomly\n"
		<< "and the Sorted Linked List object will automatically\n"
		<< "sort the nodes as needed.\n\n";

	// Create new sorted list
	SortedLinkList<int> sortedList;

	// Variable to hold random values
	int value = 0;

	// Generate and store values in the list
	for (int index = 0; index < 50; index++)
	{
		// Generate value
		value = GenValue(30, 95);
		
		// Insert value as new node
		sortedList.insertNode(value);

		// Display stored value for testing
		cout << value << " stored in SortedLinkList<int>\n";

	}

	cout << endl;

	// Pause for keypress
	pressEnterToContinue();

	cout << "\nLet's print the list to make sure it sorted the values:\n\n";

	// Test printList function
	sortedList.printList();

	cout << endl;

	// Pause for keypress
	pressEnterToContinue();

	cout << "\nWe will now test the deleteNode function.\n"
		<< "We will use it to remove the last added node,\n"
		<< "which has a value of " << value << ".\n\n";

	// Delete the last added value
	sortedList.deleteNode(value);

	// Test printList function
	sortedList.printList();

	cout << endl;

	// Pause for keypress
	pressEnterToContinue();

	// Generate new value to be added
	value = GenValue(30, 95);

	cout << "\nWe will now insert a new value into the\n"
		<< "linked list and verify that it is placed in the\n"
		<< "correct position.\nThe value to be added is " << value << ".\n";

	// Insert new value
	sortedList.insertNode(value);
	
	cout << "\nThe new linked list is:\n\n";

	// Test printList function
	sortedList.printList();

	cout << "\n\nWe are now finished testing the Sorted Link List class.\n";
}

void testListAnalysis()
{
	// Seed random number generator
	srand(static_cast<int>(time(NULL)));

	// Inform user of testing
	cout << "***********************************************\n"
		<< "********************TESTING********************\n"
		<< "***********************************************\n\n\n";

	cout << "\nWe will now test the ListAnalysis class.\n"
		<< "This class will allow us to analyze information\n"
		<< "regarding our linked list.\n\n"
		<< "We will start be creating a new linked list and\n"
		<< "populating it with randomly generated values.\n\n";

	
	// Create new ListAnalysis object
	ListAnalysis<int> list;

	// Display confirmation
	cout << "***New ListAnalysis<int> linked list created***\n\n";

	// Wait for keypress to continue
	pressEnterToContinue();

	// Variable to hold random value
	int value = 0;

	cout << "The values being added to the list are:\n";

	// Populate list with data
	for (int index = 0; index < 10; index++)
	{
		for (int count = 0; count < 10; count++)
		{
			// Generate random value
			value = GenValue(30, 95);

			// Add node to list
			list.newNode(value);

			// Display added value
			cout << value << " ";
		}

		cout << endl;
	}

	cout << endl;

	// Wait for keypress
	pressEnterToContinue();
	
	cout << "\nThe now sorted data looks like this:\n";

	// Test printList function
	list.printList();

	cout << endl;

	// Wait for keypress
	pressEnterToContinue();

	cout << "\nWe will now test several functions that\n"
		<< "will allow us to analyze the data set.\n\n";

	// Test analysis functions
	cout << "getCount: " << list.getCount();
	cout << "\ngetHighValue: " << list.getHighValue();
	cout << "\ngetLowValue: " << list.getLowValue();
	cout << "\ngetAverage: " << list.getAverage();
	cout << "\ngetMedian: " << list.getMedian();
	cout << "\ngetMode: " << list.getMode();

	cout << "\n\nWe are now finished testing the ListAnalysis class.\n"
		<< "Please verify the data generated from the above functions\n"
		<< "by reviewing the dataset displayed above.\n\n";
}

void testAllLinkedLists()
{
	testBasicList();
	testSortedList();
	testListAnalysis();
}

// Function to pause until user presses ENTER
void pressEnterToContinue()
{

	cin.sync();
	cout << "Press ENTER to continue... " << flush;
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	cout << "\n";

} /* PRESS_ENTER_TO_CONTINUE */