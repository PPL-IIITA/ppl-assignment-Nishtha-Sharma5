#include "Array.h"		//including header file TDays.h
#include<bits/stdc++.h>
#include <string.h>
using namespace std;
/** @brief Committed boys stored in array */
GIRL Girl[100]; 		//!< Object array of class GIRL
BOY Boy[100]; 			//!< Object array of class BOY
Array :: Array(){
	INPUT2 C(Girl, Boy);
	BOY Nboy[50];
	FILE *fp;
	fp = fopen("boys2.txt", "r+");
	int i;
	for(i=0 ; i<15 ; i++)
		fscanf(fp, "%s", Nboy[i].name);
	char TEMP[10][10];
	int mark[15];
	for(i=0 ; i<15 ; i++)
		mark[i] = 0;
	for(i=0 ; i<10 ; i++)
		strcpy(TEMP[i], Boy[i].name);
	int j;
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
