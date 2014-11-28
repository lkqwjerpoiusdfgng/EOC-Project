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
 *        Course: COSC 1437-P70 � M 6-9:45 p.m.
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

	using SortedLinkList<T>::printList;
};

template <class T>
ListAnalysis<T>::~ListAnalysis()
{

}

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
	T sum;			// Variable to hold sum
	
	// Start at head
	nodePtr = head;
	sum = head->value;

	// Move to next node
	nodePtr = nodePtr->next;

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
	int median = count / 2;	// Holds position of median node
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
	/* Variables */
	ListNode<T> *nodePtr;	// To traverse list
	ListNode<T> *counting;	// To hold value being incremented
	ListNode<T> *most;		// To point to most occuring node
	int mostOccurences = 0; // Holds greatest number of occurances
	int occurences = 0;		// Holds current number of occurances

	// Start at head
	nodePtr = head;
	counting = head;
	most = head;

	// Traverse list
	while (nodePtr != nullptr)
	{
		// Check if the value being counted matches current value
		while (nodePtr != nullptr && counting->value == nodePtr->value)
		{
			// Increment occurances
			occurences++;

			// Move to next node
			nodePtr = nodePtr->next;
		}

		// Check if number of occurances is greater than previous best
		if (occurences >= mostOccurences)
		{
			// Store current number of occurances as most
			mostOccurences = occurences;

			// Store node being counted as the most occuring
			most = counting;
		}
		
		// Move counting node to current node
		counting = nodePtr;

		// Reset number of occurances
		occurences = 0;
	}

	// Return most occuring value
	return most->value;
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