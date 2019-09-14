#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		char *s = malloc(sizeof(char) * 200001);
		int str_len;
		int good_substrings = 0;
		int zeros = 0;

		scanf("%s", s);
		str_len = strlen(s);
		
		for(int i = 0; i < str_len; i++){
			if(s[i] == '0'){
				zeros ++;
			}
			else{
				long long val = 0;
				int substr_len = zeros;
				for(int j = i; j < str_len && val <= substr_len; j++){
					substr_len ++;
					val <<= 1;
					val += s[j] - 48;
					if(val <= substr_len)
						good_substrings ++;

				}
				zeros = 0;
			}
		}

		free(s);
		printf("%d\n", good_substrings);
	}


	return 0;
}
