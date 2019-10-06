#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    int *a;

    int max_i = 0;
    int exist[200001] = {0};
    int dup = 0;
    int not_ok = 0;

    scanf("%d", &n);
    a = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++){
        scanf("%d", a + i);
        dup += exist[a[i]];
        exist[a[i]] = 1;
        max_i = (i & -(a[i] > a[max_i])) + (max_i & -(a[i] < a[max_i]));
    }

    for(int i = 0; i < max_i; i++)
        not_ok += (a[i] >= a[i + 1]);

    for(int i = max_i + 1; i < n; i++)
        not_ok += (a[i] >= a[i - 1]);

    free(a);

    if(dup | not_ok)
        printf("NO");
    else
        printf("YES");

    return 0;
}
