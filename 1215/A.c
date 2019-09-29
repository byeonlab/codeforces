#include<stdio.h>

int main(){
	int a1, a2;
	int k1, k2;
	int n;
	int card_left;

	int minimum, maximum = 0;

	scanf("%d", &a1);
	scanf("%d", &a2);
	scanf("%d", &k1);
	scanf("%d", &k2);
	scanf("%d", &n);

	card_left = n;

	card_left -= (a1 * (k1 - 1));
	card_left -= (a2 * (k2 - 1));

	if(card_left <= 0)
		minimum = 0;
	else
		minimum = card_left;

	card_left = n;

	
	if(k1 > k2){
		for(int i = 0; i < a2; i++){
			if(card_left < k2) break;
			card_left -= k2;
			maximum += 1;
		}
		for(int i = 0; i < a1; i++){
			if(card_left < k1) break;
			card_left -= k1;
			maximum += 1;
		}
	}else{
		for(int i = 0; i < a1; i++){
			if(card_left < k1) break;
			card_left -= k1;
			maximum += 1;
		}
		for(int i = 0; i < a2; i++){
			if(card_left < k2) break;
			card_left -= k2;
			maximum += 1;
		}
	}

	printf("%d %d", minimum, maximum);

	return 0;
}
