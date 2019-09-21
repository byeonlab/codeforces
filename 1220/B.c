#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n;
	unsigned long long *M, *a;

	scanf("%d", &n);
	M = malloc(sizeof(unsigned long long) * n * n);
    a = malloc(sizeof(unsigned long long) * n);

    for(int i = 0; i < n * n; i++)
        scanf("%I64u", M + i);

    a[0] = (unsigned long long)sqrt((*(M + 1)) * (*(M + 2)) / (*(M + (n + 2))));
    

    for(int i = 1; i < n; i++)
        a[i] = M[i] / a[0];
        
    for(int i = 0; i < n; i++)
        printf("%I64u ", a[i]);


    free(M);
    free(a);

    return 0;
}
