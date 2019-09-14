#include<stdio.h>
#include<stdlib.h>

int pairwise_distinct(int *arr, int l, int r){

}
int main(){
	int n;
	int *array;
	int maximum = 0;

	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", array + i);

	for(int i = 1; i < n; i++){
		int len = 0;

		for(int j = 1 ; j < i; j++){
			if(array[i] == array[j])
				break;
			len ++;
		}

		for(int j = n - 1 ; j >= i; j--){
			if(array[i] == array[j])
				break;
			len++;
		}

		maximum = (maximum & -(maximum > len)) + (len & -(len >= maximum));
	}

	printf("%d", n - maximum);

	return 0;
}
