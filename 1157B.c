#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	char *a, f[9];
	scanf("%d", &n);
	a = (char *)malloc(sizeof(char) * n);
	for(int i = 0; i < n; i++) scanf("%c", a + i);
	scanf("%c %c %c %c %c %c %c %c %c", &f[0], &f[1], &f[2], &f[3], &f[4], &f[5], &f[6], &f[7], &f[8]);

	for(int i = 0; i < n; i++){
		if(a[i] < f[a[i] - 1]){
			a[i] = f[a[i] - 1];
			for(int j = i + 1; j < n; j++){
				if(a[j] >= f[a[j] - 1]) break;
				a[j] = f[a[j] - 1];
			}
			i = n;
		}
	}
	for(int i = 0; i < n; i++) 
		printf("%c %d\n", a[i], i);
	return 0;

}
