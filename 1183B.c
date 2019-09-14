#include<stdio.h>

int main(){

	int q;
	scanf("%d", &q);
	while(q--){
		int n, k, min = 1000000001, max = 0;
		scanf("%d %d", &n, &k);
		while(n--){
			int price;
			scanf("%d", &price);
			if(price < min) min = price;
			if(price > max) max = price;
		}
		if(min + k < max - k) printf("-1\n");
		else printf("%d\n", min + k);
	}
	return 0;
}
