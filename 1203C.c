#include<stdio.h>
#include<stdlib.h>
#include<math.h>

long long gcd(long long x, long long y){
	while(y){
		long long tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}

long long count(long long  x){
	if(x == 1) return 1;
	long long cnt = 0;
	for(long long i = 1; i <= (long long)sqrt((double)x); i++){
		if(x % i == 0){
			if(x / i == i) cnt += 1;
			else cnt += 2;
		}
	}
	return cnt;
}
int main(){
	int n;
	long long x, d;
	scanf("%d", &n);
	scanf("%I64d", &x);
	d = x;
	for(int i = 1; i < n; i++) {
		scanf("%I64d", &x);
		d = gcd(d, x);
	}
	printf("%I64d", count(d));
	return 0;

}
