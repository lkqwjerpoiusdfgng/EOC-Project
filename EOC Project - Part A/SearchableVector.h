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

#include "SimpleVector.h"

template <class T>
class SearchableVector : public SimpleVector<T>
{

private:

    /* Functions */
	void quickSort(T*, const int, const int);	// Sorts vector in ascending order


public:
    /* Constructors */

        // Default constructor
        SearchableVector() : SimpleVector<T>()
			{ }

        // Parameterized constructor
		SearchableVector(int size) : SimpleVector<T>(size)
			{ }

        // Copy constructor
		SearchableVector(const SearchableVector &)
			{ }

    /* Destructor */

        ~SearchableVector();

    /* Member functions */

        // Function to locate item in vector
		bool doesExist(const T);

};

/* Private Functions */

template <class T>
void SearchableVector<T>::quickSort(T sort[], const int left, const int right)
{

	// Temp variable to hold value to swap
	T temp;

	// Pivot for QuickSort algorithm
	T pivot = sort[(left+right)/2];

	// Variables for sorting
	int i = left, j = right;

	// Partition
	while (i <= j)
	{
		while (sort[i] < pivot)
		{
			i++;
		}
		while (sort[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			temp = sort[i];
			sort[i] = sort[j];
			sort[j] = temp;
			i++;
			j--;
		}
	};

	// Recursion
	if (left < j)
		quickSort(sort, left, j);
	if (i < right)
		quickSort(sort, i, right);

}

/* Destructor */

template <class T>
SearchableVector<T>::~SearchableVector()
{ 

}

/* Member functions */

template <class T>
bool SearchableVector<T>::doesExist(const T element)
{
	// Copy data to new array for security
	T *sorted = new T[size()];

	for (int i = 0; i < size(); i++)
	{
		sorted[i] = this->getElement(i);
	}
	
	// Store position of last element
	int back = this->size() - 1;
	
	// Sort the data
	quickSort(sorted, 0, back);

	// Display sorted list 
	for (int i = 0; i < size(); i++)
	{
		cout << sorted[i] << endl;
	}

	// Binary search
	bool exists = false;
	int l = 0, h = back;

	while (h >= l)
	{
		int mid = (h+l) / 2;
		if (element == sorted[mid])
		{
			exists = true;
			return exists;
		}
		else if (element > sorted[mid])
		{
			l = mid + 1;
		}
		else
		{
			h = mid - 1;
		}
	}

	return exists;
}

#endif