#ifndef GIRL_desperate_H			
#define GIRL_desperate_H			
#include "GIRL.h"				
/** @brief Header file for class GIRL_desperate
	* CLASS GIRL_desperate inherits CLASS GIRL
	*containing attributes of desperate girl formed
*/
class GIRL_desperate : public GIRL{	//!< class GIRL_desperate extends class GIRL
	public:
		GIRL_desperate(char *Nname, int Natrractiveness, int Nmaintainence, int Nintelligence, int Ncriteria);		//!< Constructor for GIRL_desperate
		int Happiness(int cost, int value);			//!< function to calculate happiness
};
#endif
