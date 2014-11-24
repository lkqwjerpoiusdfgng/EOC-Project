/***************************************************
 ********** EOC - Part A: Vector Template **********
 ***************************************************
 *
 *      Filename: SimpleVector.h
 *   Description: The SimpleVector class is a template
 *                class designed to emulate certain
 *                features of the STL <vector> and 
 *                demonstrate template classes/functions.
 *
 *    Associated
 *		   files:
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 23, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

#include <iostream>
#include <new>       // For bad_alloc exception
#include <cstdlib>   // Needed for the exit function

using namespace std;

template <class T>
class SimpleVector
{
private:
    
    /* Variables */ 
    T *aPtr;            // Points to the array that is holding data
    int arraySize;      // Holds size of current vector
	int vectorCapacity;	// Holds capacity of current vector
    int timesGrown;     // Holds number of times the vector has been grown
   
    /* Functions */
    void memError();						// Called in the event of memory allocation error
    void subError() const;					// Called in the event of subscript access error
	bool growVector();						// Function increases the size of the current vector
	bool isValidSubscript(int) const;		// Function returns whether subscript is valid for current vector
	int getNewAllocationSize() const;		// Function returns new vector capacity based on exponential  
											//		algorithm to maintain efficiency over standard array

public:
    
	/* Static Constants */
		static const int MAX_EXPANSION_AMOUNT = 150;	// Stores maximum capacity increase on reallocation

    /* Constructors */

        // Default constructor
        SimpleVector()
            { aPtr = nullptr; arraySize = 0; vectorCapacity = 0; }

        // Parameterized constructor accepting int value for initial size
        SimpleVector(int);

        // Copy constructor
        SimpleVector(const SimpleVector &);

    /* Destructor */

        ~SimpleVector();

    /* Member functions */

		
		/* OVERLOADED OPERATORS */

		T operator[] (const int) const;			// Subscript operator for noneditable element
        T& operator[] (const int);				// Subscript operator for editable element


		/* ACCESSOR FUNCTIONS */

		int size() const				// Returns size of array
			{ return arraySize;	}

		int capacity() const			// Returns capacity of array
			{ return vectorCapacity; }

		T getElement(const int) const;	// Returns a specific element

		T front() const					// Returns first element in vector
			{ return aPtr[0]; }

		T back() const					// Returns the last element in vector
			{ return aPtr[arraySize - 1]; }

        
		/* MODIFIERS */

        bool push_back(T);	// Adds element onto end of vector
        bool pop_back();	// Deletes element at end of vector
};


/* Constructors */

//***********************************************************
//  Constructor for the SimpleVector class. It receives an  *
//  int argument, sets the initial size of the array and.   *
//  attempts to allocate memory for it.                     *
// **********************************************************

template <class T>
SimpleVector<T>::SimpleVector(int size)
{
	// Set capacity of current vector
	vectorCapacity = size;
	arraySize = 0;

	// Attempt memory allocation
	try
	{
		// Create array of initial size
		aPtr = new T[size];
	}
	// Catch allocation error
	catch (bad_alloc)
	{
		// Call function to handle memory error
		memError();
	}

	// Initialize the array as NULL
	for (int index = 0; index < arraySize; index++)
	{
		// Since memory locations are sequential for
		// aPtr's elements, dereference aPtr at each
		// offset to access each element and set to 0.

		*(aPtr + index) = NULL;
	}
}

