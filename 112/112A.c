#include<stdio.h>
#include<string.h>

int main(){
 	char s1[101], s2[101];
	scanf("%s\n%s", s1, s2);
	
	int comp = 0;
	for(int i = 0; i < strlen(s1); i++){
		if(comp != 0) break;
		(s1[i] < 91) && (s1[i] += 32);
		(s2[i] < 91) && (s2[i] += 32);
		(s1[i] > s2[i]) && (comp =  1);
		(s2[i] > s1[i]) && (comp = -1);
	}
	printf("%d", comp);
	return 0;
}
