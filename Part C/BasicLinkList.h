/***************************************************
********** EOC - Part C: Basic Link List **********
***************************************************
*
*      Filename: BasicLinkList.h
*   Description: The BasicLinkList class is designed
*				  to emulate the functions of a
*				  standard linked list. It is a
*				  template class that will work with
*				  with virtually any data type.
*
*    Associated
*		   files:
*
*       Code by: Craig Medlin
* Last Modified: Nov. 30, 2014
*
*        Course: COSC 1437-P70 — M 6-9:45 p.m.
*     Professor: Charles Braun
*/

#ifndef BASICLINKLIST_H
#define	BASICLINKLIST_H

#include <iostream>		// For output operations (cout)
#include "ListNode.h"

/********************************************************
* LinkdedList class										*
********************************************************/

template <class T>
class BasicLinkList
{
protected:
	ListNode<T> *head;	// Pointer to head node

public:
	/* Constructor */
	BasicLinkList()
	{
		head = nullptr;
	}

	/* Destructor */
	~BasicLinkList();

	/* Member functions */
	void append(T);		// Add node to end of list
	void prepend(T);		// Add node to beginning of list
	void printList() const;		// Display node values in rows of 10
	void removeFront();		// Remove first node in list
	void removeBack();		// Remove node at back of list
	void clearList();		// Remove all nodes from list

};

/* DESTRUCTOR */

template <class T>
BasicLinkList<T>::~BasicLinkList()
{
	// Call function to empty the list
	clearList();
}

/* MEMBER FUNCTIONS */

/********************************************************
* append inserts a new node that holds the passed value	*
* nValue at the end of the list.						*
********************************************************/

template <class T>
void BasicLinkList<T>::append(T nValue)
{
	ListNode<T> *newNode;	// Holds pointer to new node
	ListNode<T> *nodePtr;	// Used to navigate current list

	// Allocate new node and store value
	newNode = new ListNode<T>(nValue);

	// Check if there are any nodes in the list
	if (!head)
	{
		// If no nodes exist, set new node to head node
		head = newNode;
	}
	else
	{
		// Navigate list and add new node to end
		nodePtr = head;

		// Find end of list
		while (nodePtr->next)
		{
			nodePtr = nodePtr->next;
		}

		// Insert new node
		nodePtr->next = newNode;
	}
}


/*********************************************************
* prepend inserts a new node that holds the passed value *
* nValue at the beginning of the list.					 *
*********************************************************/

template <class T>
void BasicLinkList<T>::prepend(T nValue)
{
	ListNode<T> *newNode;	// Holds pointer to new node

	// Allocate new node and store value
	newNode = new ListNode<T>(nValue);

	// Set next pointer to current head
	newNode->next = head;

	// Set head pointer to new node
	head = newNode;

}

/********************************************************
* printList prints the T values held in the linked list *
* in rows of 10 values.									*
********************************************************/

template <class T>
void BasicLinkList<T>::printList() const
{
	ListNode<T> *nodePtr;	// Used to navigate current list

	// Start at beginning of list
	nodePtr = head;

	// Check if list is empty
	if (!head)
	{
		cout << "*** THE LIST IS EMPTY\n";
	}

	// Print as long as nodes exist
	while (nodePtr)
	{
		// Print values in rows of ten
		for (int index = 0; index < 10; index++)
		{
			// Verify node exists
			if (nodePtr)
			{
				// Display current node's value
				cout << nodePtr->value << " ";

				// Move to the next node
				nodePtr = nodePtr->next;
			}
		}

		// Add line break
		std::cout << endl;
	}
}

/********************************************************
* removeFront deletes the node at the front of the		*
* linked list.											*
********************************************************/

template <class T>
void BasicLinkList<T>::removeFront()
{
	ListNode<T> *nodePtr;	// Used to swap head with second node

	// Set nodePtr to front node
	nodePtr = head;

	// Set head to second node
	head = head->next;

	// Delete the old first node
	delete nodePtr;
}

/********************************************************
* removeFront deletes the node at the back of the		*
* linked list.											*
********************************************************/

template <class T>
void BasicLinkList<T>::removeBack()
{
	ListNode<T> *nodePtr;	// Used to navigate the list 
	ListNode<T> *prevNode;	// Points to previous node in list

	// Verify list isn't empty
	if (!head)
	{
		return;
	}
	// Check if first node is last node
	else if (head->next == nullptr)
	{
		// Store current head node
		nodePtr = head;

		// Clear current head node
		head = nullptr;

		// Delete previous head node
		delete nodePtr;
	}
	else
	{
		// Start at top of list
		nodePtr = head;
		prevNode = nullptr;

		// Find final node
		while (nodePtr->next != nullptr)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// Update final node
		prevNode->next = nullptr;

		// Delete old last node
		delete nodePtr;
	}
}

/********************************************************
* clearList deletes all the nodes in the list.			*
********************************************************/

template <class T>
void BasicLinkList<T>::clearList()
{
	ListNode<T> *nodePtr;	// Used to navigate lsit
	ListNode<T> *nextNode;	// Stores next node

	// Start at top of list
	nodePtr = head;

	// Delete nodes while they exist
	while (nodePtr != nullptr)
	{
		// Store next node
		nextNode = nodePtr->next;

		// Delete current node
		delete nodePtr;

		// Move to next node
		nodePtr = nextNode;
	}

	// Reset head
	head = nullptr;
}

#endif