//Header file for class GIFT
#ifndef GIFT_H
#define GIFT_H
using namespace std;
 
class GIFT{
	public:
		char giftID[10]; 		//Unique ID for a gift
		int value; 			//Value of Gift
		int price; 			//Cost of gift
		int type; 			//Type of gift :Normal/Luxury/Utility
		int l_diff; 			//Difficulty to obtain Luxury gift
		int l_rate; 			//Rating of Luxury gift
		int u_value; 			//Utility value of utility gift
		int u_class; 			//utility class of utility gift
};
#endif
