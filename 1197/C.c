#include<stdio.h>
#include<stdlib.h>

int compare(const void *num1, const void *num2){
    int n1 = *(int *)num1;
    int n2 = *(int *)num2;

    return (n1 > n2) - (n2 > n1);
}

int sum_of_arr(int *arr, int from, int to){
    int sum = 0;

    for(int i = from; i < to; i++)
        sum += arr[i];

    return sum;
}

int main(){
    int n, k;
    int *a, *diffs;

    scanf("%d %d", &n ,&k);
    a = malloc(sizeof(int) * n);
    diffs = calloc(n, sizeof(int));

  
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    for(int i = 1; i < n; i++)
        diffs[i] = a[i] - a[i - 1];

    qsort(diffs, n, sizeof(int), compare);

    printf("%d", a[n - 1] - a[0] - sum_of_arr(diffs, n - k + 1, n));

    free(diffs);
    free(a);

    return 0;
}
