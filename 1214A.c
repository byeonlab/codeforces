#include<stdio.h>
#include<stdlib.h>

int compare(const void *num1, const void *num2){
	int n1 = *(int *)num1;
	int n2 = *(int *)num2;

	return (n1 < n2) - (n1 > n2);
}

int main(){
	int n;
	int d, e;
	int exchange[13];

	scanf("%d", &n);
	scanf("%d", &d);
	scanf("%d", &e);

	exchange[0] = 1 * d; 
	exchange[1] = 2 * d;
    exchange[2] = 5 * d;
    exchange[3]	= 10 * d;
    exchange[4]	= 20 * d; 
	exchange[5] = 50 * d;
    exchange[6]	= 100 * d;
	exchange[7] = 5 * e;
    exchange[8]	= 10 * e;
    exchange[9]	= 20 * e; 
	exchange[10] = 50 * e;
	exchange[11] = 100 * e; 
	exchange[12] = 200 * e;

	qsort(exchange, 13, sizeof(int), compare);

	for(int j = 0; j < 13; j++){
		int optimal = 0;

		for(int i = 0; i < 13; i++){
			int val = (n / exchange[i] * exchange[i]);
			if(val > optimal) optimal = val;
		}
		n -= optimal;
	}

	printf("%d", n);

	return EXIT_SUCCESS;

}
