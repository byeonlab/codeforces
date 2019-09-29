#include<stdio.h>
#include<stdlib.h>

int is_ascending(char *arr, int size){
	for(int i = 0; i < size - 1; i++){
		if(arr[i] > arr[i + 1]) 
			return 0;
	}
	return 1;
}

int main(){

	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		char *d, *output, *concat;
		int found = 0;

		scanf("%d", &n);
		d = malloc(sizeof(char) * (n + 1));
		output = calloc(n, sizeof(char));
		concat = calloc(n, sizeof(char));

		scanf("%s", d);

		for(int border = 48; border < 58; border++){
			int above_border = 0;
			int concat_seq = 0;
			int ones = 0;

			for(int i = 0; i < n; i++){
				if(d[i] < border){
					output[i] = 1;
					ones ++;
				}
				else{
					if(above_border && d[i] == border){
						output[i] = 1;
						ones ++;
					}
					else{
						output[i] = 2;
						if(d[i] > border)
							above_border = 1;
					}
				}
			}

			for(int i = 0; i < n; i++){
				if(output[i] == 1)
					concat[concat_seq++] = d[i];
				else
					concat[ones++] = d[i];
			}

			if(is_ascending(concat, n)){
				for(int i = 0; i < n; i++){
					printf("%d", output[i]);
				}

				printf("\n");
				found = 1;
				break;
			}

		}
		if(found)
			continue;
		
		printf("-\n");

		free(d);
		free(output);
		free(concat);
	}

	return 0;
}
