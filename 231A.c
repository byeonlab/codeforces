#include<stdio.h>

int main(){
	int n, cnt = 0;
	scanf("%d", &n);
	while(n--){
		int p, v, t;
		scanf("%d %d %d", &p, &v, &t);
		if(p + v + t > 1) cnt++;
	}
	printf("%d", cnt);
	return 0;
}
