#include <iostream>			
#include <cmath>
#include <stdio.h>
#include <string.h>
#include "GIRL_desperate.h"		//including class GIRL_desperate
using namespace std;

/** @brief Allocate all variables according to passed values when desperate object is created
 		*
		* Initial status = 0 (single)
		* type = 2
		* TypeName = "desperate"
	 	*/
GIRL_desperate :: GIRL_desperate(char *Nname, int Natrractiveness, int Nmaintainence, int Nintelligence, int Ncriteria){
	strcpy(name, Nname); 				//!< Unique name of girl
       	attractiveness = Natrractiveness; 		//!< Attractiveness of girl
       	maintenance = Nmaintainence; 			//!< Maintenance Cost of a girl
       	intelligence = Nintelligence; 			//!< Intelligence of girl
       	status = 0; 					//!< Status: committed/single
       	criteria = Ncriteria; 				//!< criteria: Most Attractive/Richest/Most Intelligent boy
       	type = 2; 					//!< Type = 2
}
/** @brief Function to calculate Happiness
	* calculates happiness for desperate girl
	* happiness is exponential to the total cost of gifts received over maintenance, including luxury gifts.
	* the calculated happiness is returned
*/
int GIRL_desperate :: Happiness(int cost, int value) {			
	int happy;
	happy = cost - maintenance + value;		
	return happy;					
}


