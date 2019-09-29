#include<stdio.h>

int main(){
    int bags[4];
    int possible = 0;

    for(int i = 0; i < 4; i++)
        scanf("%d", &bags[i]);

    possible = (bags[0] == bags[1] + bags[2] + bags[3]);
    possible = possible | (bags[1] == bags[0] + bags[2] + bags[3]);
    possible = possible | (bags[2] == bags[0] + bags[1] + bags[3]);
    possible = possible | (bags[3] == bags[0] + bags[1] + bags[2]);
    possible = possible | (bags[0] + bags[1] == bags[2] + bags[3]);
    possible = possible | (bags[0] + bags[2] == bags[1] + bags[3]);
    possible = possible | (bags[0] + bags[3] == bags[1] + bags[2]);
    possible = possible | (bags[1] + bags[2] == bags[0] + bags[3]);
    possible = possible | (bags[1] + bags[3] == bags[0] + bags[2]);
    possible = possible | (bags[2] + bags[3] == bags[0] + bags[1]);

    if(possible) 
        printf("YES");
    else
        printf("NO");

    return 0;
}
