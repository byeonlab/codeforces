#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	int frequency = 0;
	int maximum = 0;
	int *a, *b;
	char *s;

	scanf("%d", &n);
	s = (char *)malloc(sizeof(char) * (n + 1));
	a = malloc(sizeof(int) * n);
	b = malloc(sizeof(int) * n);

	scanf("%s", s);

	for(int i = 0; i < n; i++)
		scanf("%d %d", a + i, b + i);

	for(int i = 0; i < 10000; i++){
		int on = 0;
		for(int j = 0; j < n; j++){
			if(i < b[j]) 
				on += (s[j] - 48);
			else if(((i - b[j]) / a[j]) & 1)
				on += (s[j] - 48);
			else
				on += ((s[j] - 48) ^ 1);
		}

		if(on > maximum)
			maximum = on;

	}

	free(s);
	free(a);
	free(b);

	printf("%d", maximum);

	return 0;
}
