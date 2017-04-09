#ifndef COUPLE_H		//header file for COUPLE
#define COUPLE_H
#include<bits/stdc++.h>
using namespace std;
/** class COUPLE
	* conatins information about couples
	* stores various attributes of GIRL ans BOY 
*/
class COUPLE{
        public:
       		int G_happy;			//!< happiness of girl
        	int B_happy;			//!< happiness of boy
        	int C_happy;			//!< overall happiness of girl and boy
        	int compatibility;		//!< compatibility of couple
		int Cost;			//!< Total cost of gifts
		int Value;			//!< Total value of gifts
		char Gname[10];			//!< girl's name
		char Bname[10];			//!< boy's name
		int BBudget;			//!< boy budget
		int GMaint;			//!< girl maintencance cost
};
#endif
