#include<stdio.h>
#include<stdlib.h>

int lineup(int *snacks, int *x, int *y, int done[100001], int sad, int i, int k, int n){
	for(int j = 1; j <= k; j++){
		if(done[j])
			continue;

		if(x[i] == x[j]){
			if(y[i] != y[j]){
				if(y[j] <= n){
					if(snacks[y[j]]){
						snacks[y[j]] = 0;
						done[j] = 1;
						return lineup(snacks, x, y, done, sad, j, k, n);
					}
				}else{
					done[j] = 1;
					return lineup(snacks, x, y, done, sad + 1, i, k, n);
				}
			}else{
				done[j] = 1;
				return lineup(snacks, x, y, done, sad + 1, i, k, n);
			}
		}
		if(x[i] == y[j]){
			if(y[i] != x[j]){
				if(x[j] <= n){
					if(snacks[x[j]]){
						snacks[x[j]] = 0;
						done[j] = 1;
						return lineup(snacks, x, y, done, sad, j, k, n);
					}
				}else{
					done[j] = 1;
					return lineup(snacks, x, y, done, sad + 1, i, k, n);
				}
			}else{
				done[j] = 1;
				return lineup(snacks, x, y, done, sad + 1, i, k, n);
			}
		}
		if(y[i] == x[j]){
			if(x[i] != y[j]){
				if(y[j] <= n){
					if(snacks[y[j]]){
						snacks[y[j]] = 0;
						done[j] = 1;
						return lineup(snacks, x, y, done, sad, j, k, n);
					}
				}else{
					done[j] = 1;
					return lineup(snacks, x, y, done, sad + 1, i, k, n);
				}
			}else{
				done[j] = 1;
				return lineup(snacks, x, y, done, sad + 1, i, k, n);
			}
		}
		if(y[i] == y[j]){
			if(x[i] != x[j]){
				if(x[j] <= n){
					if(snacks[x[j]]){
						snacks[x[j]] = 0;
						done[j] = 1;
						return lineup(snacks, x, y, done, sad, j, k, n);
					}
				}else{
					done[j] = 1;
					return lineup(snacks, x, y, done, sad + 1, i, k, n);
				}
			}else{
				done[j] = 1;
				return lineup(snacks, x, y, done, sad + 1, i, k, n);
			}
		}
	}
	for(int j = 0; j <= k; j++){
		if(!done[j]){
			if(snacks[x[j]] | snacks[y[j]]){
				snacks[x[j]] = 0;
				snacks[y[j]] = 0;
				done[j] = 1;
				return lineup(snacks,x ,y ,done, sad, j, k, n);
			}
		}
	}
	return sad;
}

int main(){
	int n, k;
	int *snacks;
	int *x, *y;
	int done[100001];
	int sad = 0;

	for(int i = 1; i <= 100000; i++)
		done[i] = 0;

	scanf("%d %d", &n, &k);

	snacks = malloc((n + 1) * sizeof(int));

	for(int i = 1; i <= n; i++)
		snacks[i] = 1;

	x = malloc((k + 1) * sizeof(int));
	y = malloc((k + 1) * sizeof(int));

	for(int i = 1; i <= k; i++){
		scanf("%d %d", x + i, y + i);
	}

	snacks[x[1]] = 0;
	snacks[y[1]] = 0;
	done[1] = 1;

	sad = lineup(snacks, x, y, done, 0, 1, k, n);

	printf("%d", sad);


	free(snacks);
	free(x);
	free(y);

	return 0;

}
