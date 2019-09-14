#include<stdio.h>
#include<stdlib.h>

int compare(const void *num1, const void *num2){
	int n1 = *(int *)num1;
	int n2 = *(int *)num2;

	return (n1 > n2) - (n1 < n2);
}

int main(){
	int n, k; 
	int *a, *operations, *counts;
	int min = 0x7FFFFFFF;

	scanf("%d %d", &n, &k);

	a = malloc(sizeof(int) * n);
	operations = calloc(200001, sizeof(int));
	counts = calloc(200001, sizeof(int));

	for(int i = 0; i < n; i++){
		scanf("%d", a + i);
		counts[a[i]] += 1;
	}

	//qsort(a, n, sizeof(int), compare);

	for(int i = 0; i < n; i++){

		int count = counts[i];
		while(count){
			int opers = 0;

			while(a[i]){
				if(counts[a[i]] >= k && operations[a[i]] < min){
					min = operations[a[i]];
				}

				a[i] >>= 1;
				opers ++;
				if(counts[a[i]] < k){
					counts[a[i]] += 1;
					operations[a[i]] += opers;
				}
			}
			count -= 1;
		}
	}

	if(operations[0] < min) min = operations[0];
	
	free(a);
	free(operations);
	free(counts);

	printf("%d", min);

	return 0; 

}
