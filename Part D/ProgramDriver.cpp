/***************************************************
 ******** EOC - Part D: Indexed Vendor List ********
 ***************************************************
 *
 *      Filename: ProgramDriver.cpp
 *   Description: This program will test the implementation
 *				  of the VendorList class, which is
 *				  designed to read a vendor list and store 
 *				  the data in an indexed linked list.
 *
 *    Associated
 *		   files: VendorList.h		// VendorList class
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 30, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#include <iostream>			// For cout
#include "VendorList.h"		// For VendorList class
#include <stdlib.h>			// For exit() function
using namespace std;

// Forward declarations
void showWelcome();
void showMenu();
void testIndexedList();
void pressEnterToContinue();

// Program's main function
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
		<< "the implementation of an Indexed Vender List.\n"
		<< "Code by: Craig Medlin\n"
		<< "Last modified: Nov. 29, 2014\n"
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
			<< "1. Demonstrate Indexed Vendor List\n"
			<< "2. Display program information\n"
			<< "3. Exit the program \n\n"
			<< "Your selection: ";

		cin >> menuSelection;

		cout << "\n\n";

		switch (menuSelection)
		{
		case 1:
			testIndexedList();
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


// Function to test the indexed vendor list
void testIndexedList()
{
	// Create new VendorList object
	VendorList vList;

	// Inform user that object was created
	cout << "\n***New VendorList object created!\n";
	

	// Alert to testing process
	cout << "\nWe will first attempt to read in the vendor data from a source file.\n";
	cout << "The source file is called \"Vendor List File.txt\"\n\n";

	// Build the list from the source file
	vList.buildList("Vendor List File.txt");

	// Pause for user to press enter
	pressEnterToContinue();
	cout << endl;

	// Test listAllRecords() function
	vList.listAllRecords();
	cout << endl;

	// Pause for user to press enter
	pressEnterToContinue();
	cout << endl;

	// Alert to next test
	cout << "\nWe will now test the listRecords() function to show all records\n"
		<< "for vendors within the state of California.\n\n";

	// Test ListRecords() function
	vList.listRecords("CA");
	cout << endl;

	// Pause for user to press enter
	pressEnterToContinue();
	cout << endl;

	// Alert to final test
	cout << "\nWe will now test the getVendorRecord() function to locate and display\n"
		<< "the vendor record held for a given vendor ID. For this test, we will\n"
		<< "be searching for vendor ID: 12.\n\n";

	// Attempt to locate a particular vendor record
	Vendor &search = vList.getVendorRecord(12);

	// Display results
	vList.printHeaders();
	cout << search;
	cout << "\n\n\n";

	cout << "We are now finished testing the VendorList class.\n\n";

}

// Function to pause until user presses ENTER
void pressEnterToContinue()
{

	cin.sync();
	cout << "Press ENTER to continue... " << flush;
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	cout << "\n";

} /* PRESS_ENTER_TO_CONTINUE */