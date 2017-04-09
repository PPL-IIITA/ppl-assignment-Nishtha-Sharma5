#ifndef GIFT_H
#define GIFT_H
using namespace std;
/** @brief Header file for class GIFT
 	* Contains various attributes of GIFT
	* Base class for different type of GIFTS
*/
class GIFT{
	public:
		char giftID[10]; 		//!< Unique ID for a gift
		int value; 			//!< Value of Gift
		int price; 			//!< Cost of gift
		int type; 			//!< Type: 0/1/2 Normal/Luxury/Utility
};
#endif
