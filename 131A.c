#include<stdio.h>
 
int main(){
    char str[100];
    int idx = 1, len = 1, uppers = 0;
 
    scanf("%s", str);
    while(str[idx] != '\0'){
        len += 1;
        uppers += (str[idx] < 91);
        idx++;
    }
 
    if(uppers == len - 1){
		if(str[0] > 96) str[0] -= 32;
		else			str[0] += 32;
        for(int i = 1; i < len; i++) str[i] += 32;
    }
    printf("%s", str);
    return 0;
}
