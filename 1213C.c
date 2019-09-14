#include<stdio.h>
#include<stdlib.h>

typedef unsigned long long llu;

int main(){
	int q;
	scanf("%d", &q);

	while(q--){
		llu n, m, sum = 0;
		int *cycles; 
		int clock = 1, clock_sum = 0;
		int j = 0;
		scanf("%I64u %I64u", &n, &m);
		
		cycles = malloc(sizeof(int) * clock);
		cycles[0] = (int)(m % 10);
		clock_sum = cycles[0];

		for(llu i = 2 * m; i % 10 != cycles[0]; i += m){
			clock += 1;
			cycles = realloc(cycles, sizeof(int) * clock);

			cycles[clock - 1] = (int)(i % 10);
			clock_sum += cycles[clock - 1];
		}

		sum += (n / (clock * m)) * clock_sum;

		for(llu i = (clock * m) * (n / (clock * m)) + m; i <= n; i += m) 
			sum += cycles[j++];

		free(cycles);

		printf("%I64u\n",sum);
	}
	return 0;
}
