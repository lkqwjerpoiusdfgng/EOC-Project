/***************************************************
 ********** EOC - Part A: Vector Template **********
 ***************************************************
 *
 *      Filename: SearchableVector.cpp
 *   Description: The SearchableVector class is a template
 *                class designed for a program to create
 *                searchable vectors of different data
 *                types. It is based on the SimpleVector
 *                template class.
 *
 *    Associated
 *		   files: SearchableVector.h	// Class header
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 23, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#include "SearchableVector.h"

#include <algorithm>	// std::sort

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
bool SearchableVector<T>::doesExist(T element const) const
{
	// Binary search for element, return true if it exists in vector
	return std::binary_search(sorted[0], sorted[sorted.size() - 1], element);
}