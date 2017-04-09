#include "Breakup.h" 			//including header file Breakup
#include<bits/stdc++.h>

using namespace std;
/** @Brief class breakup
	* The costructor finds the k least happy couples
	* Performs Breakup
	* Makes new couples
	* New couples updated in 'CoupleInfo.txt'
*/
int Gcount;		//!< no. of girls
int Bcount;		//!< no. of boys

/** @Brief Function MySort
	* Function to sort boys according to criteria provided by girl
	* Criteria 0 - Richest
	* Criteria 1 - Most Attractive
	* Criteria 2 - Most Interlligent
*/
void MySort(char temp[100][10], int a[100][3], int index){ 				
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

/** @Brief Function MySort2
	* Function to sort gift by price
	* sorts gifts in asscending order
*/
void MySort2(char temp1[50][10], char temp2[50][10], int a[50]){
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

Breakup::Breakup(int FACTOR)			//!< Constructor Breakup
{
	int i;
    	INPUT CF(girl, boy);			//!< Input info of girls and boys
	Gcount = CF.Gcount;			//!< Update number of girls
	Bcount = CF.Bcount;			//!< Update number of boys
	FILE *fpt;
	fpt = fopen("CoupleInfo2.txt", "r+");	//!< reading from 'CoupleInfo2.txt'
	for(i=0 ; i<10 ; i++)
		fscanf(fpt, "%s %d %s %d %d %d %d %d %d", couple[i].Gname, &couple[i].G_happy, couple[i].Bname, &couple[i].B_happy, &couple[i].GMaint, &couple[i].BBudget, &couple[i].Cost, &couple[i].Value, &couple[i].compatibility);		//!< reading attributes of couples
	fclose(fpt);				
	char temp1[50][10], temp2[50][10];
	int art[50]; 
	for(i=0 ; i<10 ; i++){
		strcpy(temp1[i], couple[i].Gname);
		strcpy(temp2[i], couple[i].Bname);
		art[i] = couple[i].G_happy + couple[i].B_happy;
	}
	MySort2 (temp1, temp2, art);		//!< sorting couples on the basis of happiness
    	int j,k, w=0, flag, in, G_index, B_index;
    	char temp[100][10];
    	int arr[100][3];
    	for (i=0 ; i<Bcount ; i++){ 						//!< pushing boy attributes in array
        	strcpy(temp[i], boy[i].name); 
        	arr[i][0] = boy[i].attractiveness;
        	arr[i][1] = boy[i].budget;
        	arr[i][2] = boy[i].intelligence;
    	}
	fpt = fopen("CoupleInfo.txt", "w");
	FILE *NEW;
	NEW = fopen("Output4.txt", "w+");
    	for (i=0 ; i<FACTOR ; i++){ 						//!< loop runs K least happy couples
            	flag = 0;							//!< performing breakup
		for(j=0 ; j<10 ; j++){
			if(strcmp(temp1[i], girl[j].name) == 0) {		//!< Girl is recogonized
				G_index = j;
				break;
			}
		}
		for(j=0 ; j<100 ; j++){
			if(strcmp(temp2[i], boy[j].name) == 0) {		//!< Boy is recogonized
				B_index = j;
				break;
			}
		}
		girl[G_index].status = 0;					//!< Girl is now single
		boy[B_index].status = 0;					//!< Boy is now single
		MySort(temp, arr, girl[G_index].criteria); 			//!< Sorting Function called
                for(j=Bcount-1 ; j>=0 ; j--) {
                       	for(k=0 ; k<Bcount ; k++){
                       		if(strcmp(temp[j],boy[k].name) == 0){		//!< allotting new boyfriend to girl
                              		if(boy[k].status == 0 && girl[G_index].attractiveness >= boy[k].beautyReqd && girl[G_index].maintenance <= boy[k].budget && k!=B_index) {
                               			girl[G_index].status = 1; 				//!< girl status changes to committed
                               			boy[k].status = 1; 					//!< boy status changes to committed
						fprintf(fpt, "Girl%d %d %d %d %d %d %d ", G_index, girl[G_index].attractiveness, girl[G_index].maintenance, girl[G_index].intelligence, girl[G_index].criteria, girl[G_index].type, girl[G_index].status);
						fprintf(fpt, "Boy%d %d %d %d %d %d %d\n",k, boy[k].attractiveness, boy[k].budget, boy[k].intelligence, boy[k].beautyReqd, boy[k].type, boy[k].status);
                              			flag=1;
						fputs(girl[G_index].name, NEW);
						fputs("\t\tOld Boyfriend: ", NEW);
						fputs(boy[B_index].name, NEW);
						fputs("\t\tNew Boyfriend: ", NEW);
						fputs(boy[k].name, NEW);
						time_t now = time(0); 					//!< adding time stamp
						char *ct = ctime(&now); 
						fputs("\t\t", NEW);
						fputs(ct, NEW);
						fputs("\n", NEW);
                               		}
                               		break;
                       		}
                      	}
                    	if(flag == 1)
                               	break;
		}
    	}
	for(i=FACTOR ; i<10 ; i++) {
		for(j=0 ; j<10 ; j++){
			if(strcmp(temp1[i], girl[j].name) == 0) {			//!< updating CoupleInfo.txt
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
		fprintf(fpt, "Girl%d %d %d %d %d %d %d ", G_index, girl[G_index].attractiveness, girl[G_index].maintenance, girl[G_index].intelligence, girl[G_index].criteria, girl[G_index].type, girl[G_index].status);
		fprintf(fpt, "Boy%d %d %d %d %d %d %d\n",B_index, boy[B_index].attractiveness, boy[B_index].budget, boy[B_index].intelligence, boy[B_index].beautyReqd, boy[B_index].type, boy[B_index].status);

	}
	fclose(NEW);
	fclose(fpt);
	
}
