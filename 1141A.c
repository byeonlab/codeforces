#include<stdio.h>

int main(){
	long n, m, div;
	scanf("%ld %ld", &n, &m);
	long mod = m - (n * (m / n));
	if(mod) printf("-1");
	else{
		int cnt = 0;
	    div = m / n;
		if((div % 2) == 0 || (div % 3) == 0 || div == 1){
			while((div % 3) == 0){
				div /= 3;
				cnt ++;
			}
			while((div & 1) == 0){
				div >>= 1;
				cnt ++;
			}
			if(div == 1) printf("%d", cnt);
			else printf("-1");
		} 
		else printf("-1");
	} 
	return 0;
}
