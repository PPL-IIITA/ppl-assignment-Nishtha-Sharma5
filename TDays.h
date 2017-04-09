#ifndef TDays_H
#define TDays_H
#include "INPUT2.h"
#include "INPUT.h"
#include "COUPLE.h"
/** @brief Header File for class TDays
	* Suppose that gifting is not limited to Valentines day alone, 
	* but t days in a calendar month, well-marked. 
	* After every such day, 
	* couples with happiness less than t break up and form new couples.
*/

class TDays{
	public:
		int Ccount;
		COUPLE couple[50]; 		//!< Object array of class COUPLE
		GIRL girl[100]; 		//!< Object array of class GIRL
		BOY boy[100]; 			//!< Object array of class BOY
		GIFT gift[100]; 		//!< Object array of class GIFT
		TDays(int k); 			//!< Constructor of TDays
};
#endif

