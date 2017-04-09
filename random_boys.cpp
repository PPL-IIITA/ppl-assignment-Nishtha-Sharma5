/** @brief Random
	* Gnerates random attributes of 15 boys
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,index;
	FILE *fpt;
	fpt = fopen("boys2.txt", "w");				//!< writing in boys.txt
	for (i=0  ;i<15 ; i++) {
		index = rand()%100 - 15;				//!< index
		fprintf(fpt, "Boy%d\n", index);
	}
	fclose(fpt);
	return 0;
}
