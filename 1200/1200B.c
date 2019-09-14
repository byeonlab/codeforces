#include<stdio.h>

int impossible(int height, int bag, int k){

	if(diff > k) return 1;

	return 0;
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		int *row;
		int n, m, k;

		scanf("%d %d %d", &n, &m, &k);
		row = malloc(n * sizeof(int));

		for(int i = 0; i < n; i++)
			scanf("%d", row + i);
		
		for(int i = 0; i < n; i++){

			int diff = 0;
			if(row[i] > row[i + 1]) diff = row[i] - row[i + 1];
			if(row[i] < row[i + 1]) diff = row[i + 1] - row[i];

			if(impossible(row[i], m, k)) {
				printf("NO\n");
				break;
			}


		}
	}

}
