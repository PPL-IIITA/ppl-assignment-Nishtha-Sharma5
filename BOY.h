#ifndef BOY_H //Header File for class BOY
#define BOY_H
#include<bits/stdc++.h>
using namespace std;
class BOY{
	public:
        	char name[10]; 			//Unique name of boy
        	int attractiveness; 		//Attractiveness of boy
        	int budget; 			//Maintenance Cost of a boy
        	int intelligence; 		//Intelligence of boy
        	int status; 			//Status: committed/single
        	int beautyReqd; 		//Minimun attractiveness of girl
        	int type; 			//Type: Miser/Generous/Geeky
};
#endif
