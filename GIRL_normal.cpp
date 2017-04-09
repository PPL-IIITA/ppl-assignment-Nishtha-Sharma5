#include <iostream>			
#include <cmath>
#include <stdio.h>
#include <string.h>
#include "GIRL_normal.h"		//including class GIRL_normal
using namespace std;

/** @brief Allocate all variables according to passed values when normal object is created
 		*
		* Initial status = 0 (single)
		* type = 1
		* TypeName = "normal"
	 	*/
GIRL_normal :: GIRL_normal(char *Nname, int Natrractiveness, int Nmaintainence, int Nintelligence, int Ncriteria){
	strcpy(name, Nname); 				//!< Unique name of girl
       	attractiveness = Natrractiveness; 		//!< Attractiveness of girl
       	maintenance = Nmaintainence; 			//!< Maintenance Cost of a girl
       	intelligence = Nintelligence; 			//!< Intelligence of girl
       	status = 0; 					//!< Status: committed/single
       	criteria = Ncriteria; 				//!< criteria: Most Attractive/Richest/Most Intelligent boy
       	type = 1; 					//!< Type = 1
}
/** @brief Function to calculate Happiness
	* calculates happiness for normal girl
	* happiness in a relationship is linear to the total cost of gifts achieved over maintenance,
	* including luxury gifts. The value of all gifts is added additional to the cost.
	* the calculated happiness is returned
*/
int GIRL_normal :: Happiness(int cost, int value) {
	int happy;
	happy = exp((int)((cost - maintenance)%10));	
	return happy;					
}


