/***************************************************
 ********** EOC - Part B: Basic Link List **********
 ***************************************************
 *
 *      Filename: SortedLinkList.h
 *   Description: The SortedLinkList class is designed
 *				  to extend the functions of the 
 *				  BasicLinkList class and allow users
 *				  the option to create LinkedLists of
 *				  sorted T values.
 *
 *
 *    Associated
 *		   files: BasicLinkList.h	// Base class
 *
 *       Code by: Craig Medlin
 * Last Modified: Nov. 27, 2014
 *
 *        Course: COSC 1437-P70 — M 6-9:45 p.m.
 *     Professor: Charles Braun
 */


#ifndef SORTEDLINKLIST_H
#define SORTEDLINKLIST_H

#include "BasicLinkList.h"

template <class T>
class SortedLinkList : protected BasicLinkList<T>
{
private: 

public:

	/* Constructors */
	SortedLinkList() : BasicLinkList<T>()
		{ }


	/* Destructor */
	~SortedLinkList();

	/* Member functions */
	void insertNode(T);		// Insert node containing a certain value
	void deleteNode(T);		// Remove node containing a certain value
	
	/* Allow certain inherited functions */
	using BasicLinkList<T>::clearList;
	using BasicLinkList<T>::removeFront;
	using BasicLinkList<T>::removeBack;
	using BasicLinkList<T>::printList;

};

/* DESTRUCTOR */
template <class T>
SortedLinkList<T>::~SortedLinkList()
{

}



/* MEMBER FUNCTIONS */


/***********************************************************
* insertNode adds the node that holds the passed value     *
* nValue to the list in the appropriate place.			   *
***********************************************************/

template <class T>
void SortedLinkList<T>::insertNode(T nValue)
{
	ListNode<T> *nodePtr;		// Used to traverse list
	ListNode<T> *prevNode;		// Points to previous node
	ListNode<T> *newNode;		// Points to new node

	// Allocate new node
	newNode = new ListNode<T>(nValue);


	// If no nodes exist or new value is less than head value, add to front
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		// Start at head
		prevNode = nullptr;
		nodePtr = head;

		// Find appropriate spot for nValue
		while (nodePtr != nullptr && nodePtr->value < nValue)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		if (prevNode == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			// Insert in appropriate space
			prevNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

/***********************************************************
* deleteNode removes the node that holds the passed value  *
* nValue from the list (if the value exists in the list).  *
***********************************************************/

template <class T>
void SortedLinkList<T>::deleteNode(T nValue)
{
	ListNode<T> *nodePtr = nullptr;		// Used to navigate the list
	ListNode<T> *prevNode = nullptr;		// Points to previous node

	// Verify list is not empty
	if (!head)
	{
		// Break and do nothing if list isn't empty
		return;
	}

	// Check if first node should be deleted
	if (head->value == nValue)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		// Start at head of list
		nodePtr = head;

		// Locate node with matching value
		while (nodePtr != nullptr && nodePtr->value != nValue)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the value exists in a node, delete it
		if (nodePtr)
		{
			prevNode->next = nodePtr->next;
			delete nodePtr;
		}
	}

}

#endif