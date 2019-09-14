#include<stdio.h>
#include<stdlib.h>

int is_clockwise(int *arr, int size){
	for(int i = 0; i < size - 1; i++){
		if(arr[i] + 1 != arr[i + 1]){
			for(int j = i + 1; j < size - 1; j++){
				if(arr[j] + 1 != arr[j + 1]) return 0;
			}
		}
	}
	return 1;
}
int is_counterclockwise(int *arr, int size){
	for(int i = 0; i < size - 1; i++){
		if(arr[i] - 1 != arr[i + 1]){
			for(int j = i + 1; j < size - 1; j++){
				if(arr[j] - 1 != arr[j + 1]) return 0;
			}
		}
	}
	return 1;
}

int main() {
	int q;

	scanf("%d", &q);

	while(q--){
		int n, *order;

		scanf("%d", &n);
		order = malloc(n * sizeof(int));

		for(int i = 0; i < n; i++) 
			scanf("%d", order + i);

		if(is_clockwise(order, n) || 
		   is_counterclockwise(order,n)) { 
			printf("YES\n");
		} else printf("NO\n");
	}
	return 0;
}
