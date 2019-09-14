#include<stdio.h>
#include<stdlib.h>

int static compare (const void* first, const void* second){
	return (*(int*)first > *(int*)second) - (*(int*)first < *(int*)second);                                        
 } 

int main(){
	int q;
	scanf("%d", &q);

	while(q--){
		int n;
		int *a;
		int impossible = 0;
		int area;
		scanf("%d", &n);
		a = malloc(4 * n * sizeof(int));

		for(int i = 0; i < 4 * n; i++) 
			scanf("%d", a + i);

		qsort(a, 4 * n, sizeof(int), compare);
		area = a[0] * a[4 * n - 2];

		for(int i = 0; i < 2 * n; i += 2){
			impossible += ((a[i] * a[4 * n - (2 + i)]) != area);
		}

		if(impossible) printf("NO\n");
		else printf("YES\n");
		free(a);
	}

	return 0;
}
