#include <iostream>			
#include <cmath>
#include <string.h>
#include "BOY_generous.h"		//!< including class BOY_generous
using namespace std;

/** @brief Allocate all variables according to passed values when generous object is created
	* Initial status = 0 (single)
	* type = 1
*/
BOY_generous :: BOY_generous(char *Nname, int Natrractiveness, int Nbudget, int Nintelligence, int NbeautyReqd){
	strcpy(name, Nname); 				//!< Unique name of BOY
       	attractiveness = Natrractiveness; 		//!< Attractiveness of BOY
       	budget = Nbudget; 				//!< Budget of a BOY
       	intelligence = Nintelligence; 			//!< Intelligence of BOY
       	status = 0; 					//!< Status: committed/single
       	beautyReqd = NbeautyReqd; 			//!< Minimun attractiveness of girl
       	type = 1; 					//!< Type = 1
}
/** @brief Function to calculate Happiness
	* calculates happiness for generous BOY
	* happiness is given by the happiness of the girlfriend.
	* the calculated happiness is returned
*/
int BOY_generous :: Happiness(int Ghappy) {		//calculating happiness for generous BOY
	int happy;
	happy = Ghappy;	
	return happy;
}


