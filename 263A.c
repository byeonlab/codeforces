#include<stdio.h>

int diff(int x, int y){
	int _diff = x - y;
	return (-(_diff > 0) & _diff) + (-(_diff < 0) & -_diff);
}
int main(){
	int matrix[25], e;
	for(int i = 0; i < 25; i++){
		scanf("%d", &e);
		if(e){
			int r = i / 5;
			int r_diff = 2 - r;
			int c = i - (r * 5);
			int c_diff = 2 - c;
			printf("%d", diff(2, r) + diff(2, c));
		}
	}
	return 0;
}
