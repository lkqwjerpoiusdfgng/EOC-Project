/***************************************************
 ******** EOC - Part D: Indexed Vendor List ********
 ***************************************************
 *
 *      Filename: Vendor.cpp
 *   Description: The Vendor class is designed
 *				  to store information relating
 *				  to a particular vendor. This class
 *				  was specifically designed to work
 *				  in conjunction with a linked list
 *				  (see VendorList.h).
 *
 *
 *    Associated
 *		   files: Vendor.h		// Class header
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 29, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#include "Vendor.h"
#include <string>

/* CONSTRUCTORS */

Vendor::Vendor()
{
	id = 0;
}

Vendor::Vendor(int vID, std::string vName, std::string vCity, std::string vState, std::string vZip)
{
	id = vID;
	name = vName;
	city = vCity;
	state = vState;
	zipCode = vZip;
}


/* DESTRUCTOR */

Vendor::~Vendor()
{

}


/* PRIVATE FUNCTIONS */
bool Vendor::isValidZip(int testZip)
{
	int digits = 0;
	
	if (testZip < 0) 
	{
		return false;
	}

	while (testZip) {
		testZip /= 10;
		digits++;
	}
	
	return digits == 5;
}

/* MEMBER FUNCTIONS */

bool Vendor::setID(int nID)
{
	if (nID != 0) 
	{
		id = nID;
		return true;
	}
	else
	{
		throw "ERROR: Invalid vendor ID!";
		return false;
	}
}

bool Vendor::setName(std::string nName)
{
	if (!nName.empty())
	{
		name = nName;
		return true;
	}
	else
	{
		throw "ERROR: Invalid vendor name!";
		return false;
	}
}

bool Vendor::setCity(std::string nCity)
{
	if (!nCity.empty())
	{
		city = nCity;
		return true;
	}
	else
	{
		throw "ERROR: Invalid vendor city!";
		return false;
	}
}

bool Vendor::setState(std::string nState)
{
	if (!nState.empty())
	{
		state = nState;
		return true;
	}
	else
	{
		throw "ERROR: Invalid vendor state!";
		return false;
	}
}

bool Vendor::setZipCode(std::string nZip)
{
	if (!nZip.empty())
	{
		zipCode = nZip;
		return true;
	}
	else
	{
		throw "ERROR: Invalid vendor zip code!";
		return false;
	}
}