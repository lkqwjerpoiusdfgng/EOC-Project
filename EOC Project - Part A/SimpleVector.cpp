/***************************************************
********** EOC - Part A: Vector Template **********
***************************************************
*
*      Filename: SimpleVector.cpp
*   Description: The SimpleVector class is a template
*                class designed to emulate certain
*                features of the STL <vector> and
*                demonstrate template classes/functions.
*
*    Associated
*		   files: SimpleVector.h		// Template class header
*
*       Code by: Craig Medlin
* Last Modified: Nov. 23, 2014
*
*        Course: COSC 1437-P70 — M 6-9:45 p.m.
*     Professor: Charles Braun
*/

#include <iostream>
#include <new>       // For bad_alloc exception
#include <cstdlib>   // Needed for the exit function

using namespace std;

#include "SimpleVector.h"

/* Constructors */

//***********************************************************
//  Constructor for the SimpleVector class. It receives an  *
//  int argument, sets the initial size of the array and.   *
//  attempts to allocate memory for it.                     *
// **********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int size)
{
	// Set initial size
	arraySize = size;

	// Attempt memory allocation
	try
	{
		// Create array of initial size
		aptr = new T[size];
	}
	// Catch allocation error
	catch (bad_alloc)
	{
		// Call function to handle memory error
		memError();
	}

	// Set capacity of current vector
	capacity = arraySize;

	// Initialize the array as NULL
	for (int index = 0; index < arraySize; index++)
	{
		// Since memory locations are sequential for
		// aptr's elements, dereference aptr at each
		// offset to access each element and set to 0.

		*(aptr + index) = NULL;
	}
}

//***********************************************************
//  Copy constructor for SimpleVector class.                *
// **********************************************************    

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &origVec)
{
	// Copy the original vector's size
	this->arraySize = origVec.arraySize;

	// Allocate memory for new array at size of original
	this->aptr = new T[this->arraySize];

	// Check for error in allocation
	if (this->aptr == 0)
	{
		// Call function to handle memory error
		this->memError();
	}

	// Set capacity of current vector
	this->capacity = this->arraySize;

	// Loop to copy elements of originalVector to new vector
	for (int index = 0; index < this->arraySize; index++)
	{
		*(aptr + count) = *(origVec.aptr + count);
	}
}

/* Destructor */

//***********************************************************
//  Destructor for SimpleVector class to deallocate memory. *
// ********************************************************** 

template <class T>
SimpleVector<T>::~SimpleVector()
{
	// Check if the vector was used
	if (arraySize > 0)
	{
		// Delete allocated memory
		delete[] this->aptr;
	}
}

/* Private functions */

//***********************************************************
// memError function: Displays error message and terminates *
// the program if memory allocation fails.                  *
// ********************************************************** 

template <class T>
void SimpleVector<T>::memError()
{
	cout << "ERROR: The program was unable to allocate memory." << endl;
	exit(EXIT_FAILURE);
}

//***********************************************************
// subError function: Displays error message and terminates *
// the program if subscript is out of range.                *
// ********************************************************** 

template <class T>
void SimpleVector<T>::subError()
{
	cout << "ERROR: Subscript out of range." << endl;
	exit(EXIT_FAILURE);
}

//***************************************************************
// getNewAllocationSize function: Calculates size to reallocate *
// vector to based on predetermined exponential algorithm		*
// to avoid inefficiently copying entire aray for each new		*
// reallocation. Accepts no arguments.							*
// ************************************************************** 

template <class T>
int SimpleVector<T>::getNewAllocationSize()
{
	int newSize = 0;		// Holds new allocation size

	newSize = (this->arraySize < this->MAX_EXPANSION_AMOUNT) ? (2 * this->arraySize) | (this->arraySize + this->MAX_EXPANSION_AMOUNT);
	return newSize;
}


/* Member functions */

//***********************************************************
// Overloaded subscript [] operator. This function accepts  *
// an int argument that is the subscript being called. The  *
// returned element is not editable.						*
// **********************************************************

template <class T>
T SimpleVector<T>::operator[] (int sub)
{
	// Decision structure to verify element is within bounds
	if (sub < 0 || sub >= this->arraySize)
	{
		subError();
	}

	// Return the called element
	return aptr[sub];
}

//***********************************************************
// Overloaded subscript [] operator. This function accepts  *
// an int argument that is the subscript being called. The  *
// returned element is editable.							*
// **********************************************************

template <class T>
T& SimpleVector<T>::operator[] (int sub)
{
	// Decision structure to verify element is within bounds
	if (sub < 0 || sub >= this->arraySize)
	{
		subError();
	}

	// Return the editable called element
	return *(aptr + sub);
}

//***********************************************************
// push_back function: Receives a new element of type T to  *
// be added to end of vector.                               *
// **********************************************************

template <class T>
bool SimpleVector<T>::push_back(T newElement)
{
	// Check if vector has proper capacity
	if (this->capacity <= this->arraySize)
	{
		// Attempt to grow vector
		if (!this->growVector())
		{
			return false;
		}
	}
	else
	{
		// Store new element at end of vector
		*(aptr + arraySize - 1) = newElement;

		// Increment arraySize variable
		this->arraySize++;
		return true;
	}
}

//************************************************************
// pop_back function: Deletes the last element in the vector * 
// ***********************************************************

template <class T>
bool SimpleVector<T>::pop_back()
{

}