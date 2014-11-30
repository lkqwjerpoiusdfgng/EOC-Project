/***************************************************
 ******** EOC - Part D: Indexed Vendor List ********
 ***************************************************
 *
 *      Filename: VendorList.cpp
 *   Description: The VendorList class is designed
 *				  to store an indexed linked list
 *				  of data relating to a vendor list.
 *
 *    Associated
 *		   files: VendorList.h		// Class header
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 29, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#include "VendorList.h"		// Class header
#include <fstream>			// For reading from files
#include <sstream>			// For string stream
#include <iostream>			// For output (cout)
#include <string>			// For String class
#include <iomanip>			// For setw()

/* CONSTRUCTOR */
VendorList::VendorList()
{
	head = nullptr;
}


/* DESTRUCTOR */
VendorList::~VendorList()
{
	IndexNode *indexPtr;	// Used to navigate index lsit
	IndexNode *nextIndex;	// Stores next index node

	RecordNode *recPtr;	// Used to navigate record list
	RecordNode *nextRecord;	// Stores next record node

	// Start at top of list
	indexPtr = head;

	// Delete nodes while they exist
	while (indexPtr != nullptr)
	{
		// Store next node
		nextIndex = indexPtr->nextIndex;

		// Store first record
		recPtr = indexPtr->firstRecord;

		// Check for any records in current index
		while (recPtr != nullptr)
		{
			// Set next record
			nextRecord = recPtr->nextRecord;

			// Delete current record
			delete recPtr;

			// Move to next record
			recPtr = nextRecord;
		}

		// Delete current index
		delete indexPtr;

		// Move to next index
		indexPtr = nextIndex;
	}

	// Reset head
	head = nullptr;
}

/* PRIVATE FUNCTIONS */
bool VendorList::isValidFile(std::string line)
{
	/* CONSTANTS for testing */
	std::string const ID = "VendorID";
	std::string const NAME = "Vendor Name";
	std::string const CITY = "Vendor City";
	std::string const STATE = "VendorState";
	std::string const ZIP = "VendorZipCode";

	/* Variables to store respective headings */
	std::string fID;
	std::string fName;
	std::string fCity;
	std::string fState;
	std::string fZip;

	std::string tempN; // String to concatenate with fName
	std::string tempC; // String to concatenate with fCity

	// Flag for if file is valid
	bool isValid = false;
	
	// Create stream object
	std::istringstream ss(line);

	// Read line into variables
	ss >> fID >> fName >> tempN >> fCity >> tempC >> fState >> fZip;

	// Concatenate variables
	fName += (" " + tempN);
	fCity += (" " + tempC);

	// Compare variables to knowns
	if (fID == ID && fName == NAME)
	{
		if (fCity == CITY && fState == STATE)
		{
			if (fZip == ZIP)
			{
				isValid = true;
			}
		}
	}

	// Return file validity
	return isValid;
}

/* MEMBER FUNCTIONS */
void VendorList::buildList(std::string filename)
{
	// Create file object
	std::ifstream vList;

	std::cout << "***Creating ifstream object\n";

	// Open file
	vList.open(filename);

	if (vList.is_open())
	{
		std::cout << "***Opening " << filename << endl;

		// String to hold line
		std::string line;

		// Expecting two blank lines before header
		for (int i = 0; i < 2; i++)
		{
			getline(vList, line);
		}

		std::cout << "***Verifying file is in expected format\n";

		getline(vList, line);

		// Check if file has expected header info
		if (isValidFile(line))
		{
			std::cout << "***File formatted as expected\n";

			// Skip a line for expected dashes under header
			getline(vList, line);

			// While records exist
			while (getline(vList, line))
			{
				// Temporary variables to hold vendor information
				string record[5];

				record[0] = line.substr(0, 11);		// Vendor ID
				record[1] = line.substr(12, 32);	// Vendor Name
				record[2] = line.substr(45, 16);	// Vendor City
				record[3] = line.substr(62, 11);	// Vendor State
				record[4] = line.substr(74, 5);		// Vendor Zip Code

				// Trim strings
				for (int i = 0; i < 5; i++)
				{
					record[i] = record[i].erase(record[i].find_last_not_of(" \n\r\t") + 1);
				}

				

				// Create vendor record
				insertRecordNode(std::stoi(record[0]),record[1],record[2],record[3],record[4]);

				std::cout << "***New record stored!\n";
			}
		}
		else
		{
			// Alert user that file was not in expected format
			std::cout << "ERROR: File not in expected format!\n";
		}

		vList.close();
	}
	else
	{
		std::cout << "***ERROR: File could not be opened!\n";
	}

}


