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
 *		   files: SimpleVector.h		// Base class header
 *				  SearchableVector.cpp  // Function definitions
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 23, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#ifndef SEARCHABLEVECTOR_H
#define SEARCHABLEVECTOR_H

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
        SearchableVector() : SimpleVector<T>()
            { }

        // Parameterized constructor
        SearchableVector(int size) : SimpleVector<T>(size)

        // Copy constructor
        SearchableVector(const SearchableVector &);

    /* Destructor */

        ~SearchableVector();

    /* Member functions */

        // Function to locate item in vector
        bool doesExist(T const) const;

};

#endif