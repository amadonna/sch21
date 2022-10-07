#include<stdio.h>
#include<stdlib.h>
int get_int();
void output(int **arr, int x, int y);
int input(int **arr, int x, int y);
void mult(int**a1, int **a2, int **b, int x2, int c, int y1);

int main() {
    int x1 = get_int();
    int y1 = get_int();
    int x2 = get_int();
    int y2 = get_int();
    int **a1, **a2, **c;
    if(x1 != 0 && x2 != 0 && y1 != 0 && y2 != 0 && x2 == y1) {
        a1 = (int**)malloc(sizeof(int*) * x1);
        for(int i = 0; i < x1; i++)
            a1[i] = (int*)malloc(sizeof(int) * y1);
        a2 = (int**)malloc(sizeof(int*) * x2);
        for(int i = 0; i < x2; i++)
            a2[i] = (int*)malloc(sizeof(int) * y2);
        c = (int**)malloc(sizeof(int*) * x2);
        for(int i = 0; i < x2; i++)
            c[i] = (int*)malloc(sizeof(int) * y1);
        if(a1 != NULL && a2 != NULL && c != NULL) {
            if(input(a1, x1, y1) != 0 && input(a2, x2, y2) != 0) {
                output(a1, x1, y1);
                printf("\n");
                output(a2, x2, y2);
                printf("\n");
                mult(a1, a2, c, x2, x1, y2);
                output(c, x2, y1);
            } else {
                printf("n/a");
            }
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }

    return 0;
}

int get_int() {
    int flag = 0;
    char c;
    int n = 0;
    if(scanf("%d%c",&n, &c) && (c == ' ' || c == '\n'))
        flag = n;
    return flag;
}

int input(int **arr, int x, int y) {
    int flag = 1;
    char c;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if(scanf("%d%c", &arr[i][j], &c) && (c == ' ' || c == '\n'))
                continue;
            else
                flag = 0;
        }
    }
    return flag;
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
void mult(int**a1, int **a2, int **b, int x2, int c, int y1) {
    for(int i = 0; i < x2; i++) {
        for(int j = 0; j < y1; j++) {
            for(int k = 0; k < c; k++) {
                b[i][j] += a1[i][k] * a2[k][j];
            }
        }
    }
}