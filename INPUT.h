#ifndef INPUT_H
#define INPUT_H
#include "ALL.h"
/** @brief CLASS INPUT
	*The constructor takes data from text files and 
	*stores it in object array of BOY and GIRL
*/
class INPUT {
	public:
		int Gcount;		//!< Number of girls
		int Bcount;		//!< Number of boys
	public:
		/** @brief Allocates information of all boys and girls into 
			* object array of class BOY and class GIRL respectively
 			* Information regarding girls is read from "girls.txt'
			* Information regarding boys is read from "boys.txt
	 	*/
		INPUT(GIRL girl[], BOY boy[]);		//!< Constructor of class INPUT
};
#endif
