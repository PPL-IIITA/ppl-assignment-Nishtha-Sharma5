#ifndef BOY_generous_H
#define BOY_generous_H
#include "BOY.h"

/** @brief Header file for class BOY_generous
	* CLASS generous inherits CLASS BOY
	*containing attributes of generous BOY formed
*/
class BOY_generous : public BOY{	//!< class BOY_generous extends class BOY
	public:
		BOY_generous(char *Nname, int Natrractiveness, int Nbudget, int Nintelligence, int NbeautyReqd);		//!< Constructor for BOY_generous
		int Happiness(int Ghappy);			//function to calculate happiness
};
#endif
