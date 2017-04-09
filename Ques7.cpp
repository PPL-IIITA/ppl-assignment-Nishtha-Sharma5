#include<bits/stdc++.h>
#include "Array.h"
#include "Hashing.h"
#include "SortedArray.h"
using namespace std;
/** @bried Question 7
	* You are given a list of boys. Find their girlfriend (if any). There are three implementations possible, storing
	* committed boys in a couple as an array/linked list, sorted array (binary search) and hash table. All have their own
	* pros and cons. Make all three implementations. The library should be such that the programmer of the main
	* program should be able to choose any of the implementation or prefer not to choose in which case the default
	* choice will be taken. (Suggestion: Implement all variants via inheritance and use upcasting to the base class).
*/
int main()
{
    	int k;
	cout<<"Enter option:\n1 Array/Linked LIst\n2 Sorted Array(Binary Search)\n3 Hash Table\n";
	scanf("%d", &k);
	cout<<"Committed boys among the random list\n";
	if(k==1)
		Array Q7;		//!< For Array implementation
	else if(k==2)
		SortedArray Q7;		//!< For Binary Search implementation
	else 
		Hashing Q7;		//!< For Hash Table implementation
	return 0;
}
