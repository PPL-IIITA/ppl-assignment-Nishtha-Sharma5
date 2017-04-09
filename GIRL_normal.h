#ifndef GIRL_normal_H			
#define GIRL_normal_H			
#include "GIRL.h"			
/** @brief Header file for class GIRL_normal
	* CLASS GIRL_normal inherits CLASS GIRL
	*containing attributes of normal girl formed
*/
class GIRL_normal : public GIRL{	//!< class GIRL_normal extends class GIRL
	public:
		GIRL_normal(char *Nname, int Natrractiveness,  int Nmaintainence, int Nintelligence, int Ncriteria);		//!< Constructor for GIRL_normal
		int Happiness(int cost, int value);			//!< function to calculate happiness

};
#endif
