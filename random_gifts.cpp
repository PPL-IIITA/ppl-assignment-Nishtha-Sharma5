//generates random attributes of different type of gifts
#include<bits/stdc++.h>
using namespace std;

int main(){
	int i;
	int value;
	int price;
	int type;
	int l_diff;
	int l_rate;
	int u_value;
	int u_class;
	FILE *fp;
	fp = fopen("gifts.txt", "w+");
	for (i=0 ; i<100 ; i++) {
		type = rand()%3;
		if (type == 0) {
			value = 1+rand()%20;
			price = 1+rand()%20;
			l_diff = -1;
			l_rate = -1;
			u_value = -1;
			u_class = -1;
		}
		else if(type == 1){
			value = 30+rand()%20;
			price = 30+rand()%20;
			l_diff = 5+rand()%10;
			l_rate = 5+rand()%10;
			u_value = -1;
			u_class = -1;
		}
		else {
			value = 20+rand()%20;
			price = 20+rand()%20;
			l_diff = -1;
			l_rate = -1;
			u_value = 5+rand()%10;
			u_class = 5+rand()%10;

		}
		fprintf(fp, "Gift%d %d %d %d %d %d %d %d\n", i, type, price, value, l_diff, l_rate, u_value, u_class);
	}
	fclose(fp);
	return 0;
}
