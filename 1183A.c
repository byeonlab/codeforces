#include<stdio.h>

int main(){
	int a;
	scanf("%d", &a);
	while(1){
		int w, x, y, z;
		w = a / 1000;
		x = a / 100 - (10 * w);
		y = a / 10 - ((100 * w) + (10 * x));
		z = a - ((1000 * w) + (100 * x) + (10 * y));

		if(!((w + x + y + z) & 3)) break;
		a++;
	}
	printf("%d", a);
	return 0;
}
