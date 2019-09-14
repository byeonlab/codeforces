#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	int *a, *appearance;
	
	scanf("%d", &n);
	a = malloc(n * sizeof(int));
	appearance = calloc(n, sizeof(int));

	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		for(int j = 0; j < i; j++){
			if(a[j] == a[i]){
				appearance[i] += a[i];
				a[i]
			}
		}
	}




}
