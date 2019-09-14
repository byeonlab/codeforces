#include<stdio.h>
#include<stdlib.h>

int *to_set(int *sorted_arr, int size){
	int size_unique = size;
	int *unique_arr = malloc(sizeof(int) * size_unique);

	for(int i = 0; i < size; i++)
		unique_arr[i] = sorted_arr[i];

	for(int i = 0; i < size_unique - 1; i++){
		if(unique_arr[i] == unique_arr[i + 1]){
			for(int j = i + 1; j < size_unique - 1; j++){
				unique_arr[j] = unique_arr[j + 1];
			}
			size_unique--;
			i--;
		}
	}
	unique_arr = realloc(unique_arr, sizeof(int) * size_unique);

	return unique_arr;
}

int get_sequence(int *unique_arr, int num){
	for(int i = 0; i < (sizeof(unique_arr) / sizeof(int)); i++){
		if(unique_arr[i] >= num)
			return i;
	}

	return - 1;
}

int to_sequential(int *unique_arr, int *sorted_arr){
	int seq = 0;
	for(int i = 0; i < 9; i++){
		for(int j = 0; j < 6; j++){
			if(sorted_arr[i] == unique_arr[j]) sorted_arr[i] = j;
		}
	}

	return 0;
}

int to_sequential2(int *sorted_arr, int size){
	int seq = 0, prev = sorted_arr[0];
	sorted_arr[0] = seq;
	for(int i = 1; i < size; i++){
		if(sorted_arr[i] == prev) {
			sorted_arr[i] = seq;
		}
		else{
			prev = sorted_arr[i];
			sorted_arr[i] = ++seq;
		}
	}

	return 0;
}

int main(){
	int tst[9] = {1, 1, 2, 2, 3, 4, 6, 9, 9};
	//int *set_tst = to_set(tst, 9);
	//int u_i = 6;
	to_sequential2(tst, 9);

	printf("to_seq: ");
	for(int i = 0; i < 9; i++)
		printf("%d ", tst[i]);
	printf("\n");
	int n;
	int *array, *visited, size_visited = 0;
	int maximum = 0;

	scanf("%d", &n);
	array = malloc(sizeof(int) * n);
	visited = calloc(n, sizeof(int));

	for(int i = 0; i < n; i++)
		scanf("%d", array + i);

	for(int i = 0; i < n; i++){
		//clean_array(visited, n);
		int len = 0;

		for(int j = 0 ; j <= i; j++){
			int done = 0;
			for(int k = 0; k < n; k++){
				if(array[j] == visited[k]){
					done = 1;
					break;
				}
			}
			if(done) 
				break;
			visited[size_visited++] = array[j];
			len++;
		}

		for(int j = n - 1 ; j > i; j--){
			int done = 0;
			for(int k = 0; k < n; k++){
				if(array[j] == visited[k]){
					done = 1;
					break;
				}
			}
			if(done) 
				break;
			visited[size_visited++] = array[j];
			len++;
		}

		maximum = (maximum & -(maximum >= len)) + (len & -(len > maximum));
	}

	free(array);
	free(visited);

	printf("%d", n - maximum);

	return 0;
}
