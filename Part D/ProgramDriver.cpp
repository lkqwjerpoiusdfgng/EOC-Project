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
 * Last Modified: Nov. 28, 2014
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

void testIndexedList()
{
	// Create new VendorList object
	VendorList vList;

	cout << "\n***New VendorList object created!\n";
	
	cout << "\nWe will first attempt to read in the vendor data from a source file.\n";
	cout << "The source file is called \"Vendor List File.txt\"\n\n";

	vList.buildList("Vendor List File.txt");
	
	// Pause for user to press enter
	pressEnterToContinue();
	cout << endl;

	// List all sorted records
	vList.listAllRecords();
	cout << endl;

	// Pause for user to press enter
	pressEnterToContinue();
	cout << endl;

	// List all records from California
	vList.listRecords("CA");
	cout << endl;

	// Pause for user to press enter
	pressEnterToContinue();
	cout << endl;

	// Variable to point to vendor object from search
	Vendor *search;

	// Attempt to locate a particular vendor record
	search = vList.getVendorRecord(12);

	// Display results of search
	cout << search->getID() << "\t" << search->getName() << "\t" << search->getCity() << "\t" << search->getState() << "\t" << search->getZipCode() << endl;

	// Pause for user to press enter
	pressEnterToContinue();
	cout << endl;

}

// Function to pause until user presses ENTER
void pressEnterToContinue()
{

	cin.sync();
	cout << "Press ENTER to continue... " << flush;
	cin.ignore(numeric_limits <streamsize> ::max(), '\n');
	cout << "\n";

} /* PRESS_ENTER_TO_CONTINUE */