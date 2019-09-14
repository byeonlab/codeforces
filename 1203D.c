#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int between(char *s, char *t, int len_s, int len_t){
	int from, to;
	for(int i = 0; i < len_s; i++) {
		if(s[i] == t[0]) {
			from = i; 
			break;
		}
	}
	for(int i = len_s - 1; i >= 0; i--) {
		if(s[i] == t[len_t - 1]) {
			to = i;
			break;
		}
	}

	return to - from - 1;
}
char *subsequence(char *s, char *t, int len_s, int len_t){
	char *tmp;
	int i = 0;
	while(j <= len_s - 1){
		if(i == len_t){
			tmp = s + (j - 1);
			break;
		}
		i += (s[j] == t[i]);

		j++;
	}

	return tmp;
}

void reverse(char * str, int len){
	for(int i = 0; i < len / 2; i++){
		*(str + i) ^= *(str + len - (i + 1));
		*(str + len - (i + 1)) ^= *(str + i);
		*(str + i) ^= *(str + len - (i + 1));
	}
}

int main(){
	char *s, *t, *end_s, *end_t;
	s = malloc(200000 * sizeof(char));
	t = malloc(200000 * sizeof(char));

	scanf("%s", s);
	scanf("%s", t)

	end_s = strchr(s, '\0');
	end_t = strchr(t, '\0');

	int len_s = end_s - s;
	int len_t = end_t - t;
	int left, right;

	int max_between = -(len_s != len_t) & between(s, t, len_s, len_t);
	//char *ptr = strstr(s, t);
	char *ptr = subsequence(s, t, len_s, len_t);
	int idx = ptr - s;
	//printf("idx: %d\n", idx);
	right = s + len_s - ptr;

	reverse(s, len_s);
	reverse(t, len_t);
	
	//char *ptr_rev = strstr(s, t);
	char *ptr_rev = subsequence(s, t, len_s, len_t);
	int idx_rev = ptr_rev - s;
	//printf("idx_rev: %d\n", idx_rev);
	left = s + len_s - ptr_rev;

	//printf("left: %d, right:%d\n", left, right);
	int max_side = (-(idx > idx_rev) & (len_s - idx_rev - 1)) + (-(idx_rev >= idx) & (len_s - idx - 1));

	int max_len = (-(max_side > max_between) & max_side) + (-(max_between >= max_side) & max_between);


	printf("%d", max_len);
	return 0;




}
