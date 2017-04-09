#include "TDays.h"		//including header file TDays.h
#include<bits/stdc++.h>
#include <string.h>
//#include<time.h>
using namespace std;

int Gcount, Bcount, Gfcount;
/** @brief Header File for class TDays
	* Suppose that gifting is not limited to Valentines day alone, 
	* but t days in a calendar month, well-marked. 
	* After every such day, 
	* couples with happiness less than t break up and form new couples.
*/

void MySort1(char temp[100][10], int a[100][3], int index){	//!< sort program to sort girl name, boy name, and happiness or compatibility
	int i, j, tmp;
	for(j=0; j<100; j++){
		for(i=0 ; i<(100-j-1) ; i++){
			if(a[i][index]>a[i+1][index]){
                		swap(a[i][0], a[i+1][0]);
			    	swap(a[i][1], a[i+1][1]);
                		swap(a[i][2], a[i+1][2]);
                		swap(temp[i], temp[i+1]);
			}
		}
	}
}
void MySort2(char temp1[50][10], char temp2[50][10], int a[50]){ 	//!< sort gifts by price
	int i, j, tmp;
	for(j=0; j<10; j++){
		for(i=0 ; i<(10-j-1) ; i++){
			if(a[i]>a[i+1]){
                		swap(a[i], a[i+1]);
                		swap(temp1[i], temp1[i+1]);
				swap(temp2[i], temp2[i+1]);
			}
		}
	}
}

