#include<stdio.h>
#include<stdlib.h>

int main(){
	int n;
	int rooms[10] = {0};
	char *memory;

	scanf("%d", &n);

	memory = (char*)malloc(sizeof(char) * (n + 1));
	scanf("%s", memory);

	for(int i = 0; i < n; i++){
		if(memory[i] == 'L'){
			for(int j = 0; j < 10; j++){
				if(rooms[j] == 0){
					rooms[j] = 1;
					break;
				}
			}
		}
		else if(memory[i] == 'R'){
			for(int j = 9; j >= 0; j--){
				if(rooms[j] == 0){
					rooms[j] = 1;
					break;
				}
			}
		}
		else{
			rooms[memory[i] - 48] = 0;
		}
	}

	free(memory);

	for(int i = 0; i < 10; i++)
		printf("%d", rooms[i]);

	return 0;
}
