#include "collection.h"		//!< including header file collection.h
#include<bits/stdc++.h>
#include <string.h>
//#include<time.h>
using namespace std;
/** @Brief
* Boys give gifts to their girlfriends
* Each exchange of gift is printed in Output3.txt in detail
* Contains Function calculate for happiness and compatibility of couples
*/
int Gcount, Bcount, Gfcount;		//Count of girls, boys and gift respectively


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
			if(a[i]<a[i+1]){
                		swap(a[i], a[i+1]);
                		swap(temp1[i], temp1[i+1]);
				swap(temp2[i], temp2[i+1]);
			}
		}
	}
}
/** @Brief Function calculate
* Function calculates happiness and compatibility of couples
* Prints k happiest and most compatible couples
*/
void calculate(GIRL *girl, BOY *boy, COUPLE *couple, int k){ 				
	int gh, bh, ch, com, i, j;
	FILE *fpt;
	fpt = fopen("CoupleInfo2.txt", "w+");

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
		fputs(girl[i].name, fpt);
		fprintf(fpt, " %d ", gh);
		fputs(boy[i].name, fpt);
		fprintf(fpt, " %d %d %d %d %d %d\n", bh, main, BGT, cost, value, com);
	}
	fclose(fpt);
	int arr[50];
	FILE *fp;
	fp = fopen("Output3.txt", "a");
	char temp1[50][10], temp2[50][10]; 
	for(i=0 ; i<10 ; i++){
		strcpy(temp1[i], girl[i].name);
		strcpy(temp2[i], boy[i].name);
		arr[i] = couple[i].C_happy;
	}
	MySort2 (temp1, temp2, arr);		//!< sorting couples on the basis of happiness
	fputs("\n\n\nk Happiest Couples\n", fp); 
	for (i=0 ; i<k ; i++) {
		fputs(temp1[i], fp);
		fputs("\t", fp);		//!< writing K happiest couples to "Output2.txt"
		fputs(temp2[i], fp);
		fputs("\tHappiness: ", fp);;
		fprintf(fp, "%d\n", arr[i]);
	}
	for(i=0 ; i<10 ; i++) {
		strcpy(temp1[i], girl[i].name);
		strcpy(temp2[i], boy[i].name);
		arr[i] = couple[i].compatibility;
	}
	MySort2 (temp1, temp2, arr);		//!< sorting couples on the basis of happiness
	fputs("\n\n\nk Most Comatible Couples\n", fp);
	for (i=0 ; i<k ; i++) {
		fputs(temp1[i], fp);		//!< writing K most compatible couples to "Output2.txt"
		fputs("\t", fp);
		fputs(temp2[i], fp);
		fputs("\tCompatibility: ", fp);
		fprintf(fp, "%d\n", arr[i]);
	}
	fclose(fp);
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
collection::collection(int k_Couples){			//!< constructor of collection

	FILE *fp;
	int i, j, k, cost, value, flag;
	
	INPUT2 C(girl, boy);
	Gcount = C.Gcount2;
	Bcount = C.Bcount2;
	C.GiftBasket(gift);
	Gfcount = C.Gfcount;
	fp = fopen("Output3.txt", "w+");
	char temp[200][10];
	int arr[200][3];
	for(i=0 ; i<Gfcount ; i++){
		strcpy(temp[i], gift[i].giftID);
		arr[i][0] = gift[i].price;
		arr[i][1] = gift[i].type;
		arr[i][2] = gift[i].value;
	}
	MySort1(temp, arr, 0);
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
			fputs("(Choosy)", fp);		//!< writing in "Output2.txt"
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
	fputs("------------------------------------------------------------------------------------------------------------------------", fp);
	fclose(fp);
	calculate(girl, boy, couple ,k_Couples);		//!< calling function calculate
}
