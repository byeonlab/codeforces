#include<stdio.h>
#include<stdlib.h>

int min(int a, int b){
	return (-(a > b) & b) + (-(a <= b) & a);
}

int main(){
	int n, *x, odds = 0, evens = 0;
	scanf("%d", &n);
	x = malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++) {
		scanf("%d", x + i);
		odds += (x[i] & 1);
	}
	evens = n - odds;
	printf("%d", min(odds, evens));
	free(x);
	return 0;
}
