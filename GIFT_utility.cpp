#include <string.h>
#include "GIFT_utility.h"
using namespace std;

/** @brief Class GIFT_utility
	* Allocate all variables according to passed values when GIFT_utility object is created
	* type = 2
	* TypeName is 'Utility'
*/

GIFT_utility :: GIFT_utility(char *NID, int Nprice, int Nvalue, int Nuvalue, int Nuclass){
	strcpy(giftID, NID); 				//!< Unique ID of GIFT
       	price = Nprice; 				//!< Price of GIFT
       	value = Nvalue; 				//!< Value of GIFT
	u_value = Nuvalue; 				//!< Utility value of utility gift
	u_class = Nuclass; 				//!< Utility class of utility gift
       	type = 2; 					//!< Type = 2
}
