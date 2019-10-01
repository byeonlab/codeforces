#include<stdio.h>
#include<string.h>

int main(){
    char s[101];
    int ones = 0;
    scanf("%s", s);

    for(int i = 0; i < strlen(s); i++)
        ones += (s[i] == 49);

    printf("%I64d", strlen(s) / 2 + ((ones > 1) & (strlen(s) & 1)));

    return 0;
}
