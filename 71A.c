#include<stdio.h>

int main(){
	int n;
	scanf("%d", &n);

	while(n --){
		char str[101];

		int len;
		scanf("%s", str);
		for(int i = 0; ; i++){
			if(str[i] == '\0') {
				len = i;
				break;
			}
		}
		if(len > 10) printf("%c%d%c\n", str[0], len - 2, str[len - 1]);
		else printf("%s\n", str);
	}
	return 0;
}
