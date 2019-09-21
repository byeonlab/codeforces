#include<stdio.h>
#include<string.h>

int main(){
	char s[500001];
	char names[2][5] = {"Mike", "Ann"};
	int minimum = 0x4FFFFFFF;
	int len;

	scanf("%s", s);
	len = strlen(s);

	for(int i = 0; i < len; i++){
		int idx = s[i] - 'a';

		s[i] = (idx > minimum);
		minimum = (minimum & -s[i]) + (idx & -!s[i]);
		printf("%s\n", names[s[i]]);
	}

	//for(int i = 0; i < len; i++){
	//}

	return 0;
}
