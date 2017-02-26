#include "collection.h"		//including header file collection.h
#include "GIFT.h" 		//including header file GIFT.h
#include "GIRL.h"  		//including header file GIRL.h
#include "BOY.h" 		//including header file BOY.h
#include "COUPLE.h" 		//including header file COUPLE.h
#include<bits/stdc++.h>
using namespace std;

GIRL girl[100]; 		//Object array of class GIRL
BOY boy[100]; 			//Object array of class GIRL
COUPLE couple[50]; 		//Object array of class GIRL
GIFT gift[50]; 			//Object array of class GIFT
int Gcount, Bcount, Ccount, Gfcount;

void MySort1(char temp[100][10], int a[100][3], int index){	//sort program to sort girl name, boy name, and happiness or compatibility
	int i, j, tmp;
	for(j=0; j<Gfcount; j++){
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

void MySort2(char temp1[50][10], char temp2[50][10], int a[50]){ 	//sort gifts by price
	int i, j, tmp;
	for(j=0; j<Ccount; j++){
		for(i=0 ; i<(Ccount-j-1) ; i++){
			if(a[i]<a[i+1]){
                		swap(a[i], a[i+1]);
                		swap(temp1[i], temp1[i+1]);
				swap(temp2[i], temp2[i+1]);
			}
		}
	}
}
void calculate(){ 				//calculate happiness and compatibility
	int gh, bh, ch, com, i, j;


	for (i=0 ; i<Ccount ; i++) {
		int BGT = boy[i].budget;
		int main = girl[i].maintenance;
		int bt = boy[i].type;
		int gt = girl[i].type;
		int cost = couple[i].Cost;
		int value = couple[i].Value;
		if( gt == 0) 			//calculating happiness for Choosy girl
			gh = log(1 + ((int)((cost - main)%10)));
		else if(gt == 1)		//calculating happiness for Normal girl
			gh = cost - main + value;
		else				//calculating happiness for Desperate girl
			gh = exp((int)((cost - main)%10));
		if(bt == 0)			//calculating happiness for Miser boy
			bh = BGT - cost;
		else if (bt == 1)		//calculating happiness for Generous boy
			bh = gh;
		else				//calculating happiness for Geeky boy
			bh = girl[i].intelligence;

		ch = bh + gh;				//calculatinh overall happiness of couple
		int atr = abs (girl[i].attractiveness - boy[i].attractiveness);
		int intel = abs (girl[i].intelligence - boy[i].intelligence);
		com = BGT - main + atr + intel; 	//calculating compatibility of couple
		couple[i].G_happy = gh;
		couple[i].B_happy = bh;
		couple[i].C_happy = ch;
		couple[i].compatibility = com;
		
	}
	int k;
	cout<<"\nEnter value of k (less than 10)\n";	//input k
	scanf("%d", &k);
	int arr[50];
	FILE *fp;
	fp = fopen("Output.txt", "a");
	char temp1[50][10], temp2[50][10]; 
	for(i=0 ; i<Ccount ; i++){
		strcpy(temp1[i], girl[i].name);
		strcpy(temp2[i], boy[i].name);
		arr[i] = couple[i].C_happy;
	}
	MySort2 (temp1, temp2, arr);		//sorting couples on the basis of happiness
	fputs("\n\n\nk Happiest Couples\n", fp); 
	for (i=0 ; i<k ; i++) {
		fputs(temp1[i], fp);
		fputs("\t", fp);		//writing K happiest couples to "Output.txt"
		fputs(temp2[i], fp);
		fputs("\tHappiness: ", fp);;
		fprintf(fp, "%d\n", arr[i]);
	}
	for(i=0 ; i<Ccount ; i++) {
		strcpy(temp1[i], girl[i].name);
		strcpy(temp2[i], boy[i].name);
		arr[i] = couple[i].compatibility;
	}
	MySort2 (temp1, temp2, arr);		//sorting couples on the basis of happiness
	fputs("\n\n\nk Most Comatible Couples\n", fp);
	for (i=0 ; i<k ; i++) {
		fputs(temp1[i], fp);		//writing K most compatible couples to "Output.txt"
		fputs("\t", fp);
		fputs(temp2[i], fp);
		fputs("\tCompatibility: ", fp);
		fprintf(fp, "%d\n", arr[i]);
	}
	fclose(fp);
}
collection::collection(){

	FILE *fp;
	int i, j, k, cost, value, flag;
	fp = fopen ("gifts.txt", "r+"); 		//reading gift attributes from "gifts.txt"
	for (i=0 ; i<100 ; i++) {
		fscanf(fp, "%s %d %d %d %d %d %d %d", gift[i].giftID,  &gift[i].type, &gift[i].price, &gift[i].value, &gift[i].l_diff, &gift[i].l_rate, &gift[i].u_value, &gift[i].u_class);
	}
	Gfcount = i;
	fclose(fp);
	fp = fopen("CoupleInfo.txt", "r");		//reading girls and boys information from "CoupleInfo.txt"
	for (i=0 ; i<10 ; i++){
		fscanf( fp, "%s %d %d %d %d %d %d %s %d %d %d %d %d %d", girl[i].name, &girl[i].attractiveness, &girl[i].maintenance, &girl[i].intelligence, &girl[i].criteria, &girl[i].type, &girl[i].status, boy[i].name, &boy[i].attractiveness, &boy[i].budget, &boy[i].intelligence, &boy[i].beautyReqd, &boy[i].type, &boy[i].status);
	}

	fclose(fp);
	Bcount = i;
	Gcount = i;
	Ccount = i;

	fp = fopen("Output.txt", "w+");
	char temp[200][10];
	int arr[200][3];
	for(i=0 ; i<Gfcount ; i++){
		strcpy(temp[i], gift[i].giftID);
		arr[i][0] = gift[i].price;
		arr[i][1] = gift[i].type;
		arr[i][2] = gift[i].value;
	}


	MySort1(temp, arr, 0);

	for (i=0 ; i<Ccount ; i++){		//Exchanging gifts
		flag=0;
		cost=0;
		value=0;
		int BGT = boy[i].budget;
		int main = girl[i].maintenance;
		int bt = boy[i].type;
		int gt = girl[i].type;

		fputs(girl[i].name, fp);
		if(gt == 0)
			fputs("(Choosy)", fp);		//writing in "Output.txt"
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
		if(bt == 1){						//calculating toatal cost for Generous boy
			for (j=Gfcount-1 ; j>=0 ; j--){
				if(cost + arr[j][0] <= BGT) {
					cost = cost + arr[j][0];
					if (arr[j][1] == 2 && gt == 0)
						value = value + 2*arr[j][2];
					else
						value = value + arr[j][2];
					char tmp[10];				//Alotting gifts from most exensive
					if(arr[j][1] == 0)
						strcpy(tmp, "Normal");
					else if(arr[j][1] == 1)
						strcpy(tmp, "Luxury");
					else
						strcpy(tmp, "Utility");
					fputs("\t Gift ID: ", fp);
					fputs(temp[j], fp);
					fputs(", Price: ", fp);			//writing information about Gifts given to "Output.txt"
					fputs(", Value: ", fp);
					fputs(", Type: ", fp);
					fputs(tmp, fp);
					time_t now = time(0); 
					char *ct = ctime(&now); 
					fputs("\t\t\t", fp);
					fputs(ct, fp);
					fputs("\n", fp);
					flag=1;
				}
			}

		}
		else if(bt == 2){					//calculating toatal cost for Geeky boy
			for (j=0 ; j<Gfcount ; j++){
				if(arr[j][1] == 1) {
					if(cost + arr[j][0] <= BGT) {
						cost = cost + arr[j][0];
						if(gt == 0)
							value = value + 2*arr[j][2];
						else
							value = value + arr[j][2];	//finding and allotting an affordable Luxury gift
						char tmp[10];
						if(arr[j][1] == 0)
							strcpy(tmp, "Normal");
						else if(arr[j][1] == 1)
							strcpy(tmp, "Luxury");
						else
							strcpy(tmp, "Utility");
						fputs("\t Gift ID: ", fp);
						fputs(temp[j], fp);
						fputs(", Price: ", fp);
						fputs(", Value: ", fp);		//writing information about Gifts given to "Output.txt"
						fputs(", Type: ", fp);
						fputs(tmp, fp);
						time_t now = time(0); 
						char *ct = ctime(&now); 
						fputs("\t\t\t", fp);
						fputs(ct, fp);
						fputs("\n", fp);
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
					value = value + arr[j][2];		//Finding and allotting gift staring from cheapest
					char tmp[10];
					if(arr[j][1] == 0)
						strcpy(tmp, "Normal");
					else if(arr[j][1] == 1)
						strcpy(tmp, "Luxury");
					else
						strcpy(tmp, "Utility");
					fputs("\t Gift ID: ", fp);
					fputs(temp[j], fp);
					fputs(", Price: ", fp);
					fputs(", Value: ", fp);			//writing information about Gifts given to "Output.txt"
					fputs(", Type: ", fp);
					fputs(tmp, fp);
					time_t now = time(0); 
					char *ct = ctime(&now); 
					fputs("\t\t\t", fp);
					fputs(ct, fp);
					fputs("\n", fp);
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
					char tmp[10];				//Finding and allotting gift staring from cheapest
					if(arr[j][1] == 0)
						strcpy(tmp, "Normal");
					else if(arr[j][1] == 1)
						strcpy(tmp, "Luxury");
					else
						strcpy(tmp, "Utility");
					fputs("\t Gift ID: ", fp);
					fputs(temp[j], fp);			//writing information about Gifts given to "Output.txt"
					fputs(", Price: ", fp);
					fputs(", Value: ", fp);
					fputs(", Type: ", fp);
					fputs(tmp, fp);
					time_t now = time(0); 
					char *ct = ctime(&now); 
					fputs("\t\t\t", fp);
					fputs(ct, fp);
					fputs("\n", fp);
					flag=1;
				}
				if(cost >= main)
					break;
			}
		}
		if(flag==0){						//calculating toatal cost for Miser boy
				boy[i].budget = arr[0][0];
			cost = arr[0][0];
			value = arr[0][1];			
		}

		couple[i].Cost = cost;
		couple[i].Value = value;
		fputs("Total Cost: ", fp);		//writing Total Cost to "Output.txt"
		fprintf(fp, "%d\t\t:", cost);
		fputs("Total Value: ", fp);		//Writing Total Value to "Ouput.txt"
		fprintf(fp, "%d\n\n:", value);
	}
	fputs("------------------------------------------------------------------------------------------------------------------------", fp);
	fclose(fp);
	calculate();		//calling function calculate
}
