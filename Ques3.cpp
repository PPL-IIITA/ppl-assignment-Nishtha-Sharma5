#include<bits/stdc++.h>
#include "collection.h"
using namespace std;
/** @Brief Question 3
	* After allocating boyfriends to all girls in the same order as given in the input, and after performing gifting to all
	* girls as per logic, print the best k happiest couples and the best k most compatible couples. Also print all gift
	* details of gift exchanges between all couples. Solve the question using inheritance.
*/
int main()
{
    	int k;
	printf("To calculate k happiest and most compatible couple.\n Enter value of k (less than 10)\n");
	scanf("%d", &k);
	collection Q3(k); //Exchanging gifts and calculating happiness and compatibility
	return 0;
}
