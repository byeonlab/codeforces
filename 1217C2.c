#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char *int_to_binstr(long long num);

long long find(char *s, int l, int r, long long  good_substrings);

int main(){
	int t;
	scanf("%d", &t);

	while(t--){
		char s[200001];
		long long good_substrings;

		scanf("%s", s);

		good_substrings = find(s, 0, 0, 0);

		printf("%I64d\n", good_substrings);
	}

	return 0;
}

char *int_to_binstr(long long num){
	char *binstr = calloc(num, sizeof(char));
/*
	for(long long i = 0; i <= num; i++){
		binstr[i] = ((num & (1 << (num - i - 1))) != 0) + 48;
	}
	**/
	long long i;
	for(i = num - 1; num; i--){
		binstr[i] = (num & 1) + 48;
		num >>= 1;
	}
	for(i; i >= 0; i--){
		binstr[i] = 48;
	}
	return binstr;
}

long long find(char *s, int l, int r, long long good_substrings){
	if(s[l] == '\0') return good_substrings;
	if(s[r] == '\0') return find(s, l + 1, l + 1, good_substrings);

	char *binstr = int_to_binstr(r - l + 1);
	good_substrings += !strncmp(s + l, binstr, r - l + 1);
	free(binstr);

	return find(s, l, r + 1, good_substrings);
}
