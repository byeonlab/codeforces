#include<stdio.h>

int main() {
	int n, x, y;
	int cnt = 0;
	char num;
	scanf("%d %d %d\n", &n, &x, &y);
	int no_meaning = n - x;
	while (no_meaning--) {
		scanf("%c", &num);
	}

	int meaning_left = x - y - 1;
	while (meaning_left--) {
		scanf("%c", &num);
		if (num == 49) cnt++;
	}
	scanf("%c", &num);
	if (num == 48) cnt++;

	int meaning_right = y;
	while (meaning_right--) {
		scanf("%c", &num);
		if (num == 49) cnt++;
	}

	printf("%d", cnt);
	return 0;
}

