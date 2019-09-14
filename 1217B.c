#include<stdio.h>
#include<stdlib.h>

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		int n, x;
		int *d, *h;
		int max_d = 0, max_d_h = 0;

		int defeatable = 0;
		int minimum = 0;

		scanf("%d %d", &n, &x);

		d = malloc(sizeof(int) * n);
		h = malloc(sizeof(int) * n);

		for(int i = 0; i < n; i++){
			scanf("%d %d", d + i, h + i);
			max_d = (d[i] & -(d[i] > max_d)) + (max_d & -(d[i] <= max_d));
			max_d_h = ((d[i] - h[i]) & -((d[i] - h[i] > max_d_h))) + (max_d_h & -((d[i] - h[i]) <= max_d_h));
		}

		free(d);
		free(h);
		
		defeatable = (max_d_h > 0) | (max_d >= x);
		if(defeatable){
			if(max_d >= x) printf("1\n");
			else printf("%d\n", ((x - max_d) / max_d_h) + (((x - max_d) % max_d_h) > 0) + 1);

		}
		else
			printf("-1\n");
	}

	return 0;
}
