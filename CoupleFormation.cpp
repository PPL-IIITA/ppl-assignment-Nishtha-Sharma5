#include "CoupleFormation.h" 			//!< including header file CoupleFormation
#include<bits/stdc++.h>

using namespace std;

int Gcount;
int Bcount;
/** @brief class CoupleFormation
	* Forms couple for girls
	* method as stated in question 1
*/

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
CoupleFormation::CoupleFormation()
{
	int i;
    	INPUT CF(girl, boy);
	Gcount = CF.Gcount;
	Bcount = CF.Bcount;
    	int j,k, w=0, flag, in;
    	char temp[100][10];
    	int arr[100][3];
    	for (i=0 ; i<Bcount ; i++){ 						//!< pushing boy attributes in array
        	strcpy(temp[i], boy[i].name); 
        	arr[i][0] = boy[i].attractiveness;
        	arr[i][1] = boy[i].budget;
        	arr[i][2] = boy[i].intelligence;
    	}
	FILE *fpt;
	fpt = fopen("CoupleInfo.txt", "w");
	//fputs("", fpt);
    	for (i=0 ; i<Gcount ; i++){ 						//!< loop runs for all girls
            	flag = 0;
		if(girl[i].status == 0) {
                    	MySort(temp, arr, girl[i].criteria); 			//!< Sorting Function called
                    	for(j=Bcount-1 ; j>=0 ; j--) {
                        	for(k=0 ; k<Bcount ; k++){
                            		if(strcmp(temp[j],boy[k].name) == 0){ 					//!< allotting boyfriend to ith girl
                                		if(boy[k].status == 0 && girl[i].attractiveness >= boy[k].beautyReqd && girl[i].maintenance <= boy[k].budget) {
							strcpy(couple[w].Gname, girl[i].name); 			//!< writing girl name to couple girl name
							strcpy(couple[w].Bname, boy[k].name); 			//!< wrinting boy name to couple boy name
                                    			girl[i].status = 1; 					//!< girl status changes to committed
                                    			boy[k].status = 1; 					//!< boy status changes to committed
							couple[w].GMaint = girl[i].maintenance;
							couple[w].BBudget = boy[k].budget;			//!< writing details about the couple formed in 'CoupleInfo.txt'
							fprintf(fpt, "Girl%d %d %d %d %d %d %d ", i, girl[i].attractiveness, girl[i].maintenance, girl[i].intelligence, girl[i].criteria, girl[i].type, girl[i].status);
							fprintf(fpt, "Boy%d %d %d %d %d %d %d\n",k, boy[k].attractiveness, boy[k].budget, boy[k].intelligence, boy[k].beautyReqd, boy[k].type, boy[k].status);
                                    			w++;
                                    			flag=1;
                                		}
                                    		break;
                            		}
                        	}
                        	if(flag == 1)
                                    	break;
                    	}
            	}
    	}
	fclose(fpt);
    	Ccount = w; 							//!< updating total no. of couples
	FILE *fp; 							//!< writing output in "Output1.txt"
	fp = fopen("Output1.txt", "w");
    	for (i=0 ; i<Ccount ; i++) {
		fputs(couple[i].Gname, fp);
		fputs("\twith\t", fp);
		fputs(couple[i].Bname, fp);
		time_t now = time(0); 					//!< adding time stamp
		char *ct = ctime(&now); 
		fputs("\t\t", fp);
		fputs(ct, fp);
		fputs("\n", fp);
    	}
	fclose(fp);
}
