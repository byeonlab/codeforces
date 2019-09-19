#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    int ones, zeros = 0;
    char *bin;

    scanf("%d", &n);
    bin = malloc(sizeof(int) * (n + 1));
    scanf("%s", bin);

    for(int i = 0; i < n; i++){
        zeros += (bin[i] == 'z');
    }
    ones = (n - (zeros * 4)) / 3;
    
    for(int i = ones; i > 0; i--)
        printf("1 ");

    for(int i = zeros; i > 0; i--)
        printf("0 ");

    free(bin);
    return 0;
}
