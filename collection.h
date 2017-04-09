#ifndef collection_H
#define collection_H
#include "INPUT2.h"
#include "COUPLE.h"
/*!\brief Header File for class collection
	* Constructor allots gifts to couples
	* Calculates k most compatible couples and k happiest couples
	* Ouput is written in 'Output2.txt'
	*/

class collection{
	public:
		int Ccount;
		COUPLE couple[50]; 		//!< Object array of class COUPLE
		GIRL girl[100]; 		//!< Object array of class GIRL
		BOY boy[100]; 			//!< Object array of class BOY
		GIFT gift[100]; 			//!< Object array of class GIFT
		collection(int k); 			//!< Constructor of collection
};
#endif

