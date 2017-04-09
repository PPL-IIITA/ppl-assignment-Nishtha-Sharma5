#include "SortedArray.h"		//including header file TDays.h
#include<bits/stdc++.h>
#include <string.h>
//#include<time.h>
using namespace std;
/** @brief class SortedArray
	* Stores committed boys in an SortedArray
*/
int Gcount, Bcount, Gfcount;
int Ccount;
GIRL girl[100]; 		//!< Object array of class GIRL
BOY boy[100]; 			//!< Object array of class BOY
GIFT gift[100]; 		//!< Object array of class GIFT

int Binary(BOY *boy, int attr, int start, int end){
	if (start>end || start>9 || end<0)
		return -1;
	int mid = (start+end)/2;
	if(attr == boy[mid].attractiveness)
		return mid;
	else if(attr > boy[mid].attractiveness)
		Binary(boy, attr, mid+1, end);
	else
		Binary(boy, attr, start, mid);


}
SortedArray :: SortedArray(){
	INPUT2 C(girl, boy);
	Gcount = C.Gcount2;
	Bcount = C.Bcount2;
	GIRL Dgirl[10];
	BOY Dboy[100];
	INPUT D(Dgirl, Dboy);
	BOY Nboy[50];
	FILE *fp;
	fp = fopen("boys2.txt", "r+");
	int i, j, tmp, index;
	for(i=0 ; i<15 ; i++)				//!< Input list of boys to be searched
		fscanf(fp, "%s", Nboy[i].name);
	
	for(j=0; j<10; j++){			//!< Sort committed boys according to attractiveness
		for(i=0 ; i<(10-j-1) ; i++){
			if(boy[i].attractiveness > boy[i+1].attractiveness){
                		swap(boy[i], boy[i+1]);
			}
		}
	}
	int attr[15];
	for(i=0 ; i<15 ; i++) {
		for(j=0 ; j<100 ; j++) {
			if(strcmp(Nboy[i].name, Dboy[j].name) == 0) {
				attr[i] = Dboy[j].attractiveness;
				break;
			}
		}
	}
	char TEMP[10][10];
	int mark[15];
	for(i=0 ; i<15 ; i++)
		mark[i] = 0;
	for(i=0 ; i<10 ; i++)
		strcpy(TEMP[i], boy[i].name);
	for(i=0 ; i<15 ; i++) {
		for(j=0 ; j<10 ; j++){
			if(strcmp(TEMP[j], Nboy[i].name) == 0) {
				mark[i] = 1;
				break;
			}
		}

	}
	for(i=0; i<15 ; i++){
		if(mark[i] == 1)
			cout<<Nboy[i].name<<"\n";

	}
}
