/***************************************************
 ******** EOC - Part D: Indexed Vendor List ********
 ***************************************************
 *
 *      Filename: VendorList.h
 *   Description: The VendorList class is designed
 *				  to store an indexed linked list
 *				  of data relating to a vendor list.
 *
 *    Associated
 *		   files: VendorList.cpp
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 29, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#ifndef VENDORLIST_H
#define VENDORLIST_H

#include "Vendor.h"			// For Vendor class
#include <string>

using namespace std;

// Forward declarations
struct RecordNode;

struct IndexNode
{
	std::string state;
	IndexNode *nextIndex;
	RecordNode *firstRecord;
};

struct RecordNode
{
	Vendor record;
	RecordNode *nextRecord;
};

class VendorList
{
private:	
	IndexNode *head;

	bool isValidFile(std::string);

public:
	/* Constructor*/
	VendorList();

	/* Destructor */
	~VendorList();

	/* Member functions */
	void buildList(std::string);
	void insertIndexNode(std::string);
	void insertRecordNode(int, std::string, std::string, std::string, std::string);
	Vendor* getVendorRecord(int);
	void listRecords(std::string);
	void listAllRecords();

};

#endif