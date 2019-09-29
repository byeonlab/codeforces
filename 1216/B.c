#include<stdio.h>
#include<stdlib.h>

int comp(const void *a, const void *b){
    int n1 = *(int *)a;
    int n2 = *(int *)b;

    return (n1 > n2) - (n2 < n1);
}

int max_index(int *a, int n){
    int maximum = 0;

    for(int i = 0; i < n; i++){
        int new_max = (a[maximum] < a[i]);
        maximum = (maximum & -(!new_max)) + (i & -new_max);
    }

    return maximum;
}

int main(){
    int n;
    int *a, *seq;
    int sum = 0;

    scanf("%d", &n);
    a = malloc(sizeof(int) * n);
    seq = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++)
        scanf("%d", a + i);

    //qsort(a, n, sizeof(int), comp);

    for(int i = 0; i < n; i++){
        int max_i = max_index(a, n);
        sum += (a[max_i] * i) + 1;
        a[max_i] = 0;
        seq[i] = max_i + 1;
    }

    printf("%d\n", sum);
    for(int i = 0; i < n; i++)
        printf("%d ", seq[i]);

    free(a);
    free(seq);
    return 0;
}
