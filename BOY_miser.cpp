#include <iostream>			
#include <cmath>
#include <string.h>
#include "BOY_miser.h"		//!< including class BOY_miser
using namespace std;

/** @brief Allocate all variables according to passed values when miser object is created
	* Initial status = 0 (single)
	* type = 0
*/
BOY_miser :: BOY_miser(char *Nname, int Natrractiveness, int Nbudget, int Nintelligence, int NbeautyReqd){
	strcpy(name, Nname); 				//!< Unique name of BOY
       	attractiveness = Natrractiveness; 		//!< Attractiveness of BOY
       	budget = Nbudget; 				//!< Budget of a BOY
       	intelligence = Nintelligence; 			//!< Intelligence of BOY
       	status = 0; 					//!< Status: committed/single
       	beautyReqd = NbeautyReqd; 			//!< Minimun attractiveness of girl
       	type = 0; 					//!< Type = 0
}
/** @brief Function to calculate Happiness
	* calculates happiness for miser BOY
	* happiness is given by the total unspent money from their budget.
	* the calculated happiness is returned
*/
int BOY_miser :: Happiness(int cost) {			//calculating happiness for miser BOY
	int happy;
	happy = budget - cost;				
	return happy;
}


