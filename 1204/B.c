#include<stdio.h>

int main(){
    int n, l ,r;
    int maximum, minimum;

    scanf("%d %d %d", &n, &l, &r);

    minimum = ((1 << l) - 1) + (n - l); 
    maximum = ((1 << r) - 1) + ((n - r) * (1 << (r - 1)));

    printf("%d %d", minimum, maximum);

    return 0;
}
