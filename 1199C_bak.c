#include<stdio.h>
#include<stdlib.h>

int static compare (const void* first, const void* second){
	return (*(int*)first > *(int*)second) - (*(int*)first < *(int*)second);
}
int l_cnt(int *n){
	*n = *n + 1;
	return *n;
}
int r_cnt(int *n){
	*n = *n - 1;
	return *n;
}
int count_edge(int (*f)(int*), int *arr, int pos){
	int ret = 1;
	while(arr[pos] == arr[f(&pos)]){
		ret += 1;
	}
	return ret;
}
int count_distinct(int *arr, int size){
	int cnt = 1;
	for(int i = 1; i < size ; i++) cnt += (arr[i - 1] != arr[i]);
	//printf("distinct: %d\n", cnt);
	return cnt;
}
int log2N(int N){
	//printf("N: %d, ", N);
	if(N == 1) return 0;
	int ret = 0;
	int comp = 1;
	N -= 1;
	//while(N > comp){
	//	ret++;
	//	//N >>= 1;
	//	comp <<= 1;

	//}
	while(N){
		ret++;
		//N >>= 1;
		N >>= 1;

	}
	//printf("log: %d\n", ret );
	return ret;
}

int main(){
	int n, bytes, *arr, l, r;
	scanf("%d %d", &n, &bytes);
	arr = malloc(sizeof(int) * n);

	for(int i = 0; i < n; i++) scanf("%d", arr + i);
	qsort(arr, n, sizeof(int), compare);

	int *consecutives, distincts = count_distinct(arr, n);
	consecutives = malloc(distincts * sizeof(int));

	int distinct = 0;
	int count = 1;
	for(int i = 0; i < n; i++){
		if(arr[i] != arr[i + 1]){
			consecutives[distinct++] = count;
			count = 0;
		}
		count ++;
	}
	l = 0;
	r = distincts - 1;
	//printf("consecutives: ");
	//for(int i = 0; i < distincts; i++) printf("%d ", consecutives[i]);
	//printf("\n");
	int changed = 0;
	while(log2N(distincts) * n > bytes * 8){
		int l_gap = consecutives[l], r_gap = consecutives[r];
		//printf("l: %d, r: %d\n", l_gap, r_gap);
		changed += (-(l_gap > r_gap) & r_gap) + (-(l_gap <= r_gap) & l_gap);
		distincts -= 1;
		r -= (l_gap > r_gap);
		l += (l_gap <= r_gap);
	}
	printf("%d", changed);
	
	return 0;
}
