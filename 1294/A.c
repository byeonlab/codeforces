#include<stdio.h>

int main(){
    int t;

    scanf("%d", &t);

    while(t--){
        int a, b, c, n;
        const char res[3][4] = {"NO", "YES"};

        scanf("%d %d %d %d", &a, &b, &c, &n);

        const int s = a + b + c + n;
        const int q = s / 3;
        const int r = s - (3 * q);

        printf("%s\n", res[!r & (a <= q) & (b <= q) & (c <= q)]);
    }

    return 0;
}
