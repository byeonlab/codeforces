#include<stdio.h>

int push_r(char str[201], int idx){
	for(int i = 200; i > idx; i--){
		str[i] = str[i - 1];
	}
	return 0;
}

int push_l(char str[201], int idx){
	for(int i = idx; i < 201; i++){
		str[i] = str[i + 1];
	}
	return 0;
}

int main(){
	char str[201];
	scanf("%s", str);
	for(int i = 0; i < 201; i++){
		if(str[i] == '\0') break;
		if(str[i] == 'A' || str[i] == 'O' || str[i] == 'I' || str[i] == 'E' || str[i] == 'U' || str[i] == 'Y'||
		   str[i] == 'a' || str[i] == 'o' || str[i] == 'i' || str[i] == 'e' || str[i] == 'u' || str[i] == 'y') {
				push_l(str, i);
				i--;
		}
		else{
			if(str[i] < 91) str[i] += 32;
			if(str[i] != '.'){
				push_r(str, i);
				str[i] = '.';
			i ++;
			}
		}
	}
	printf("%s", str);
	return 0;

}
