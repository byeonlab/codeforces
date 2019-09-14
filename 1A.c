#include<stdio.h>
typedef long long lld;
int main(){
	lld n, m, a, v, h;
	scanf("%lld %lld %lld", &n, &m, &a);

	lld r = m / a;
	lld mod_v = m - (r * a);
	v = r + (mod_v != 0);

	lld c = n / a;
	lld mod_h = n - (c * a);
	h = c + (mod_h != 0);

	printf("%lld", v * h);
	return 0;
}
