#include<stdio.h>

int f(int x, int cnt){
	if(x < 10) return cnt + 8;
	x += 1;
	while(x % 10 == 0){
		x /= 10;
	}
	return f(x, cnt + 1);
}

int main(){
	int x;
	scanf("%d", &x);
	printf("%d", f(x, 1));
	return 0;
}
