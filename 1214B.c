#include<stdio.h>

int main(){
	int b, g, n;

	scanf("%d", &b);
	scanf("%d", &g);
	scanf("%d", &n);

	if(b >= n && g >= n) printf("%d", n + 1);
	else if(b >= n && g < n) printf("%d", n + 1 - (n - g));
	else if(b < n && g >= n) printf("%d", n + 1 - (n - b));
	else printf("1");

	return 0;
}
