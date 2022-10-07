#include<stdio.h>
#include<stdlib.h>

int input(int **arr, int n, int m);
void output(int **arr, int n, int m);
void sort(int **ar, int *test, int n, int m);
void snake_vert(int **a, int **b, int x, int y);
void snake_hor(int **a, int **b, int x, int y);

int main() {
    char c, d;
    int x = 0;
    int y = 0;
    int **a, **b;
    if (scanf("%d%c%d%c", &x, &c, &y, &d) && c == ' ' && d == '\n' && x != 0 && y != 0) {
        a = (int**)malloc(x * sizeof(int*));
        for (int i = 0; i < x; i++)
            a[i] = (int*)malloc(y * sizeof(int));
        b = (int**)malloc(x * sizeof(int*));
        for (int i = 0; i < x; i++)
            b[i] = (int*)malloc(y * sizeof(int));
        if (a != NULL && b != NULL && input(a, x, y) != 0) {
            snake_vert(a, b, x, y);
            output(b, x, y);
            printf("\n");
            snake_hor(a, b, x, y);
            output(b, x, y);
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    for (int v = 0; v < x; v++) {
        free(a[v]);
        free(b[v]);
    }
    free(a);
    free(b);
    return 0;
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

void sort(int **ar, int *test, int n, int m) {
    int z;
    int temp = 0;
    for (int l = 0; l < n; l++) {
        for (int k = 0; k < m; k++) {
            test[z] = ar[l][k];
            z++;
        }
    }
    for (int i = 0; i < n * m; i++) {
        for (int j = 0; j < n * m - 1; j++) {
            if (test[j] > test[j + 1]) {
                temp = test[j];
                test[j] = test[j + 1];
                test[j + 1] = temp;
            }
        }
    }
}
void snake_vert(int **a, int **b, int x, int y) {
    int *test = malloc(sizeof(int) * x * y);
    sort(a, test, x, y);
    int q = 0;
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            a[j][i] = test[q];
            q++;
        }
    }
    for (int d = 0; d < y; d++) {
        if (d % 2 != 0) {
            int t = x - 1;
            for (int l = 0; l < x; l++) {
                b[l][d] = a[t][d];
                t--;
            }
        } else {
                for (int p = 0; p < x; p++)
                    b[p][d] = a[p][d];
        }
    }
    free(test);
}
void snake_hor(int **a, int **b, int x, int y) {
    int *test = malloc(sizeof(int) * x * y);
    sort(a, test, x, y);
    int h = 0;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            a[i][j] = test[h];
            h++;
        }
    }
    for (int i = 0; i < x; i++) {
        if (i % 2 != 0) {
            int c = y - 1;
            for (int j = 0; j < y; j++) {
                b[i][j] = a[i][c];
                c--;
            }
        } else {
            for (int g = 0; g < y; g++)
                b[i][g] = a[i][g];
        }
    }
    free(test);
}
