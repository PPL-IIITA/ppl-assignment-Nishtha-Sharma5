#ifndef GIFT_essential_H
#define GIFT_essential_H
#include "GIFT.h"

/** @brief Header file for class GIFT_essential
	* CLASS_essential inherits CLASS GIFT
	* containing attributes of essential GIFT
*/
class GIFT_essential : public GIFT{	//!< class GIFT_essential extends class GIFT
	public:
		GIFT_essential(char *NID, int Nprice, int Nvalue);		//!< Constructor for GIFT_essential
};
#endif
