#include<stdio.h>
#include<stdlib.h>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n, *a, min = 0x7FFFFFFF, bad = 0;
		scanf("%d", &n);
		a = malloc(sizeof(int) * n);
		for(int i = 0; i < n; i++) 
			scanf("%d", a + i);
		for(int i = n - 1; i >= 0; i--){
			bad += (a[i] > min);
			min = (-(a[i] < min) & a[i]) + (-(a[i] >= min) & min);
		}
		free(a);
		printf("%d\n", bad);
	}
}
