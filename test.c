#include<stdio.h>

int main(){
	int x, y;
	while(1){
		printf("enter: ");
		scanf("%d %d", &x ,&y);
		printf("%d\n", (x | y) & y);
	}
}
