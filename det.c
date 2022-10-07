#include<stdio.h>
#include<stdlib.h>
int input(int **arr, int x, int y);
void output(int **arr, int x, int y);

int main() {
    char c, d;
    int x = 0;
    int y = 0;
    int **a;
    if (scanf("%d%c%d%c", &x, &c, &y, &d) && c == ' ' && d == '\n' && x != 0 && y != 0) {
        a = (int**)malloc(x * sizeof(int*));
        for (int i = 0; i < x; i++)
            a[i] = (int*)malloc(y * sizeof(int));
        if (a != NULL && input(a, x, y) != 0) {
            output(a, x, y);
        }
    }
}

int input(int **arr, int x, int y) {
    int ret = 1;
    char e;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (!(scanf("%d", &arr[i][j]))) {
                ret = 0;
                break;
            }
            if (i == x - 1 && j == y - 1) {
                scanf("%c", &e);
                if (!(e == '\n')) {
                    ret = 0;
                    break;
                }
            }
        }
    }
    return ret;
}

void output(int **arr, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d", arr[i][j]);
            if (j < y - 1)
                printf(" ");
        }
        if (i < x - 1)
            printf("\n");
    }
}