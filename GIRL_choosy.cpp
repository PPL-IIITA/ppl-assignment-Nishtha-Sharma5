#include <iostream>			
#include <cmath>
#include <stdio.h>
#include <string.h>
#include "GIRL_choosy.h"		//including class GIRL_choosy
using namespace std;

/** @brief Allocate all variables according to passed values when Choosy object is created
 		*
		* Initial status = 0 (single)
		* type = 0
		* TypeName = "CHOOSY"
	 	*/
GIRL_choosy :: GIRL_choosy(char *Nname, int Natrractiveness, int Nmaintainence, int Nintelligence, int Ncriteria){
	strcpy(name, Nname); 				//!< Unique name of girl
       	attractiveness = Natrractiveness; 		//!< Attractiveness of girl
       	maintenance = Nmaintainence; 			//!< Maintenance Cost of a girl
       	intelligence = Nintelligence; 			//!< Intelligence of girl
       	status = 0; 					//!< Status: committed/single
       	criteria = Ncriteria; 				//1< criteria: Most Attractive/Richest/Most Intelligent boy
       	type = 0; 					//!< Type = 0
}
/** @brief Function to calculate Happiness
	* calculates happiness for choosy girl
	* happiness is logarithmic of the total cost of gifts achieved over maintenance.
	* the calculated happiness is returned
*/
int GIRL_choosy :: Happiness(int cost, int value) {		
	int happy;
	happy = log(1 + ((int)((cost - maintenance)%10)));	
	return happy;						
}


