/***************************************************
 ********** EOC - Part B: Basic Link List **********
 ***************************************************
 *
 *      Filename: ListAnalysis.h
 *   Description: The ListAnalysis class is designed
 *				  to extend the functions of the
 *				  BasicLinkList class and allow users
 *				  the option to perform various analysis
 *				  operations on LinkedLists of T values.
 *
 *
 *    Associated
 *		   files: SortedLinkList.h	// Base class
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 27, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */

#ifndef LISTANALYSIS_H
#define LISTANALYSIS_H

#include "SortedLinkList.h"

template <class T>
class ListAnalysis : private SortedLinkList<T>
{
private:
	int count;			// Holds number of nodes

public:
	
	/* Constructors */

	// Default constructor
	ListAnalysis() : SortedLinkList()
		{ count = 0; }

	/* Destructor */
	~ListAnalysis();

	/* Member functions */
	int getCount()				// Returns number of nodes
		{ return count; }

	T getHighValue();
	T getLowValue();
	T getAverage();
	T getMedian();
	T getMode();

	void newNode(T);
	void removeNode(T);
	void deleteFront();
	void deleteBack();
	void addToFront(T);
	void addToBack(T);
};

template <class T>
T ListAnalysis<T>::getHighValue()
{
	/* Variables */
	ListNode<T> *nodePtr;		// To navigate current list

	// Start at head
	nodePtr = head;

	// Find last node
	while (nodePtr->next != nullptr)
	{
		nodePtr = nodePtr->next;
	}

	// Return high value
	return nodePtr->value;
}

template <class T>
T ListAnalysis<T>::getLowValue()
{
	// Return low value
	return head->value;
}

template <class T>
T ListAnalysis<T>::getAverage()
{
	ListNode<T> *nodePtr;	// To traverse linked list
	T sum;					// Variable to hold sum
	
	// Start at head
	nodePtr = head;

	// Sum all the values
	while (nodePtr != nullptr)
	{
		sum += nodePtr->value;
		nodePtr = nodePtr->next;
	}

	// Return the average
	return sum / count;
}

template <class T>
T ListAnalysis<T>::getMedian()
{
	int position = 0;		// To store current node
	int median = count /2	// Holds position of median node
	ListNode<T> *nodePtr;	// To traverse list

	// Start at head
	nodePtr = head;

	// Find median
	for (position = 0; position < median; position++)
	{
		nodePtr = nodePtr->next;
	}

	// Return median value
	return nodePtr->value;
}

template <class T>
T ListAnalysis<T>::getMode()
{

}

template <class T>
void ListAnalysis<T>::newNode(T nValue)
{
	// Insert new node with passed value
	insertNode(nValue);

	// Increment count variable
	count++;
}

template <class T>
void ListAnalysis<T>::removeNode(T nValue)
{
	// Remove node with matching nValue
	deleteNode(nValue);

	// Decrement count variable
	count--;
}

template <class T>
void ListAnalysis<T>::deleteFront()
{
	// Remove head node
	removeFront();

	// Decrement count variable
	count--;
}

template <class T>
void ListAnalysis<T>::deleteBack()
{
	// Remove last node
	removeBack();

	// Decrement count variable
	count--;
}


template <class T>
void ListAnalysis<T>::addToFront(T nValue)
{
	// Add passed value as new node at head
	prepend(nValue);

	// Increment count variable
	count++;
}

template <class T>
void ListAnalysis<T>::addToBack(T nValue)
{
	// Add passed value as new node at end of list
	append(nValue);

	// Increment count variable
	count++;
}

#endif