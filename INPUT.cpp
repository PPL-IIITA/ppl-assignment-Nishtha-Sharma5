#include "INPUT.h"
#include<bits/stdc++.h>
using namespace std;
/** @brief classs INPUT
	* Data is read from girls.txt and boys.txt
	* new objects of appropriate type are formed
	* allocates attributes to girl and boy objects
*/
INPUT::INPUT (GIRL girl[], BOY boy[]){
	int i;
	char name[10];
	int attractiveness;
	int maint_budg;
	int intelligence;
	int criteria;
	int type;
	int status;
	int beautyReqd;
    	FILE *fg, *fb;
    	fg = fopen("girls.txt", "r"); 				//!< reading attributes for GIRL class from file "girls.txt"
	for(i=0 ; i<10 ; i++){
		GIRL *GT;
        	fscanf( fg, "%s %d %d %d %d %d %d", name, &attractiveness, &maint_budg, &intelligence, &criteria, &type, &status);
		if(type == 0)
			GT = new GIRL_choosy(name, attractiveness, maint_budg, intelligence, criteria);		//!< new obect GIRL_choosy created
		else if(type == 1)
			GT = new GIRL_normal(name, attractiveness, maint_budg, intelligence, criteria);		//!< new obect GIRL_normal created
		else
			GT = new GIRL_desperate(name, attractiveness, maint_budg, intelligence, criteria);	//!< new obect GIRL_desperate created
		girl[i] = *GT;
    	}
    	Gcount = i;
    	fclose(fg);
	fb = fopen("boys.txt", "r");				//!< reading attributes for BOY class from file "boys.txt"
    	for(i=0 ; i<100 ; i++){
		BOY *BT;
        	fscanf( fb, "%s %d %d %d %d %d %d", name, &attractiveness, &maint_budg, &intelligence, &beautyReqd, &type, &status);
		if(type == 0)
			BT = new BOY_miser(name, attractiveness, maint_budg, intelligence, beautyReqd);		//!< new obect BOY_miser created
		else if(type == 1)
			BT = new BOY_generous(name, attractiveness, maint_budg, intelligence, beautyReqd);	//!< new obect BOY_generous created
		else
			BT = new BOY_geek(name, attractiveness, maint_budg, intelligence, beautyReqd);		//!< new obect BOY_geek created
		boy[i] = *BT;
    	}
    	Bcount = i;
	fclose(fb);
}
