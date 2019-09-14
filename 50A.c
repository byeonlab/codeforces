#include<stdio.h>

int main(){
	unsigned M, N, restM, restN;
	scanf("%u %u", &M ,&N);
	restM = M & 1;
	restN = N & 1;

	printf("%u", (((M - restM)) * ((N - restN))) / 2 + (restM  * N / 2) + (restN * M / 2));
	return 0;

}
