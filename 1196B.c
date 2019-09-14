#include<stdio.h>

int *ptr(int *s1, int *s2, int len_s1, int len_s2);

int has_odd_sum(int *arr, int *borders, int i){
	int sum = 0;
	for(int j = borders[i - 1]; j < borders[i]; j++) 
		sum += borders[j];
	return  sum & 1;
}
int draw_border(int n, int k, int i, int *borders, int *arr){
	borders[i] :	``
}
int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		int n, k *a, *l_borders;
		scanf("%d %d", &n, &k);
		a = malloc(sizeof(int) * n);
		for(int i = 0; i < n; i++) 
			scanf("%d", a + i);


	}
	return 0;
}
