#include<stdio.h>

long play_and_charge(long k, long n, long a, long b, long played){
	if(k > b * (n - played)) return played;
	return play_and_charge(k + a, n, a, b, played - 1);
}
long just_play(long k, long n, long a, long b, long played){
	if(k <= played * a) return just_play(k, n, a, b, played - 1);
	return play_and_charge(k - (a * played), n, a, b, played);
}
long do_game(long k, long n, long a, long b){
	if(k <= n * b) return -1;
	return just_play(k, n, a, b, n);
}
int main(){
	int q;
	scanf("%d", &q);
	while(q--){
		long k, n, a, b, turns;
		scanf("%ld %ld %ld %ld", &k, &n, &a, &b);
		turns = do_game(k, n, a, b);
		printf("%ld\n", turns);
	}
	return 0;
}
