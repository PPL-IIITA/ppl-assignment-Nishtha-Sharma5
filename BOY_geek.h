#ifndef BOY_geek_H
#define BOY_geek_H
#include "BOY.h"

/** @brief Header file for class BOY_geek
	* CLASS geek inherits CLASS BOY
	*containing attributes of geek BOY formed
*/
class BOY_geek : public BOY{	//!< class BOY_geek extends class BOY
	public:
		BOY_geek(char *Nname, int Natrractiveness, int Nbudget, int Nintelligence, int NbeautyReqd);		//!< Constructor for BOY_geek
		int Happiness(int Gintel);			//!< function to calculate happiness
};
#endif
