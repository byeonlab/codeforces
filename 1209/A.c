#include<stdio.h>
#include<stdlib.h>

int comp(const void *num1, const void *num2){
	int n1 = *(int *)num1;
	int n2 = *(int *)num2;

	return (n1 > n2) - (n2 - n1);
}

int main(){
	int n;
	int *e;
	int minimum = 0;
	
	scanf("%d", &n);
	e = malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", e + i);
	
	qsort(e, n, sizeof(int), comp);

	for(int i = 0; i < n; i++){
		if(e[i] == 0) 
			continue;

		for(int j = i + 1; j < n; j++){
			if((e[j] % e[i]) == 0){
				e[j] = 0;
			}
		}
	}

	for(int i = 0; i < n; i++){
		minimum += (e[i] != 0);
	}

	printf("%d", minimum);
	return 0;
}
