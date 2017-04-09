#ifndef BOY_miser_H
#define BOY_miser_H
#include "BOY.h"

/** @brief Header file for class BOY_miser
	* CLASS miser inherits CLASS BOY
	*containing attributes of miser BOY formed
*/
class BOY_miser : public BOY{	//!< class BOY_miser extends class BOY
	public:
		BOY_miser(char *Nname, int Natrractiveness, int Nbudget, int Nintelligence, int NbeautyReqd);		//Constructor for BOY_miser
		int Happiness(int cost);			//function to calculate happiness
};
#endif
