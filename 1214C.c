#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	char *s = NULL;
	int open = 0, close = 0;
	int fail = 0; 

	scanf("%d", &n);
	
	s = malloc(sizeof(int) * n + 1);
	scanf("%s", s);

	for(int i = 0; i < n; i++){
		open += (s[i] == '(');
		close += (s[i] == ')');
		if(!open & (s[i] == ')')) {
			fail++;
		}
	}

	free(s);

	if(n & 1) printf("No");
	else if(fail <= 1) printf("Yes");
	else printf("No");

	return 0;
}
