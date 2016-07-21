##Part B : 	   Basic Link List##
*What follows is the project description, as assigned*

Project Description:

**Design a Basic Link List class to hold a series of integers.**

* Implement the following member functions:
   1. Append
   2. Prepend
   3. Constructor
   4. Destructor
   5. RemoveFront
   6. RemoveBack	
   7. Print List (in rows of ten values)
   8. ClearList

* Test/Demonstrate ALL methods.
* Populate your list with 50 scores between 30 and 95.
* Use random generator to create scores.

**Design a Sorted Link List class to hold a series of integers.**
* You may use Composition or Inheritance.
* Implement the additional member functions:
  1. Insert Node
  2. Delete Node

* Demonstrate ALL methods.
* Populate your list with 50 scores between 30 and 95.
* Use random generator to create scores.

**Design a List Analysis class to hold a series of integers.**
* You may use Composition or Inheritance.
* Implement the additional member functions:
   1. getCount
   2. getHighValue
   3. getLowValue
   4. getAverage
   5. getMedian
   6. getMode (value with most occurrences)  

* Demonstrate ALL methods.
* Generate a random number of 100  scores between.
* Populate your list with score values between 30 and 95.
* Use random generator to create scores.

##Example Output##
``` 
**************** TESTING PROGRAM ****************

This program will provide the opportunity to test
the implementation and operation of classes related to
linked lists. These include a Basic Link List class,
Sorted Link List class, and List Analysis class.
Code by: Craig Medlin
Last modified: Nov. 27, 2014
Course: COSC 1437-P70
Instructor: Charles Braun
*****
****
***
**
*

Press ENTER to continue...

Please select one of the following options:
1. Demonstrate BasicLinkList class
2. Demonstrate SortedLinkList class
3. Demonstrate ListAnalysis class
4. Demonstrate all linked list classes
5. Display program information
6. Exit the program

Your selection: 4


***********************************************
********************TESTING********************
***********************************************


We will now test the Basic Link List class.
We will start by creating a new Basic Link List and
populating it with 50 random integers between 30 and 95.
This operation will also test the Append function of
the class.


Press ENTER to continue...

*** New BasicLinkList<int> created successfully
*** 67 appeneded to BasicLinkList<int>
*** 43 appeneded to BasicLinkList<int>
*** 66 appeneded to BasicLinkList<int>
*** 91 appeneded to BasicLinkList<int>
*** 38 appeneded to BasicLinkList<int>
*** 38 appeneded to BasicLinkList<int>
*** 95 appeneded to BasicLinkList<int>
*** 84 appeneded to BasicLinkList<int>
*** 74 appeneded to BasicLinkList<int>
*** 49 appeneded to BasicLinkList<int>
*** 81 appeneded to BasicLinkList<int>
*** 32 appeneded to BasicLinkList<int>
*** 35 appeneded to BasicLinkList<int>
*** 42 appeneded to BasicLinkList<int>
*** 64 appeneded to BasicLinkList<int>
*** 73 appeneded to BasicLinkList<int>
*** 73 appeneded to BasicLinkList<int>
*** 67 appeneded to BasicLinkList<int>
*** 64 appeneded to BasicLinkList<int>
*** 85 appeneded to BasicLinkList<int>
*** 34 appeneded to BasicLinkList<int>
*** 64 appeneded to BasicLinkList<int>
*** 58 appeneded to BasicLinkList<int>
*** 84 appeneded to BasicLinkList<int>
*** 51 appeneded to BasicLinkList<int>
*** 72 appeneded to BasicLinkList<int>
*** 84 appeneded to BasicLinkList<int>
*** 38 appeneded to BasicLinkList<int>
*** 91 appeneded to BasicLinkList<int>
*** 71 appeneded to BasicLinkList<int>
*** 74 appeneded to BasicLinkList<int>
*** 73 appeneded to BasicLinkList<int>
*** 39 appeneded to BasicLinkList<int>
*** 75 appeneded to BasicLinkList<int>
*** 76 appeneded to BasicLinkList<int>
*** 31 appeneded to BasicLinkList<int>
*** 48 appeneded to BasicLinkList<int>
*** 30 appeneded to BasicLinkList<int>
*** 38 appeneded to BasicLinkList<int>
*** 75 appeneded to BasicLinkList<int>
*** 78 appeneded to BasicLinkList<int>
*** 89 appeneded to BasicLinkList<int>
*** 90 appeneded to BasicLinkList<int>
*** 50 appeneded to BasicLinkList<int>
*** 41 appeneded to BasicLinkList<int>
*** 41 appeneded to BasicLinkList<int>
*** 54 appeneded to BasicLinkList<int>
*** 35 appeneded to BasicLinkList<int>
*** 52 appeneded to BasicLinkList<int>
*** 53 appeneded to BasicLinkList<int>
Press ENTER to continue...



To verify the success of the list creation,
we will now display the entire list in rows of 10.
Please verify that the values match those presented
when the list was created.

67 43 66 91 38 38 95 84 74 49
81 32 35 42 64 73 73 67 64 85
34 64 58 84 51 72 84 38 91 71
74 73 39 75 76 31 48 30 38 75
78 89 90 50 41 41 54 35 52 53

Press ENTER to continue...



We will now remove the first node in the list.

*** First node removed
*** NEW LIST:
43 66 91 38 38 95 84 74 49 81
32 35 42 64 73 73 67 64 85 34
64 58 84 51 72 84 38 91 71 74
73 39 75 76 31 48 30 38 75 78
89 90 50 41 41 54 35 52 53

Press ENTER to continue...



We will now remove the last node in the list.

*** Last node removed
*** NEW LIST:
43 66 91 38 38 95 84 74 49 81
32 35 42 64 73 73 67 64 85 34
64 58 84 51 72 84 38 91 71 74
73 39 75 76 31 48 30 38 75 78
89 90 50 41 41 54 35 52

Press ENTER to continue...



We will now add a value to the beginning of the list.
The value to be added is: 88
*** 88 added to front of linked list
*** NEW LIST:
88 43 66 91 38 38 95 84 74 49
81 32 35 42 64 73 73 67 64 85
34 64 58 84 51 72 84 38 91 71
74 73 39 75 76 31 48 30 38 75
78 89 90 50 41 41 54 35 52

Press ENTER to continue...



We will now clear the list completely.

*** THE LIST IS EMPTY



We have finished testing the BasicLinkList class.

***********************************************
********************TESTING********************
***********************************************


We will now test the Sorted Linked List class.
First, we will create a new sorted list and populate
it with values. The values are to be generated randomly
and the Sorted Linked List object will automatically
sort the nodes as needed.

59 stored in SortedLinkList<int>
87 stored in SortedLinkList<int>
48 stored in SortedLinkList<int>
95 stored in SortedLinkList<int>
30 stored in SortedLinkList<int>
66 stored in SortedLinkList<int>
34 stored in SortedLinkList<int>
54 stored in SortedLinkList<int>
38 stored in SortedLinkList<int>
54 stored in SortedLinkList<int>
70 stored in SortedLinkList<int>
56 stored in SortedLinkList<int>
36 stored in SortedLinkList<int>
73 stored in SortedLinkList<int>
44 stored in SortedLinkList<int>
63 stored in SortedLinkList<int>
49 stored in SortedLinkList<int>
85 stored in SortedLinkList<int>
69 stored in SortedLinkList<int>
46 stored in SortedLinkList<int>
51 stored in SortedLinkList<int>
34 stored in SortedLinkList<int>
35 stored in SortedLinkList<int>
40 stored in SortedLinkList<int>
86 stored in SortedLinkList<int>
64 stored in SortedLinkList<int>
47 stored in SortedLinkList<int>
90 stored in SortedLinkList<int>
71 stored in SortedLinkList<int>
85 stored in SortedLinkList<int>
32 stored in SortedLinkList<int>
73 stored in SortedLinkList<int>
49 stored in SortedLinkList<int>
69 stored in SortedLinkList<int>
45 stored in SortedLinkList<int>
93 stored in SortedLinkList<int>
90 stored in SortedLinkList<int>
50 stored in SortedLinkList<int>
36 stored in SortedLinkList<int>
78 stored in SortedLinkList<int>
77 stored in SortedLinkList<int>
51 stored in SortedLinkList<int>
43 stored in SortedLinkList<int>
57 stored in SortedLinkList<int>
81 stored in SortedLinkList<int>
80 stored in SortedLinkList<int>
70 stored in SortedLinkList<int>
58 stored in SortedLinkList<int>
39 stored in SortedLinkList<int>
71 stored in SortedLinkList<int>

Press ENTER to continue...


Let's print the list to make sure it sorted the values:

30 32 34 34 35 36 36 38 39 40
43 44 45 46 47 48 49 49 50 51
51 54 54 56 57 58 59 63 64 66
69 69 70 70 71 71 73 73 77 78
80 81 85 85 86 87 90 90 93 95

Press ENTER to continue...


We will now test the deleteNode function.
We will use it to remove the last added node,
which has a value of 71.

30 32 34 34 35 36 36 38 39 40
43 44 45 46 47 48 49 49 50 51
51 54 54 56 57 58 59 63 64 66
69 69 70 70 71 73 73 77 78 80
81 85 85 86 87 90 90 93 95

Press ENTER to continue...


We will now insert a new value into the
linked list and verify that it is placed in the
correct position.
The value to be added is 48.

The new linked list is:

30 32 34 34 35 36 36 38 39 40
43 44 45 46 47 48 48 49 49 50
51 51 54 54 56 57 58 59 63 64
66 69 69 70 70 71 73 73 77 78
80 81 85 85 86 87 90 90 93 95


We are now finished testing the Sorted Link List class.
***********************************************
********************TESTING********************
***********************************************



We will now test the ListAnalysis class.
This class will allow us to analyze information
regarding our linked list.

We will start be creating a new linked list and
populating it with randomly generated values.

***New ListAnalysis<int> linked list created***

Press ENTER to continue...

The values being added to the list are:
94 63 81 82 87 61 64 88 83 34
71 35 61 73 71 90 63 55 63 33
84 39 77 95 32 60 38 78 91 58
37 84 53 73 80 87 65 32 90 84
74 82 77 87 42 56 40 72 39 32
42 30 37 43 61 43 63 92 73 33
88 94 89 83 40 73 36 38 56 89
74 45 86 94 94 84 48 70 37 34
80 72 88 55 85 38 32 54 60 43
88 80 43 79 87 70 34 77 77 60

Press ENTER to continue...


The now sorted data looks like this:
30 32 32 32 32 33 33 34 34 34
35 36 37 37 37 38 38 38 39 39
40 40 42 42 43 43 43 43 45 48
53 54 55 55 56 56 58 60 60 60
61 61 61 63 63 63 63 64 65 70
70 71 71 72 72 73 73 73 73 74
74 77 77 77 77 78 79 80 80 80
81 82 82 83 83 84 84 84 84 85
86 87 87 87 87 88 88 88 88 89
89 90 90 91 92 94 94 94 94 95

Press ENTER to continue...


We will now test several functions that
will allow us to analyze the data set.

getCount: 100
getHighValue: 95
getLowValue: 30
getAverage: 64
getMedian: 70
getMode: 94

We are now finished testing the ListAnalysis class.
Please verify the data generated from the above functions
by reviewing the dataset displayed above.
```
