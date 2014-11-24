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
 *		   files: SimpleVector.cpp		// Definitions
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 23, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H

template <class T>
class SimpleVector
{
private:
    
    /* Variables */ 
    T *aPtr;            // Points to the array that is holding data
    int arraySize;      // Holds size of current vector
	int capacity;		// Holds capacity of current vector
    int timesGrown;     // Holds number of times the vector has been grown
   
    /* Functions */
    void memError();				// Called in the event of memory allocation error
    void subError();				// Called in the event of subscript access error
	bool growVector();				// Function increases the size of the current vector
	bool isValidSubscript(int);		// Function returns whether subscript is valid for current vector
	int getNewAllocationSize();		// Function returns new vector capacity based on exponential  
									//		algorithm to maintain efficiency over standard array

public:
    
	/* Static Constants */
		static const int MAX_EXPANSION_AMOUNT = 150;	// Stores maximum capacity increase on reallocation

    /* Constructors */

        // Default constructor
        SimpleVector()
            { aPtr = 0; arraySize = 0;}

        // Parameterized constructor accepting int value for initial size
        SimpleVector(int);

        // Copy constructor
        SimpleVector(const SimpleVector &);

    /* Destructor */

        virtual ~SimpleVector();

    /* Member functions */

		
		/* OVERLOADED OPERATORS */

		T operator[] (const int) const;			// Subscript operator for noneditable element
        T& operator[] (const int);				// Subscript operator for editable element


		/* ACCESSOR FUNCTIONS */

		int size() const				// Returns size of array
			{ return arraySize;	}

		int capacity() const			// Returns capacity of array
			{ return capacity; }

		T getElement(const int) const;	// Returns a specific element

		T front() const					// Returns first element in vector
			{ return aPtr[0]; }

		T back() const					// Returns the last element in vector
			{ return aPtr[(arraySize - 1)]; }

        
		/* MODIFIERS */

        bool push_back(T);	// Adds element onto end of vector
        bool pop_back();	// Deletes element at end of vector
};

#endif