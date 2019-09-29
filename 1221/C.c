#include<stdio.h>

int min_of_them(int x, int y, int z){
    int min_xy = (x & -(x < y)) + (y & -(x >= y));
    
    return (z & -(z < min_xy)) + (min_xy & -(z >= min_xy));
}

int main(){

    int q;
    scanf("%d", &q);

    while(q--){
        int c, m, x;
        int teams = 0;
        
        scanf("%d %d %d", &c, &m, &x);

        if(c && m && x){
            int minimum = min_of_them(c, m, x);
            c -= minimum;
            m -= minimum;
            x -= minimum;
            teams += minimum;
        }

        if(c && m){
            x = (c - m);
            if(x < 0){
                x *= -1;
                m -= x;
            }else{
                c -= x;
            }


            int minimum = min_of_them(c, m, x);

            c -= minimum;
            m -= minimum;
            teams += minimum;

            if(c && m)
                teams += (c * 2) / 3;
        }

        printf("%d\n", teams);
    }

    return 0;
}
