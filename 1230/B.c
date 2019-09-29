#include<stdio.h>
#include<stdlib.h>

int main(){
    int n, k;
    int finish = 0;
    char *S;

    scanf("%d %d", &n, &k);

    S = malloc((n + 1) * sizeof(char));
    scanf("%s", S);


    if(n == 1){
        if(k)
            printf("0");
        else
            printf("%s", S);
    }
    else{
        if(k){
            k -= (S[0] != 49);
            S[0] = 49;
        }
        for(int i = 1; k && i < n; i++){
            int is_not_zero = (S[i] != 48);
            S[i] = 48;
            k -= is_not_zero;
        }
        printf("%s", S);
    }

    free(S);

    return 0;
}
