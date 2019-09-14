#include<stdio.h>
#include<stdlib.h>

int before(int a, int b){return a - b;}
int after(int a, int b){return a + b;}
int forecast(int _d, int d, int * summer, int (*f)(int, int)){
	int rain_d = summer[d];
	int res = 0;
    while(_d){
		res += (summer[f(d, _d)] < rain_d);
		_d--;
	}
	return res == _d;
}
int main(){
	int n, x, y;
	int *summer;

	scanf("%d %d %d", &n, &x, &y);

	summer = malloc(sizeof(int) * n);

	for(int i = 0; i < n; i++) 
		scanf("%d", summer + i);

	for(int i = 0; i < n; i++){
		if(forecast(x + (-(i - x < 0) & (i - x)), i, summer, before) && 
		  (forecast(y - (-(i + y > n - 1) & (i + y - n + 1)), i, summer, after))){
			printf("%d", i + 1);
			break;
		}
	}

	free(summer);

	return 0;
}    
