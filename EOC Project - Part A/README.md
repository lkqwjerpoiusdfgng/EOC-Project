*What follows is the project description, as assigned*

##Part A:    Vector Template##

*Project Description:*

1. Create a SimpleVector Template Class.

	It should have the following member functions:
	*	Default Constructor
	*	Parameterized Constructor
	*	Copy Constructor
	*	Destructor
	*	Accessor to return the array size
	*	Accessor to return a specific element
	*	Subscript Operator
	*	push_back member that emulates the STL Vector
	*	pop_back member that emulates the STL Vector
	
2. Create a SearchableVector Template Class.
3. Use Inheritance from SimpleVector Template Class.
4. It should sort an unordered dataset and then search for a specific item returning true if found.

5. Test, Demonstrate, & Document each method implemented.

##Example Output
```
**************** TESTING PROGRAM ****************

This program will provide the opportunity to test
the implementation and operation of two template
classes: SimpleVector and SearchableVector.

Code by: Craig Medlin
Last modified: Nov. 23, 2014
Course: COSC 1437-P70
Instructor: Charles Braun
*****
****
***
**
*

Press ENTER to continue...

Please select one of the following options:
1. Demonstrate SimpleVector class
2. Demonstrate SearchableVector class
3. Demonstrate both Simple and Searchable vector classes
4. Display program information
5. Exit the program

Your selection: 3







We will now test the SimpleVector template class.
First, we will create a SimpleVector object to store int elements,
and also one to store double elements. We will then assign values
to the vectors and demonstrate the different functions that are possible.


New SimpleVector<int> created, simVectorA.
New SimpleVector<double> created simVectorB.

We will now fill the arrays with data.
simVectorA[0]: 1
simVectorB[0]: 1.11
simVectorA[1]: 2
simVectorB[1]: 2.22
simVectorA[2]: 3
simVectorB[2]: 3.33
simVectorA[3]: 4
simVectorB[3]: 4.44
simVectorA[4]: 5
simVectorB[4]: 5.55
simVectorA[5]: 6
simVectorB[5]: 6.66
simVectorA[6]: 7
simVectorB[6]: 7.77
simVectorA[7]: 8
simVectorB[7]: 8.88
simVectorA[8]: 9
simVectorB[8]: 9.99
simVectorA[9]: 10
simVectorB[9]: 11.1
Press ENTER to continue...



We will now test the accessor functions for each of the vectors,
starting with simVectorA.

simVectorA.size(): 10, expected value is 10.
simVectorA.capacity(): 10, expected value is 10.
simVectorA.front(): 1, expected value is 1.
simVectorA.back(): 10, expected value is 10.
simVectorA.getElement(5): 6, expected value is 6.

Press ENTER to continue...

simVectorB.size(): 10, expected value is 10.
simVectorB.capacity(): 15, expected value is 15.
simVectorB.front(): 1.11, expected value is 1.11.
simVectorB.back(): 11.1, expected value is 11.1.
simVectorB.getElement(5): 6.66, expected value is 6.66.

Press ENTER to continue...

We will now test the subscript operators for the vectors.

simVectorA[3]: 4 , the expected value is 4.
simVectorB[3]: 4.44 , the expected value is 4.44.

simVectorA[3] = simVectorA[5]
simVectorA[3]: 6, the expected value is 6.

simVectorB[3] = 1294.32
simVectorB[3]: 1294.32, the expected value is 1294.32.

Press ENTER to continue...

We will now test the modifier functions push_back and pop_back.
simVectorA.size(): 10
simVectorA.capacity(): 10
simVectorA.back(): 10

simVectorA.push_back(24)

simVectorA.size(): 11
simVectorA.capacity(): 20
simVectorA.back(): 24

Press ENTER to continue...

simVectorB.size(): 10
simVectorB.capacity(): 15
simVectorB.back(): 11.1

simVectorB.push_back(54.32)

simVectorB.size(): 11
simVectorB.capacity(): 15
simVectorB.back(): 54.32

simVectorB.pop_back()

simVectorB.size(): 10
simVectorB.capacity(): 15
simVectorB.back(): 11.1

Press ENTER to continue...

We have now tested all functions for the SimpleVector class.
We will now test the searchable vector class. We'll start by
creating a new serachable vector and populating it with data.

SearchableVector<int> vector(10)


vector[0] = 26;
vector[1] = 32;
vector[2] = 1;
vector[3] = 1983;
vector[4] = 2;
vector[5] = 0;
vector[6] = 12;
vector[7] = 99;
vector[8] = 31;
vector[9] = 21;

We will now run a search for value 12 within this vector.

0
1
2
12
21
26
31
32
99
1983
vector.doesExist(12): true

We have now finished testing the searchable vector.

Press ENTER to continue...
```
