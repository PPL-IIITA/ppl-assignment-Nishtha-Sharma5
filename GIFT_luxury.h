#ifndef GIFT_luxury_H
#define GIFT_luxury_H
#include "GIFT.h"

/** @brief Header file for class GIFT_luxury
	* CLASS_luxury inherits CLASS GIFT
	* containing attributes of luxury GIFT
*/

class GIFT_luxury : public GIFT{	//!< class GIFT_luxury extends class GIFT
	public:
		int l_diff; 			//!< Difficulty to obtain Luxury gift
		int l_rate; 			//!< Rating of Luxury gift
		GIFT_luxury(char *NID, int Nprice, int Nvalue, int Ndiff, int Nrate);		//!< Constructor for GIFT_luxury
};
#endif
