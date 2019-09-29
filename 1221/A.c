#include<stdio.h>

int msb(int x){
    int power = -1;
    while(x){
        x >>= 1;
        power += 1;
    }
    return power;
}

int main(){
    int q;
    scanf("%d", &q);

    while(q--){
        int n;
        int powers[30] = {0};

        scanf("%d", &n);

        for(int i = 0; i < n; i++){
            int val;
            scanf("%d", &val);
            powers[msb(val)] += 1;
        }

        for(int i = 1; i <= 11; i++){
            powers[i] += (powers[i - 1] >> 1);
        }

        if(powers[11])
            printf("YES\n");
        else
            printf("NO\n");
        
    }

    return 0;
}
