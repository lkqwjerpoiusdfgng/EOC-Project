/***************************************************
 ********** EOC - Part A: Vector Template **********
 ***************************************************
 *
 *      Filename: SearchableVector.h
 *   Description: The SearchableVector class is a template
 *                class designed for a program to create
 *                searchable vectors of different data
 *                types. It is based on the SimpleVector
 *                template class. 

 *    Associated
 *		   files: SimpleVector.h		// Base class
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 23, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H

#include <algorithm>	// std::sort
#include "SimpleVector.h"

template <class T>
class SearchableVector : public SimpleVector<T>
{

private:
    /* Variables */
    SimpleVector<T> sorted;     // Holds the sorted dataset

    /* Functions */
    void sortData();	// Sorts vector in ascending order


public:
    /* Constructors */

        // Default constructor
        SearchableVector() : SimpleVector<T>();

        // Parameterized constructor
		SearchableVector(int size) : SimpleVector<T>(size)
			{ }

        // Copy constructor
        SearchableVector(const SearchableVector &);

    /* Destructor */

        ~SearchableVector();

    /* Member functions */

        // Function to locate item in vector
		bool doesExist(const T) const;

};

/* Private Functions */

template <class T>
void SearchableVector<T>::sortData()
{
	// Copy data to new SimpleVector to prevent
	// damage to original data
	sorted = new SimpleVector<T>(this);

	// Sort data
	std::sort(sorted[0], sorted[sorted.size() - 1]);
}

/* Destructor */

template <class T>
SearchableVector<T>::~SearchableVector()
{
	// Check if memory has been allocated
	if (sorted.capacity > 0)
	{
		// Deallocate memory
		delete[] sorted;
	}
}

/* Member functions */

template <class T>
bool SearchableVector<T>::doesExist(const T element) const
{
	// Binary search for element, return true if it exists in vector
	return std::binary_search(sorted[0], sorted[sorted.size() - 1], element);
}

#endif