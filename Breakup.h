#ifndef Breakup_H
#define Breakup_H
#include "INPUT.h"
#include "COUPLE.h"
/*!\brief Header File for class Breakup
	* Find the K least happy couples and performs breakup
	* New boyfriends are allocated to now single girls
	*/

class Breakup{
	public:
		int Ccount;
		GIRL girl[100]; 		//!< Object array of class GIRL
		BOY boy[100]; 			//!< Object array of class BOY
		COUPLE couple[50]; 		//!< Object array of class COUPLE
		Breakup(int k); 			//!< Constructor of Breakup
};
#endif

