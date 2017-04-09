#ifndef CoupleFormation2_H
#define CoupleFormation2_H
#include "INPUT.h"
#include "COUPLE.h"
/*!\brief Header File for class CoupleFormation2
	* Constructor forms couples from given list of boys and girls
	*/

class CoupleFormation2{
	public:
		int Ccount;
		GIRL girl[100]; 		//!< Object array of class GIRL
		BOY boy[100]; 			//!< Object array of class BOY
		COUPLE couple[50]; 		//!< Object array of class COUPLE
		CoupleFormation2(); 		//!< Constructor of CoupleFormation2
};
#endif

