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
    T *aptr;            // Points to the array that is holding data
    int arraySize;      // Holds size of current vector
	int capacity;		// Holds capacity of current vector
    int timesGrown;     // Holds number of times the vector has been grown
   
    /* Functions */
    void memError();				// Called in the event of memory allocation error
    void subError();				// Called in the event of subscript access error
	bool growVector();				// Function increases the size of the current vector
	int getNewAllocationSize();		// Function returns new vector capacity based on exponential  
									//		algorithm to maintain efficiency over standard array

public:
    
	/* Static Constants */
	static const int MAX_EXPANSION_AMOUNT = 150;	// Stores maximum vector capacity increase on reallocation

    /* Constructors */

        // Default constructor
        SimpleVector()
            { aptr = 0; arraySize = 0;}

        // Parameterized constructor accepting int value for initial size
        SimpleVector(int);

        // Copy constructor
        SimpleVector(const SimpleVector &);

    /* Destructor */

        virtual ~SimpleVector();

    /* Member functions */

        // Accessor function to return size of array
        int size() const
            { return arraySize; }

		// Accessor function to return capacity of array
		int capacity() const
			{ return capacity; }

        // Accessor function to return a specific element
        T getElement(int position);

		// Overloaded subscript operator for noneditable element
		T operator[] (const int) const;

        // Overloaded subscript operator for editable element
        T& operator[] (const int);

        // Function to add element onto end
        bool push_back(T);

        // Function to delete element at end of vector
        bool pop_back();
};

#endif