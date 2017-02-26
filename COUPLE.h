#ifndef COUPLE_H		//header file for COUPLE
#define COUPLE_H
#include<bits/stdc++.h>
using namespace std; 
class COUPLE{
        public:
       		float G_happy;			//happiness of girl
        	float B_happy;			//happiness of boy
        	float C_happy;			//overall happiness of girl and boy
        	int compatibility;		//compatibility of couple
		int Cost;			//Total cost of gifts
		int Value;			//Total value of gifts
		char Gname[10];			//girl's name
		char Bname[10];			//boy's name
		int BBudget;			//boy budget
		int GMaint;			//girl maintencance cost
};
#endif
