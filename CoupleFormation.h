#ifndef CoupleFormation_H
#define CoupleFormation_H
#include "INPUT.h"
#include "COUPLE.h"
/*!\brief Header File for class CoupleFormation
	* Constructor forms couples from given list of boys and girls
	*/

class CoupleFormation{
	public:
		int Ccount;
		GIRL girl[100]; 		//!< Object array of class GIRL
		BOY boy[100]; 			//!< Object array of class BOY
		COUPLE couple[50]; 		//!< Object array of class COUPLE
		CoupleFormation(); 		//!< Constructor of CoupleFormation
};
#endif

