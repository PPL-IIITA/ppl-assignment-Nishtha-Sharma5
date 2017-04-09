#include<bits/stdc++.h>
#include "Breakup.h"
using namespace std;
/** Question 4
	* Perform a breakup after Valentines day of the least k happy couples. 
	* Assign new (different) boyfriends to the girls who broke up.
*/

int main()
{
    	int k;
	printf("To perform breakup between k least happy couples\nEnter value of k (less than 10)\n");
	scanf("%d", &k);
	Breakup Q4(k); //Exchanging gifts and calculating happiness and compatibility
	return 0;
}
