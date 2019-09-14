#include<stdio.h>
#include<string.h>

int log2N(int x){
	int ret = 0;
	while(x){
		x >>= 1;
		ret += 1;
	}
	return ret;
}
int main(){

	int T;
	scanf("%d", &T);

	while(T--){
		char x[100001], y[100001];
		int num_x = 0, num_y = 0;
		int k = 0;
		int minimum = 0x4fffffff;

		scanf("%s", x);
		scanf("%s", y);

		for(int i = 0; x[i] == '1' || x[i] == '0'; i++){
			num_x <<= 1;
			num_x += (x[i] - 48);
		}
		
		for(int i = 0; y[i] == '1' || y[i] == '0'; i++){
			num_y <<= 1;
			num_y += (y[i] - 48);
		}
		//printf("x: %d, y: %d\n", num_x, num_y);

		char *min_rev;

		while(1){
			int s = num_x + (num_y << k);
			int length_s = log2N(s);
			char rev_s[length_s + 1];
			//printf("s: %d, length_s: %d\n", s, length_s);
			
			for(int i = 0; i < length_s; i++){
				rev_s[i] = ((s >> i) & 1) + 48;
			}

			rev_s[length_s] = '\0';

			if(k == 0){min_rev = rev_s;}
			//for(int i = 0; i < length_s; i++){
		//		printf("%d", rev_s[i]);
		//	}
			//printf("rev: %s\n\n", rev_s);
			//printf("\n\n");
			int d = (strcmp(min_rev, rev_s));
			printf("d: %d\n",d);
			if(strcmp(min_rev, rev_s) < 0) break;
			else if(strcmp(min_rev, rev_s) > 0) min_rev = rev_s;

			printf("min: %s, rev; %s\n", min_rev, rev_s);
			k++;
		}
		printf("ans: %s\n", min_rev);

	}
	return 0;
}
