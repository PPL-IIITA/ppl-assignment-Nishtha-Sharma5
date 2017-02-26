//Gnerates random attributes of girls and boys
#include<bits/stdc++.h>
using namespace std;
int main(){
	int i,attractiveness, maintenance, intelligence, type, criteria , min_attract, status = 0;
	FILE *fptr, *fpt;
	fptr = fopen("girls.txt", "w+");
	for (i=0  ;i<10 ; i++) {
		attractiveness = 50 + rand()%50;
		maintenance = 20 + rand()%50;
		intelligence = 50 + rand()%50;
		type = rand()%3;
		criteria = rand()%3;
		fprintf(fptr, "Girl%d %d %d %d %d %d %d\n", i, attractiveness, maintenance, intelligence, criteria, type, status);
	}
	fclose(fptr);
	fpt = fopen("boys.txt", "w");
	for (i=0  ;i<100 ; i++) {
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
