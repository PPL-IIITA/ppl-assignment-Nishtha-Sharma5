/** @brief Random
	* Gnerates random attributes of girls and boys
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,attractiveness, maintenance, intelligence, type, criteria , min_attract, status = 0;
	FILE *fptr, *fpt;
	fptr = fopen("girls.txt", "w+");			//!< Writing in girls.txt
	for (i=0  ;i<10 ; i++) {				//!< Number of girls is 10
		attractiveness = 50 + rand()%50;
		maintenance = 20 + rand()%50;
		intelligence = 50 + rand()%50;
		type = rand()%3;
		criteria = rand()%3;
		fprintf(fptr, "Girl%d %d %d %d %d %d %d\n", i, attractiveness, maintenance, intelligence, criteria, type, status);
	}
	fclose(fptr);
	fpt = fopen("boys.txt", "w");				//!< writing in boys.txt
	for (i=0  ;i<100 ; i++) {				//!< Number of boys is 100
		attractiveness = 50 + rand()%50;
		maintenance = 150 + rand()%50;
		intelligence = 50 + rand()%50;
		min_attract = 50 + rand()%50;
		type = rand()%3;
		fprintf(fpt, "Boy%d %d %d %d %d %d %d\n", i, attractiveness, maintenance, intelligence, min_attract ,type, status);
	}
	fclose(fpt);
	return 0;
}
