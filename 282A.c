#include<stdio.h>

int main(){
	int n, x = 0;
	char statement[4];
	scanf("%d", &n);
	while(n--){
		scanf("%s", statement);
		for(int i = 0; i < 4; i++){
			if(statement[i] == '+') {x++; break;}
			if(statement[i] == '-') {x--; break;}
		}
	}
	printf("%d", x);
	return 0;
}
