#include<stdio.h>

int is_dangerous(char players[101], int idx, int prev, int cnt){
	if(cnt == 7) return 1;
	if(players[idx] == '\0') return 0;
	return is_dangerous(players, idx + 1, players[idx], cnt * (players[idx] == prev) + 1);
}
int main(){
	char players[101];
	int danger;
	scanf("%s", players);
	danger = is_dangerous(players, 1, players[0], 1);
	if(danger) printf("YES");
	else printf("NO");
	return 0;
}
