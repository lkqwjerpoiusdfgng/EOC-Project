/********************************************************
* The ListNode class is the template used to store	    *
* a value of data type T in a node in the linked list. *
* It also provides structure to hold the pointer	    *
* to the next node in the list.					    *
*******************************************************/

template <class T>
class ListNode
{
public:

	/* Variables */
	T value;			// Holds node value
	T sum;				// Holds current sum
	ListNode<T> *next;	// Pointer to next node

	/* Constructor */

	// Accepts argument for node value
	ListNode(T nValue)
	{
		// Initialize node value to passed argument
		value = nValue;

		// Initialize next pointer to nullptr
		next = nullptr;
	}
};
