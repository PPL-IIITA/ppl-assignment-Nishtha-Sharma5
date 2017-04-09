#include <string.h>
#include "GIFT_luxury.h"
using namespace std;

/** @brief Class GIFT_luxury
	* Allocate all variables according to passed values when GIFT_luxury object is created
	* type = 1
	* TypeName is 'Luxury'
*/

GIFT_luxury :: GIFT_luxury(char *NID, int Nprice, int Nvalue, int Ndiff, int Nrate){
	strcpy(giftID, NID); 				//!< Unique ID of GIFT
       	price = Nprice; 				//!< Price of GIFT
       	value = Nvalue; 				//!< Value of GIFT
	l_diff = Ndiff; 				//!< Difficulty to obtain Luxury gift
	l_rate = Nrate; 				//!< Rating of Luxury gift
       	type = 1; 					//!< Type = 1
}
