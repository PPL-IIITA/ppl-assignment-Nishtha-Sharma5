#ifndef GIRL_choosy_H			
#define GIRL_choosy_H			
#include "GIRL.h"			
/** @brief Header file for class GIRL_choosy
	* CLASS GIRL_choosy inherits CLASS GIRL
	*containing attributes of choosy girl formed
*/
class GIRL_choosy : public GIRL{	//!<class GIRL_choosy extends class GIRL
	public:
		GIRL_choosy(char *Nname, int Natrractiveness, int Nmaintainence, int Nintelligence, int Ncriteria);		//Constructor for GIRL_choosy
		int Happiness(int cost, int value);
};
#endif