//***********************************************************
//  Copy constructor for SimpleVector class.                *
// **********************************************************    

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &origVec)
{
	// Copy the original vector's size
	arraySize = origVec.size();

	// Allocate memory for new array at size of original
	aPtr = new T[arraySize];

	// Check for error in allocation
	if (aPtr == 0)
	{
		// Call function to handle memory error
		memError();
	}

	// Set capacity of current vector
	vectorCapacity = arraySize;

	// Loop to copy elements of originalVector to new vector
	for (int index = 0; index < arraySize; index++)
	{
		aPtr[index] = origVec.getElement(index);
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
		delete[] aPtr;
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
void SimpleVector<T>::subError() const
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
int SimpleVector<T>::getNewAllocationSize() const
{
	int newSize = 0;		// Holds new allocation size

	// Set new vector size using simple double size algorithm
	// with limit at MAX_EXPANSION_AMOUNT
	newSize =
		((vectorCapacity < MAX_EXPANSION_AMOUNT) ?
		(2 * vectorCapacity) : (vectorCapacity + MAX_EXPANSION_AMOUNT));
	return newSize;
}

//***********************************************************
// isValidSubscript function: Checks if subscript provided  *
// exists within the current vector.		                *
// ********************************************************** 

template <class T>
bool SimpleVector<T>::isValidSubscript(int sub) const
{
	// Decision structure to verify element is within bounds
	return (sub >= 0 && sub < vectorCapacity);
}

template <class T>
bool SimpleVector<T>::growVector()
{
	if (aPtr == nullptr || (arraySize == 0 && vectorCapacity == 0))
	{
		aPtr = new T[5];
		arraySize = 0;
		vectorCapacity = 5;
		return true;
	}
	else if (arraySize == 0 && vectorCapacity != 0)
	{
		return false;
	}
	else
	{
		// Copy elements to placeholder
		SimpleVector<T> temp(*this);

		// Delete stored data
		delete[] aPtr;

		// Prepare to reallocate
		int newAllocation = getNewAllocationSize();

		// Reallocate
		aPtr = new T[newAllocation];

		// Set new capacity
		vectorCapacity = newAllocation;

		// Reset array size
		arraySize = 0;

		// Copy stored elements to new array
		for (int index = 0; index < temp.size(); index++)
		{
			aPtr[index] = temp[index];
			arraySize++;
		}

		return true;
	}
}


/* Member functions */

//***********************************************************
// Overloaded subscript [] operator. This function accepts  *
// an int argument that is the subscript being called. The  *
// returned element is not editable.						*
// **********************************************************

template <class T>
T SimpleVector<T>::operator[] (int sub) const
{
	// Check if subscript is valid
	if (!isValidSubscript(sub))
	{
		subError();
		return NULL;
	}
	else
	{
		// Return the called element
		return aPtr[sub];
	}
}

//***********************************************************
// Overloaded subscript [] operator. This function accepts  *
// an int argument that is the subscript being called. The  *
// returned element is editable.							*
// **********************************************************

template <class T>
T& SimpleVector<T>::operator[] (int sub)
{
	// Check if subscript is valid
	if (!isValidSubscript(sub))
	{
		subError();
	}
	else
	{
		// Increment array size if necessary
		if (sub >= arraySize) 
		{
			arraySize++;
		}

		// Return the editable called element
		return *(aPtr + sub);
	}
}


//***********************************************************
// getElement function: Returns the element at the			*
// provided position.										*
// **********************************************************

template <class T>
T SimpleVector<T>::getElement(int position) const
{
	return aPtr[position];
}

//***********************************************************
// push_back function: Receives a new element of type T to  *
// be added to end of vector.                               *
// **********************************************************

template <class T>
bool SimpleVector<T>::push_back(T newElement)
{
	// Check if vector has proper capacity
	if (vectorCapacity == arraySize)
	{
		// Attempt to grow vector
		if (!growVector())
		{
			// Indicate failed operation
			return false;
		}
	}

	// Increment arraySize variable
	arraySize++;

	// Store new element at end of vector
	aPtr[arraySize - 1] = newElement;

	// Indicate successful operation
	return true;
}

//************************************************************
// pop_back function: Deletes the last element in the vector * 
// ***********************************************************

template <class T>
bool SimpleVector<T>::pop_back()
{
	// Delete last element and decrement arraySize operator
	aPtr[--arraySize] = NULL;

	// Indicate successful operation
	return true;
}

#endif