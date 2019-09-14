#include<stdio.h>
#include<stdlib.h>

int main(){
	int n, m;
	int pos[5000];
	int k = 0;
	int *matrix1, *matrix2;
	int not_equal = 0;


	scanf("%d %d", &n, &m);
	matrix1 = malloc(sizeof(int) * n * m);
	matrix2 = calloc(m * n, sizeof(int));

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", matrix1 + (i * m) + j);
		}
	}

	for(int i = 0; i < n - 1; i++){
		for(int j = 0; j < m - 1; j++){
			if(*(matrix1 + (i * m) + j) && 
				*(matrix1 + (i * m) + j + 1) && 
				*(matrix1 + ((i + 1) * m) + j) && 
				*(matrix1 + ((i + 1) * m) + j + 1)){

				*(matrix2 + (i * m) + j) = 1;
				*(matrix2 + (i * m) + j + 1) = 1;
				*(matrix2 + ((i + 1) * m) + j) = 1;
				*(matrix2 + ((i + 1) * m) + j + 1) = 1;

				pos[2 * k] = i + 1;
				pos[2 * k + 1] = j + 1;
				//j += 1;
				k += 1;
			}
		}
	}

	for(int i = 0; i < n; i += 1){
		for(int j = 0; j < m; j++){
			not_equal += (*(matrix1 + (i * m) + j) != *(matrix2 + (i * m) + j));
		}
	}
	
	if(not_equal) printf("-1");
	else{
		printf("%d\n", k);
		for(int i = 0; i < k; i ++){
			printf("%d %d\n", pos[2 * i], pos[2 * i + 1]);
		}
	}

	free(matrix1);
	free(matrix2);

	return EXIT_SUCCESS;
}
