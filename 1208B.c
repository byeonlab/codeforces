#include<stdio.h>
#include<stdlib.h>

int main(){
 	int n;
	int *arr, *dups;
	int first_dup = 0, last_dup = 0;

	scanf("%d", &n);
	arr = malloc(sizeof(int) * n);
	dups = calloc(n , sizeof(int));

	for(int i = 0; i < n; i++){
		scanf("%d", arr + i);
		for(int j = 0; j < i; j++){
			if(arr[i] == arr[j]){
				dups[i] == arr[i];
				dups[j] = arr[j];
			}
		}
	}

	for(int i = 0; i < n; i++)
		printf("%d,  ", dups[i]);

	printf("\n");


	return 0;

}