void MySort(char temp[100][10], int a[100][3], int index){ 				//!< Function to sort boys according to criteria provided by girl
	int i, j, tmp;
	for(j=0; j<Bcount; j++){
		for(i=0 ; i<(Bcount-j-1) ; i++){
			if(a[i][index]>a[i+1][index]){
                swap(a[i][0], a[i+1][0]);
			    swap(a[i][1], a[i+1][1]);
                swap(a[i][2], a[i+1][2]);
                swap(temp[i], temp[i+1]);
			}
		}
	}
}
void WRITING(FILE *fp, char *temp, int arr[][3], int j){
	char tmp[10];				
	if(arr[j][1] == 0)
		strcpy(tmp, "Essential");
	else if(arr[j][1] == 1)
		strcpy(tmp, "Luxury");
	else
		strcpy(tmp, "Utility");
	fputs("\t Gift ID: ", fp);
	fputs(temp, fp);
	fprintf(fp, ", Price: %d, Value: %d, Type: ", arr[j][0], arr[j][2]);
	fputs(tmp, fp);
	time_t now = time(0); 
	char *Currenttime = ctime(&now); 
	fputs("\t\t\t", fp);
	fputs(Currenttime, fp);
	fputs("\n", fp);
}
TDays::TDays(int T){

	FILE *fp;
	int i, j, k, cost, value, flag;
	int gh, bh, ch, com;
	INPUT2 C(girl, boy);
	Gcount = C.Gcount2;
	Bcount = C.Bcount2;
	C.GiftBasket(gift);
	Gfcount = C.Gfcount;
	fp = fopen("Output6.txt", "w+");
	char temp[200][10];
	int arr[200][3];
	for(i=0 ; i<Gfcount ; i++){
		strcpy(temp[i], gift[i].giftID);
		arr[i][0] = gift[i].price;
		arr[i][1] = gift[i].type;
		arr[i][2] = gift[i].value;
	}
	MySort1(temp, arr, 0);
	int m;
	for(m=0 ; m<T ; m++) {
		for (i=0 ; i<10 ; i++){		//!< Exchanging gifts
			flag=0;
			cost=0;
			value=0;
			int BGT = boy[i].budget;
			int main = girl[i].maintenance;
			int bt = boy[i].type;
			int gt = girl[i].type;
			fputs(girl[i].name, fp);
			if(gt == 0)
				fputs("(Choosy)", fp);		//!< writing in "Output6.txt"
			else if(gt == 1)
				fputs("(Normal)", fp);
			else 
				fputs("(Desperate)", fp);
			fputs(": Maintenace Cost- ", fp);
			fprintf(fp, "%d\t", main);
			fputs(boy[i].name, fp);
			if(bt == 0)
					fputs("(Miser)", fp);
			else if(bt == 1)
				fputs("(Generous)", fp);
			else
				fputs("(Geeky)", fp);
			fputs(": Budget- ", fp);
			fprintf (fp, "%d\n", BGT);
			fputs("Gifts given\n", fp);	
			if(bt == 1){							//!< calculating total cost for Generous boy
				for (j=100-1 ; j>=0 ; j--){
					if(cost + arr[j][0] <= BGT) {
						cost = cost + arr[j][0];		//!< Alotting gifts from most exensive
						if (arr[j][1] == 2 && gt == 0)
							value = value + 2*arr[j][2];
						else
							value = value + arr[j][2];
						WRITING(fp, temp[j], arr, j);		//!< writing information about Gifts given to "Output2.txt"		
						flag=1;
					}
				}
	
			}
			else if(bt == 2){					//!< calculating toatal cost for Geeky boy
				for (j=0 ; j<Gfcount ; j++){
						if(arr[j][1] == 1) {
					if(cost + arr[j][0] <= BGT) {
							cost = cost + arr[j][0];
							if(gt == 0)
								value = value + 2*arr[j][2];
							else
								value = value + arr[j][2];	//!< finding and allotting an affordable Luxury gift
							WRITING(fp, temp[j], arr, j);		//!< writing information about Gifts given to "Output2.txt"
							flag=1;
					}
						break;
					}
				}
				if(cost >= main)
					break;
				for (j=0 ; j<Gfcount ; j++){
					if(cost + arr[j][0] <= BGT) {
						cost = cost + arr[j][0];
						value = value + arr[j][2];		//!< Finding and allotting gift staring from cheapest
						WRITING(fp, temp[j], arr, j);		//!< writing information about Gifts given to "Output2.txt"
						flag=1;
				}
					if(cost >= main)
						break;
				}
			}
			else if(bt == 0){
				for (j=0 ; j<Gfcount ; j++){
					if(cost + arr[j][0] <= BGT) {
						cost = cost + arr[j][0];
						value = value + arr[j][2];
						WRITING(fp, temp[j], arr, j);		//!< writing information about Gifts given to "Output2.txt"
						flag=1;
					}
					if(cost >= main)
						break;
				}
			}
			if(flag==0){						//!< calculating toatal cost for Miser boy
					boy[i].budget = arr[0][0];
				cost = arr[0][0];
				value = arr[0][1];			
			}
	
			couple[i].Cost = cost;
			couple[i].Value = value;
			fprintf(fp, "Total Cost: %d\t\tTotal Value: %d\n\n", cost, value);	//!< writing Total Cost and Total Value to "Output2.txt"
		}
		for (i=0 ; i<10 ; i++) {
			int BGT = boy[i].budget;
			int main = girl[i].maintenance;
			int bt = boy[i].type;
			int gt = girl[i].type;
			int cost = couple[i].Cost;
			int value = couple[i].Value;
			if( gt == 0) 			//!< calculating happiness for Choosy girl
				gh = log(1 + ((int)((cost - main)%10)));
			else if(gt == 1)		//!< calculating happiness for Normal girl	
				gh = cost - main + value;
			else				//!< calculating happiness for Desperate girl
				gh = exp((int)((cost - main)%10));
			if(bt == 0)			//!< calculating happiness for Miser boy
				bh = BGT - cost;
				else if (bt == 1)		//!< calculating happiness for Generous boy
			bh = gh;
				else				//!< calculating happiness for Geeky boy
			bh = girl[i].intelligence;
	
			ch = bh + gh;				//!< calculating overall happiness of couple
				int atr = abs (girl[i].attractiveness - boy[i].attractiveness);
			int intel = abs (girl[i].intelligence - boy[i].intelligence);
			com = BGT - main + atr + intel; 	//!< calculating compatibility of couple
			couple[i].G_happy = gh;
			couple[i].B_happy = bh;
			couple[i].C_happy = ch;
			couple[i].compatibility = com;
				}
			for(j=0; j<10; j++){
				for(i=0 ; i<(10-j-1) ; i++){
					if(couple[i].C_happy<couple[i+1].C_happy){
		                		swap(couple[i], couple[i+1]);
					}
				}
			}
				INPUT CF(girl, boy);
			Gcount = CF.Gcount;
			Bcount = CF.Bcount;
			char temp1[50][10], temp2[50][10];
			int art[50]; 
			for(i=0 ; i<10 ; i++){
				strcpy(temp1[i], couple[i].Gname);
				strcpy(temp2[i], couple[i].Bname);
				art[i] = couple[i].G_happy + couple[i].B_happy;
			}
			MySort2 (temp1, temp2, art);		//!< sorting couples on the basis of happiness
			int TT;
			for(i=0 ; i<10 ; i++) {
				if(art[i]>T)
					break;
			}
			TT = i;
	    		int j,k, w=0, flag, in, G_index, B_index;
	    		char temp[100][10];
		    	int arr[100][3];
		    	for (i=0 ; i<Bcount ; i++){ 						//!< pushing boy attributes in array
		        	strcpy(temp[i], boy[i].name); 
		        	arr[i][0] = boy[i].attractiveness;
		        	arr[i][1] = boy[i].budget;
		        	arr[i][2] = boy[i].intelligence;
		    	}
	    	for (i=0 ; i<TT ; i++){ 
	            	flag = 0;
				for(j=0 ; j<10 ; j++){
				if(strcmp(temp1[i], girl[j].name) == 0) {
					G_index = j;
					break;
				}
			}
			for(j=0 ; j<100 ; j++){
				if(strcmp(temp2[i], boy[j].name) == 0) {
					B_index = j;
					break;
				}
			}
			girl[G_index].status = 0;					//!< Girl is now single
			boy[B_index].status = 0;					//!< Boy is now single
			MySort(temp, arr, girl[G_index].criteria); 			//!< Sorting Function called
	                for(j=Bcount-1 ; j>=0 ; j--) {
	                       	for(k=0 ; k<Bcount ; k++){
	                       		if(strcmp(temp[j],boy[k].name) == 0){		//!< allotting fp boyfriend to girl
	                              		if(boy[k].status == 0 && girl[G_index].attractiveness >= boy[k].beautyReqd && girl[G_index].maintenance <= boy[k].budget && k!=B_index) {
	                               			girl[G_index].status = 1; 				//!< girl status changes to committed
	                               			boy[k].status = 1; 					//!< boy status changes to committed
							flag=1;
							fputs(girl[G_index].name, fp);
						fputs("\t\tOld Boyfriend: ", fp);
							fputs(boy[B_index].name, fp);
							fputs("\t\tfp Boyfriend: ", fp);
							fputs(boy[k].name, fp);
							time_t now = time(0); 					//!< adding time stamp
							char *ct = ctime(&now); 
							fputs("\t\t", fp);
							fputs(ct, fp);
							fputs("\n", fp);
	                               		}
	                               		break;
                       		}
	                      	}
	                    	if(flag == 1)
	                               	break;
			}
	    	}
	}
	fputs("------------------------------------------------------------------------------------------------------------------------", fp);
	fclose(fp);
}
