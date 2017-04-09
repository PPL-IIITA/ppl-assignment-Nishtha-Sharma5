#ifndef GIFT_utility_H
#define GIFT_utility_H
#include "GIFT.h"

/** @brief Header file for class GIFT_utility
	* CLASS_utility inherits CLASS GIFT
	* containing attributes of utility GIFT
*/

class GIFT_utility : public GIFT{	//!< class GIFT_utility extends class GIFT
	public:
		int u_value; 			//!< Utility value of utility gift
		int u_class; 			//!< utility class of utility gift
		GIFT_utility(char *NID, int Nprice, int Nvalue, int Ndiff, int Nrate);		//!< Constructor for GIFT_utility
};
#endif
