#include<stdio.h>

int main(){
	char c = 0;
	int len = 0, nums[3] = {0, 0, 0}, tail;

	while(c != '\n'){
		scanf("%c", &c);
		len ++;
		nums[c - 49] += (-(c != 43) & 1);
	}
	for(int i = 0; i < nums[0]; i++){
		len -= 2;
		printf("1");
		if(len > 0) printf("+");
	}
	for(int i = 0; i < nums[1]; i++){
		len -= 2;
		printf("2");
		if(len > 0) printf("+");
	}
	for(int i = 0; i < nums[2]; i++){
		len -= 2;
		printf("3");
		if(len > 0) printf("+");
	}
	return 0;

}
