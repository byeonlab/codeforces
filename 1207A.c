#include<stdio.h>

int maximum(int x, int y){
	return (x & -(x > y)) + (y & -(x <= y));
}

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		int b, p, f;
		int h, c;
		int profit = 0;

		int expensive, cheap;

		scanf("%d %d %d", &b , &p, &f);
		scanf("%d %d", &h, &c);

		if(h > c){
			while(b >= 2 && p > 0){
				b -= 2;
				p -= 1;
				profit += h;
			}
			while(b >= 2 && f > 0){
				b -= 2;
				f -= 1;
				profit += c;
			}
		}else{
			while(b >= 2 && f > 0){
				b -= 2;
				f -= 1;
				profit += c;
			}
			while(b >= 2 && p > 0){
				b -= 2;
				p -= 1;
				profit += h;
			}

		}

 		printf("%d\n", profit);
	}

	return 0;
}
