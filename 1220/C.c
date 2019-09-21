#include<stdio.h>
#include<string.h>

int main(){
    char s[500000];
    int alphabets[26] = {0};

    scanf("%s", s);

    for(int i = 0; i < strlen(s); i++){
       int lowers = 0;
       for(int j = 0; j < alphabets[s[i] - 'a']; j++)
           lowers += alphabets[j];

       printf("i, lowers = %d, %d\n", i, lowers);
       
       if(lowers & 1)
           printf("Ann\n");
       else
           printf("Mike\n");

       alphabets[s[i] - 'a'] ++;
    }

    return 0;
}
