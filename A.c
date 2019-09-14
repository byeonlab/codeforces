#include<stdio.h>

int zero_if_minus(int x);

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int str, inte, exp;
		int cnt = 0;
		scanf("%d %d %d", &str, &inte, &exp);
		
		if(str - inte > exp) printf("%d\n", exp + 1);
		else if(str > inte) {
			if(exp & 1) printf("%d\n", (exp + 1) / 2 + ((str - inte) / 2)) ;
			else printf("%d\n", (exp + 1) / 2 + ((str - inte - 1)) / 2);
		}
		else if(str == inte) printf("%d\n", (exp + 1) / 2 );
		else {
			if(inte - str >= exp) printf("0\n");
			else if(exp & 1) printf("%d\n", (exp + 1) / 2 - ( (inte - str) / 2 ) );
			else printf("%d\n", (exp + 1) / 2 - ( (inte - str) / 2 ) );

		}
	}

	return 0;
}

int zero_if_minus(int x){
	return (0 & -(x < 0)) + (x & -(x > 0));
}
