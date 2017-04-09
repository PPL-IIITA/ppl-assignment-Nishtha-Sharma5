#include "CoupleFormation2.h" 			//including header file CoupleFormation2
#include<bits/stdc++.h>
using namespace std;
/** @brief class CoupleFormation2
* Rather than making couples by taking girls one by one as in question 1, we create a different mechanism. First
* one girl chooses a boy, then one boy choses a girl, and so on. The girl list is ordered by maintenance cost, while
* the boy list is ordered by attractiveness. The boys always chose the most attractive available girl. 
* Print the happiest k couples.
*/
int Gcount;			//!< number of girls
int Bcount;			//!< number of boys


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
void MySort1(char temp[10][10], int a[10]){ 				//!< Function to sort girl according ot attractiveness
	int i, j, tmp;
	for(j=0; j<Gcount; j++){
		for(i=0 ; i<(Gcount-j-1) ; i++){
			if(a[i]>a[i+1]){
                		swap(a[i], a[i+1]);
                		swap(temp[i], temp[i+1]);
			}
		}
	}
}
CoupleFormation2::CoupleFormation2()
{
	int i;
    	INPUT CF(girl, boy);
	Gcount = CF.Gcount;
	Bcount = CF.Bcount;
    	int j,k, w=0, flag, in;
    	char temp[100][10], temp2[10][10];
    	int arr[100][3], art[10];
    	for (i=0 ; i<Bcount ; i++){ 						//!< pushing boy attributes in array
        	strcpy(temp[i], boy[i].name); 
        	arr[i][0] = boy[i].attractiveness;
        	arr[i][1] = boy[i].budget;
        	arr[i][2] = boy[i].intelligence;
    	}
	for (i=0 ; i<Gcount ; i++){ 						//!< pushing girl attributes in array
        	strcpy(temp2[i], girl[i].name); 
        	art[i] = girl[i].attractiveness;
    	}
	for(j=0; j<Gcount; j++){
		for(i=0 ; i<(Gcount-j-1) ; i++){
			if(girl[i].maintenance > girl[i+1].maintenance)
				swap(girl[i], girl[i+1]);
		}
	}
	for(j=0; j<Bcount; j++){
		for(i=0 ; i<(Bcount-j-1) ; i++){
			if(boy[i].attractiveness > boy[i+1].attractiveness)
				swap(boy[i], boy[i+1]);
		}
	}
	FILE *fpt;
	fpt = fopen("CoupleInfo.txt", "w");
	int m;
	for(m=0 ; m<5 ; m++) {
		flag = 0;
    		for (i=0 ; i<Gcount ; i++){ 						//!< loop runs for one
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
								fputs(girl[i].name, fpt);
								fprintf(fpt, " %d %d %d %d %d %d ", girl[i].attractiveness, girl[i].maintenance, girl[i].intelligence, girl[i].criteria, girl[i].type, girl[i].status);
								fputs(boy[k].name, fpt);							
								fprintf(fpt, " %d %d %d %d %d %d\n", boy[k].attractiveness, boy[k].budget, boy[k].intelligence, boy[k].beautyReqd, boy[k].type, boy[k].status);
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
			if(flag == 1)
                	 	break;
    		}
		flag = 0;
		for (i=0 ; i<Bcount ; i++){ 						//!< loop runs for one boy
			if(boy[i].status == 0) {
        	            	MySort1(temp2, art);					//!< Sorting Function called
       		             	for(j=Gcount-1 ; j>=0 ; j--) {
       		                 	for(k=0 ; k<Gcount ; k++){
        	                    		if(strcmp(temp2[j],girl[k].name) == 0){ 					//!< allotting boyfriend to kth girl
        	                        		if(girl[k].status == 0 && girl[k].attractiveness >= boy[i].beautyReqd && girl[k].maintenance <= boy[i].budget) {
								strcpy(couple[w].Gname, girl[k].name); 			//!< writing girl name to couple girl name
								strcpy(couple[w].Bname, boy[i].name); 			//!< wrinting boy name to couple boy name
        	                            			girl[k].status = 1; 					//!< girl status changes to committed
        	                            			boy[i].status = 1; 					//!< boy status changes to committed
								couple[w].GMaint = girl[k].maintenance;
								couple[w].BBudget = boy[i].budget;			//!< writing details about the couple formed in 'CoupleInfo.txt'
								fputs(girl[k].name, fpt);
								fprintf(fpt, " %d %d %d %d %d %d ", girl[k].attractiveness, girl[k].maintenance, girl[k].intelligence, girl[k].criteria, girl[k].type, girl[k].status);
								fputs(boy[i].name, fpt);							
								fprintf(fpt, " %d %d %d %d %d %d\n", boy[i].attractiveness, boy[i].budget, boy[i].intelligence, boy[i].beautyReqd, boy[i].type, boy[i].status);
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
			if(flag == 1)
        		       	break;
    		}
	}
	fclose(fpt);
    	Ccount = w; 							//!< updating total no. of couples
	FILE *fp; 							//!< writing output in "Output5.txt"
	fp = fopen("Output5.txt", "w");
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
