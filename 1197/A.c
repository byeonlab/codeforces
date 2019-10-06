#include<stdio.h>

int minimum(int a, int b){
    return (a & -(a <= b)) + (b & -(b < a));
}

int main(){
    int T;
    
    scanf("%d", &T);

    while(T--){
        int n;
        int base1 = 0, base2 = 0;
        
        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            int a;
            int a_ge_base1 = 0, a_ge_base2 = 0;

            scanf("%d", &a);

            a_ge_base1 = (a >= base1);
            a_ge_base2 = !a_ge_base1 & (a >= base2);

            base2 = (base1 & -a_ge_base1) + (base2 & -!a_ge_base1);
            base1 = (a & -a_ge_base1) + (base1 & -!a_ge_base1);
            base2 = (a & -a_ge_base2) + (base2 & -!a_ge_base2);
        }
        printf("%d\n", minimum((minimum(base1, base2) - 1), n - 2));
    }

    return 0;
}
