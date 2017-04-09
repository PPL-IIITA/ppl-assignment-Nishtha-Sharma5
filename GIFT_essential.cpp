#include <string.h>
#include "GIFT_essential.h"
using namespace std;

/** @brief Class GIFT_essential
	* Allocate all variables according to passed values when GIFT_essential object is created
	* type = 0
	* TypeName is 'Essential'
*/
GIFT_essential :: GIFT_essential(char *NID, int Nprice, int Nvalue){
	strcpy(giftID, NID); 				//!< Unique ID of GIFT
       	price = Nprice; 				//!< Price of GIFT
       	value = Nvalue; 				//!< Value of GIFT
       	type = 0; 					//!< Type = 0
}