void VendorList::insertIndexNode(std::string nIndex)
{
	// Verify pased string
	if (nIndex.empty())
	{
		throw "ERROR: Invalid index name provided!";
		return;
	}
	
	// Allocate new index
	IndexNode *newIndex = new IndexNode;
	newIndex->state = nIndex;
	newIndex->nextIndex = nullptr;
	newIndex->firstRecord = nullptr;
	
	// Check if there are any index nodes yet
	if (head == nullptr)
	{
		// Set new index to head
		head = newIndex;
	}
	else
	{
		// Pointers used for traversing index nodes
		IndexNode *prevIndex = nullptr;
		IndexNode *currIndex;

		// Start at head
		currIndex = head;

		// While new index is less than current index (i.e. closer to 'z')
		while (currIndex != nullptr && nIndex < currIndex->state)
		{
			// Set previous index to current index
			prevIndex = currIndex;

			// Set current index to next index
			currIndex = currIndex->nextIndex;
		}

		// Check if the index already exists
		if (currIndex != nullptr && nIndex == currIndex->state)
		{
			throw "ERROR: Index already exists!";
		}
		// Place the new index
		else
		{
			// Set the previous node's nextIndex pointer to the new index
			prevIndex->nextIndex = newIndex;

			// Set the new node's nextIndex pointer to the current index
			newIndex->nextIndex = currIndex;
		}
	}
}

void VendorList::insertRecordNode(int vID, std::string vName, std::string vCity, std::string vState, std::string vZip)
{
	// Variables
	RecordNode *newRecord;				// Holds new record node
	IndexNode *currIndex;				// Used to traverse index
	IndexNode *prevIndex = nullptr;		// Used to hold previous index
	RecordNode *currRecord;				// Used to traverse records
	RecordNode *prevRecord = nullptr;	// Used to store previous record

	// Set data for new record
	newRecord = new RecordNode;

	newRecord->record.setID(vID);		// Set ID
	newRecord->record.setName(vName);	// Set name
	newRecord->record.setCity(vCity);	// Set city
	newRecord->record.setState(vState);	// Set state
	newRecord->record.setZipCode(vZip);	// Set zip code

	newRecord->nextRecord = nullptr;

	// Locate appropriate index node

	// Start at head
	currIndex = head;

	if (head == nullptr)
	{
		// Create new index
		insertIndexNode(vState);

		// Set current index to head
		currIndex = head;
	}
	else
	{
		// While new index is less than current index (i.e. closer to 'z')
		while (currIndex != nullptr && vState < currIndex->state)
		{
			// Set previous index to current index
			prevIndex = currIndex;

			// Set current index to next index
			currIndex = currIndex->nextIndex;
		}

		// Create new index if necessary
		if (currIndex == nullptr || vState != currIndex->state)
		{
			// Create new index
			insertIndexNode(vState);

			// Adjust pointer to new index node
			currIndex = prevIndex->nextIndex;
		}
	}
	

	// Check if records exist
	if (currIndex->firstRecord == nullptr)
	{
		currIndex->firstRecord = newRecord;
	}
	else
	{
		// Start at first record
		currRecord = currIndex->firstRecord;

		// While record exists and new vendor name is closer to 'z', advance record
		while (currRecord != nullptr && vName < currRecord->record.getName())
		{
			prevRecord = currRecord;
			currRecord = currRecord->nextRecord;
		}

		// Insert new record
		if (prevRecord != nullptr) { prevRecord->nextRecord = newRecord; }
		newRecord->nextRecord = (currRecord != nullptr ? currRecord : nullptr);
	}
	
}

