#include<stdio.h>

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int a, b, c, n, res, ans;
		
		scanf("%d %d %d", &a, &b, &n);

		res = n % 3;
		
		c = a ^ b;
		if(res == 0) ans = a;
		else if(res == 1) ans = b;
		else if(res == 2) ans = c;

		printf("%d\n", ans);
	}

	return 0;
}
