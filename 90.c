#include<stdio.h>
#include<stdlib.h>

int input(int **arr, int x, int y);
void output(int **arr, int x, int y);
void sort(int **arr, int *temp, int x, int y);
void spiral(int **arr, int x, int y);
void turn(int **arr, int x, int y);

int main() {
   char c, d;
    int x = 0;
    int y = 0;
    int **arr;
    if (scanf("%d%c%d%c", &x, &c, &y, &d) && c == ' ' && d == '\n' && x != 0 && y != 0) {
        arr = (int**)malloc(x * sizeof(int*));
        for (int i = 0; i < x; i++)
            arr[i] = (int*)malloc(y * sizeof(int));
        if(input(arr, x, y) != 0) {
            output(arr, x, y);
            printf("\n======================\n");
            turn(arr,x, y);
        }
        else
            printf("n/a");
    }
    else
        printf("n/a");
    for(int i =0; i < x; i++)
        free(arr[i]);
    free(arr);
    return 0;
}
int input(int **arr, int x, int y) {
    int flag = 1;
    char c;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            if(scanf("%d%c", &arr[i][j], &c) && (c == ' ' || c == '\n'))
                continue;
            else
                flag = 0;
        }
    }
    return flag;
}
void output(int **arr, int x, int y) {
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            printf("%d", arr[i][j]);
            if(j < y - 1)
                printf(" ");
        }
        if(i < x - 1)
            printf("\n");
    }
}
void turn(int **arr, int x, int y) {
    for(int j = 0; j < y; j++) {
        for(int i = x - 1; i >= 0; i--) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}