#include "INPUT2.h"
#include<bits/stdc++.h>
using namespace std;
/** @brief classs INPUT
	* Data is read from girls.txt and boys.txt
	* new objects of appropriate type are formed
	* allocates attributes to girl and boy objects
	* allocates attributes to gifts by GiftBasket function
*/
INPUT2 :: INPUT2 (GIRL girl[], BOY boy[]){
	int i;
	char name[10];
	int attractiveness;
	int maint_budg;
	int intelligence;
	int criteria;
	int type;
	int status;
	int beautyReqd;
    	FILE *fp;
    	fp = fopen("CoupleInfo.txt", "r"); 				//reading attributes for GIRL class from file "girls.txt"
	for(i=0 ; i<10 ; i++){
		GIRL *GT;
        	fscanf( fp, "%s %d %d %d %d %d %d ", name, &attractiveness, &maint_budg, &intelligence, &criteria, &type, &status);
		if(type == 0)
			GT = new GIRL_choosy(name, attractiveness, maint_budg, intelligence, criteria);		//!< new obect GIRL_choosy created
		else if(type == 1)
			GT = new GIRL_normal(name, attractiveness, maint_budg, intelligence, criteria);		//!< new obect GIRL_normal created
		else
			GT = new GIRL_desperate(name, attractiveness, maint_budg, intelligence, criteria);	//!< new obect GIRL_desperate created
		girl[i] = *GT;
		BOY *BT;
        	fscanf( fp, "%s %d %d %d %d %d %d", name, &attractiveness, &maint_budg, &intelligence, &beautyReqd, &type, &status);
		if(type == 0)
			BT = new BOY_miser(name, attractiveness, maint_budg, intelligence, beautyReqd);		//!< new obect BOY_miser created
		else if(type == 1)
			BT = new BOY_generous(name, attractiveness, maint_budg, intelligence, beautyReqd);	//!< new obect BOY_generous created
		else
			BT = new BOY_geek(name, attractiveness, maint_budg, intelligence, beautyReqd);		//!< new obect BOY_geek created
		boy[i] = *BT;
    	}
	Gcount2 = i;
    	Bcount2 = i;
	fclose(fp);
}
void INPUT2 :: GiftBasket (GIFT gift[]){
	FILE *fp;
	int i;
	char giftID[10];
	int type;
	int price;
	int value;
	int l_diff;
	int l_rate;
	int u_value;
	int u_class;
	fp = fopen ("gifts.txt", "r+"); 		//!< reading gift attributes from "gifts.txt"
	for (i=0 ; i<100 ; i++) {
		GIFT *GFT;
		fscanf(fp, "%s %d %d %d %d %d %d %d", giftID, &type, &price, &value, &l_diff, &l_rate, &u_value, &u_class);
		if(type == 0)
			GFT = new GIFT_essential(giftID, price, value);						//!< new object GIFT_essential created
		else if(type == 1)
			GFT = new GIFT_luxury(giftID, price, value, l_diff, l_rate);				//!< new object GIFT_luxury created
		else
			GFT = new GIFT_utility(giftID, price, value, u_value, u_class);				//!< new object GIFT_utility created
		gift[i] = *GFT;
	}
	Gfcount = i;
	fclose(fp);
}
