#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    int modify_count = 0;
    char *s;
    
    scanf("%d", &n);

    s = malloc(sizeof(int) * (n + 1));
    scanf("%s", s);

    for(int i = 1; i <= n; i += 2){
        int dup = (s[i] == s[i - 1]);
        int is_a = (s[i] == 'a');

        s[i] = (s[i] & -(!dup)) + ((('b' & -is_a) + ('a' & -(!is_a))) & -dup);
        modify_count += dup;
    }

    printf("%d\n", modify_count);
    printf("%s", s);

    free(s); 

    return 0;
}
