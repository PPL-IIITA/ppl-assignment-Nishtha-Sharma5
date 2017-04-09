#ifndef BOY_H 
#define BOY_H
/** @brief Header file for class BOY
 	* Contains various attributes of boy
	* Base class for different type of BOYS
 	*/
using namespace std;
class BOY{
	public:
        	char name[10]; 			//!< Unique name of boy
        	int attractiveness; 		//!< Attractiveness of boy
        	int budget; 			//!< Budget of a boy
        	int intelligence; 		//!< Intelligence of boy
        	int status; 			//!< Status: committed/single
        	int beautyReqd; 		//!< Minimun attractiveness of girl
		int type; 			//!< Type: 0/1/2 : Miser/Generous/Geekys
		int Happiness();
};
#endif
