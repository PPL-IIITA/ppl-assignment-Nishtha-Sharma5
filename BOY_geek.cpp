#include <iostream>			
#include <cmath>
#include <string.h>
#include "BOY_geek.h"		//!< including class BOY_geek
using namespace std;

/** @brief Allocate all variables according to passed values when BOY_geek object is created
	* Initial status = 0 (single)
	* type = 2
*/
BOY_geek :: BOY_geek(char *Nname, int Natrractiveness, int Nbudget, int Nintelligence, int NbeautyReqd){
	strcpy(name, Nname); 				//!< Unique name of BOY
       	attractiveness = Natrractiveness; 		//!< Attractiveness of BOY
       	budget = Nbudget; 				//!< Budget of a BOY
       	intelligence = Nintelligence; 			//!< Intelligence of BOY
       	status = 0; 					//!< Status: committed/single
       	beautyReqd = NbeautyReqd; 			//!< Minimun attractiveness of girl
       	type = 2; 					//!< Type = 2
}
/** @brief Function to calculate Happiness
	* calculates happiness for geek BOY
	* happiness is given by the intelligence of their girlfriend
	* the calculated happiness is returned
*/
int BOY_geek :: Happiness(int Gintel) {			//!< calculating happiness for geek BOY
	int happy;
	happy = Gintel;					 
	return happy;					
}


