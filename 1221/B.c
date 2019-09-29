#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    char *board;

    scanf("%d", &n);
    board = malloc(sizeof(char) * n * n);

    for(int i = 0; i < n; i += 2){
        for(int j = 0; j < n; j += 2){
           *(board + (i * n) + j) = 'W';
        }
        for(int j = 1; j < n; j += 2){
           *(board + (i * n) + j) = 'B';
        }
    }
    for(int i = 1; i < n; i += 2){
        for(int j = 0; j < n; j += 2){
           *(board + (i * n) + j) = 'B';
        }
        for(int j = 1; j < n; j += 2){
           *(board + (i * n) + j) = 'W';
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            printf("%c", *(board + (n * i) + j));
        printf("\n");
    }

    free(board);

    return 0;
}
