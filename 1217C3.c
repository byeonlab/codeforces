#include<stdio.h>
 
 
unsigned long long binstr_to_int(char *binstr, unsigned long long len);
 
unsigned long long find(char *s, unsigned long long l, unsigned long long r, unsigned long long good_substrings);
 
int main(){
	int t;
	scanf("%d", &t);
 
	while(t--){
		char s[200001];
		unsigned long long good_substrings;
 
		scanf("%s", s);
 
		good_substrings = find(s, 0, 0, 0);
 
		printf("%I64u\n", good_substrings);
	}
 
	return 0;
}
 
unsigned long long binstr_to_int(char *binstr, unsigned long long len){
	unsigned long long decimal = 0;
 
	for(unsigned long long i = 0; i < len; i++){
		decimal <<= 1;
		decimal += (unsigned long long)(*(binstr + i) - 48);
	}
 
	return decimal;
}
 
unsigned long long find(char *s, unsigned long long l, unsigned long long r, unsigned long long good_substrings){
	if(s[l] == '\0') return good_substrings;
	if(s[r] == '\0') return find(s, l + 1, l + 1, good_substrings);
	return find(s, l, r + 1, good_substrings + ((r - l + 1) == binstr_to_int(s + l, r - l + 1)));
}