Vendor* VendorList::getVendorRecord(int vID)
{
	// Variables
	IndexNode *currIndex;					// To traverse index nodes
	RecordNode *currRecord = nullptr;		// To traverse record nodes
	Vendor *vRecord = nullptr;				// To copy data from record
	bool found = false;						// Flag for if record was found


	// Start at head
	currIndex = head;

	// Verify indices exist
	if (head == nullptr)
	{
		throw "ERROR: No index of records exists!";
	}
	else
	{
		// While index exists
		while (currIndex != nullptr)
		{
			// Start at first record
			currRecord = currIndex->firstRecord;

			// While records exist
			while (currRecord != nullptr)
			{
				// See if we've found the matching record
				if (vID == currRecord->record.getID())
				{
					// Copy record data
					vRecord = new Vendor(currRecord->record);
					found = true;
					return vRecord;
				}
				else
				{
					// Move to next record
					currRecord = currRecord->nextRecord;
				}
			} // RECORD LOOP

			// Advance to next index node
			currIndex = currIndex->nextIndex;

		} // INDEX LOOP
	}

	// Exception if no record found
	if (!found)
	{
		throw "ERROR: No record found for that vendor ID!";
	}

	return vRecord;
}

void VendorList::listRecords(std::string state)
{
	IndexNode *currIndex;
	RecordNode *currRecord = nullptr;

	// Start at head
	currIndex = head;

	// Verify nodes exist
	if (head == nullptr)
	{
		std::cout << "ERROR: The index is empty!\n";
		return;
	}
	else
	{
		// Traverse index while nodes exist and match isn't found
		while (currIndex != nullptr && currIndex->state != state)
		{
			// Advance to next index node
			currIndex = currIndex->nextIndex;
		}

		// Verify records exist
		if (currIndex == nullptr || currIndex->state != state)
		{
			std::cout << "ERROR: No records were found for " << state << "!\n";
		}
		else
		{
			// Start at first record
			currRecord = currIndex->firstRecord;

			if (currRecord == nullptr)
			{
				std::cout << "No records exist for " << state << "!\n";
			}
			else
			{
				// Print table header
				std::cout << "Vendor records found for " << state << endl;
				std::cout << "ID\tName\tCity\tState\tZip Code\n";

				// While records exist
				while (currRecord != nullptr)
				{
					// Print current record
					std::cout << currRecord->record;
					std::cout << endl;

					// Advance to next record
					currRecord = currRecord->nextRecord;
				}
			}
		}
	}

}


void VendorList::listAllRecords()
{
	// Variables
	IndexNode *currIndex;		// Points to current index
	RecordNode *currRecord;		// Points to current record

	// Start at head
	currIndex = head;
	currRecord = nullptr;

	// Check if index exists
	if (head == nullptr)
	{
		std::cout << "Index does not exist!\n";
		return;
	}

	// While index nodes exists
	while (currIndex != nullptr)
	{

		// Print table header
		std::cout << "Results from index node for " << currIndex->state << endl;
		std::cout << std::setw(11) << left << "VendorID";
		std::cout << std::setw(32) << left << "Vendor Name";
		std::cout << std::setw(16) << left << "Vendor City";
		std::cout << std::setw(11) << left << "State";
		std::cout << std::setw(7) << left << "ZipCode" << endl;

		std::cout << std::setfill('-') << std::setw(77) << "-" << endl;

		std::cout << std::setfill(' ');

		// Start at first record
		currRecord = currIndex->firstRecord;

		// While records exist
		while (currRecord != nullptr)
		{
			// Print records
			std::cout << currRecord->record;
			std::cout << endl;

			// Advance to next record
			currRecord = currRecord->nextRecord;
		}

		std::cout << endl;

		// Advance to next index node
		currIndex = currIndex->nextIndex;
	}
}


// Overloaded  output operator
ostream& operator<<(ostream& out, const Vendor &vRecord)
{
	out << std::setw(11) << left << vRecord.id;
	out << std::setw(32) << left << vRecord.name; 
	out << std::setw(16) << left << vRecord.city;
	out << std::setw(11) << left << vRecord.state; 
	out << std::setw(7)  << left << vRecord.zipCode;
	return out;
}