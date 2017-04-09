#ifndef GIRL_H 			//!< Header file for class GIRL
#define GIRL_H
using namespace std;
/** @brief Header file for class GIRL
 	* Contains various attributes of girl
	* Base class for different type of GIRLS
 	*/
class GIRL{
	public:
        	char name[10]; 				//!< Unique name of girl
        	int attractiveness; 			//!< Attractiveness of girl
        	int maintenance; 			//!< Maintenance Cost of a girl
        	int intelligence; 			//!< Intelligence of girl
        	int status; 				//!< Status: committed/single
        	int criteria; 				//!< criteria: Most Attractive/Richest/Most Intelligent boy
        	int type; 				//!< Type: 0/1/2
		char TypeName[10];			//!< TypeName: Choosy/Normal/Desperate
		int Happiness();	//!< Function to calculate happiness
};
#endif
