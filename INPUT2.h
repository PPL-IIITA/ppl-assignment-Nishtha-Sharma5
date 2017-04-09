#ifndef INPUT2_H
#define INPUT2_H
#include "ALL.h"
/** @brief CLASS INPUT2
	*The constructor takes data from text files and 
	*stores it in object array of BOY, GIRL and GIFT
*/
class INPUT2 {
	public:
		int Gcount2;		//!< Number of girls
		int Bcount2;		//!< Number of boys
		int Gfcount;		//!< Number of gifts
	public:
		/** @brief Allocates information of all committed boys and girls into 
			* object array of class BOY and class GIRL respectively
 			* Information regarding couples is read from "CoupleInfo.txt'
	 	*/
		INPUT2(GIRL girl[], BOY boy[]);		//!< Constructor of class INPUT2

		/** @brief Allocates information of all gifts into object array of class GIFT
 		* Information regarding gifts is read from "gifts.txt'
	 	*/
		void GiftBasket (GIFT gift[]);		//!< Function to transfer information of all gifts into GIFT array
};
#endif
