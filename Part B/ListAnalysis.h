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
 * Last Modified: Nov. 30, 2014
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
	
	T getHighValue();	// Returns highest value
	 T getLowValue();	// Returns lowest value
	  T getAverage();   // Calculates and returns average value
	   T getMedian();	// Locates and returns median value
	     T getMode();	// Determines most frequent occuring value and returns it

		void newNode(T);	// Adds a new node
	 void removeNode(T);	// Removes a node containing a specific value
	 void deleteFront();	// Deletes the first node in the list
	  void deleteBack();	// Deletes the last node in the list
	 void addToFront(T);	// Inserts a node at the front of the list
      void addToBack(T);	// Inserts a node at the back of the list

	// Using the inherited printList function
	using SortedLinkList<T>::printList;
};

/* DESTRUCTOR */
template <class T>
ListAnalysis<T>::~ListAnalysis()
{

}

/***************************************
* The getHighValue() function locates  *
* the highest valued item in a sorted  *
* list (the final node) and returns	   *
* its value.						   *
***************************************/
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

/***************************************
* The getLowValue() function locates   *
* the lowest valued item in a sorted   *
* list (the first node) and returns	   *
* its value.						   *
***************************************/

template <class T>
T ListAnalysis<T>::getLowValue()
{
	// Return low value
	return head->value;
}

/***************************************
* The getAverage() function calculates *
* the average of all the values by	   *
* summing them and then dividing that  *
* sum by the total number of elements. *
***************************************/

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

/***************************************
* The getMedian() function locates the *
* median by dividing the total number  *
* of elements by two and returning	   *
* the value at that position.		   *
***************************************/

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

/***************************************
* The getMode() function traverses a   *
* sorted list and counts the number of *
* times each value occurs. It returns  *
* the value that occurs the most.	   *
*									   *
* NOTE: In the event of a tie, the	   *
* function wil return the most recent  *
* value which occured the greatest	   *
* number of times.
***************************************/

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

/***************************************
* The newNode() function accepts a T   *
* value and inserts it into the list   *
* as a new node.					   *
***************************************/

template <class T>
void ListAnalysis<T>::newNode(T nValue)
{
	// Insert new node with passed value
	insertNode(nValue);

	// Increment count variable
	count++;
}

/***************************************
* The removeNode() function accepts a  *
* T value and searches for it in the   *
* existing list. If the value exists,  *
* it is removed from the list.		   *
***************************************/

template <class T>
void ListAnalysis<T>::removeNode(T nValue)
{
	// Remove node with matching nValue
	deleteNode(nValue);

	// Decrement count variable
	count--;
}

/***************************************
* The deleteFront() function removes   *
* the first node in the linked list.   *
***************************************/

template <class T>
void ListAnalysis<T>::deleteFront()
{
	// Remove head node
	removeFront();

	// Decrement count variable
	count--;
}

/***************************************
* The deleteBack() function removes    *
* the first node in the linked list.   *
***************************************/

template <class T>
void ListAnalysis<T>::deleteBack()
{
	// Remove last node
	removeBack();

	// Decrement count variable
	count--;
}

/***************************************
* The addToFront() function accepts a  *
* T value and adds it to the list as   *
* a new head node.					   *
***************************************/

template <class T>
void ListAnalysis<T>::addToFront(T nValue)
{
	// Add passed value as new node at head
	prepend(nValue);

	// Increment count variable
	count++;
}

/***************************************
* The addToBack() function accepts a   *
* T value and adds it to the list as   *
* a new node at the end of the list.   *
***************************************/

template <class T>
void ListAnalysis<T>::addToBack(T nValue)
{
	// Add passed value as new node at end of list
	append(nValue);

	// Increment count variable
	count++;
}

#endif