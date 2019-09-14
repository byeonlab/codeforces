#include<stdio.h>

int main(){
	char c;
	scanf("%c", &c);
	printf("%c", (-(c > 96) & (c - 32)) + (-(c < 97) & c));
	while(c != '\n'){
		scanf("%c", &c);
		printf("%c", c);
	}
	return 0;

}
