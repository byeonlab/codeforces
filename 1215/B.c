#include<stdio.h>
#include<stdlib.h>

int window(int *a, int i, int n, int neg, int pos, unsigned long long *sum_neg, unsigned long long *sum_pos){
    if(i == n) return 0;
    if(a[i] < 0){
        *sum_pos += neg;
        *sum_neg += pos + 1;
        return window(a, i + 1, n, pos + 1, neg, sum_neg, sum_pos);
    }
    
    *sum_pos += pos + 1;
    *sum_neg += neg;
    return window(a, i + 1, n, neg, pos + 1, sum_neg, sum_pos);
}

int main(){
    int n;
    int total;
    int *a;
    unsigned long long neg = 0, pos = 0;

    scanf("%d", &n);
    total = (n * (n + 1)) / 2;
    a = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    window(a, 0, n, 0, 0, &neg, &pos);

    free(a);

    printf("%I64u %I64u", neg, pos);

    return 0;
}
