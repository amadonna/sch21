#include<stdio.h>
#include<stdlib.h>

int input(int **arr, int x, int y);
void output(int **arr, int x, int y);
void sort(int **arr, int *temp, int x, int y);
void spiral(int **arr, int x, int y);

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
            printf("\n");
            spiral(arr, x, y);
            output(arr, x, y);
        }
        else {
            printf("n/a");
        }
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

void sort(int **arr, int *temp, int x, int y) {
    int k = 0;
    for(int i = 0; i < x; i++) {
        for(int j = 0; j < y; j++) {
            temp[k] = arr[i][j];
            k++;
        }
    }
    int t = 0;
    for(int i = 0; i < x * y; i++) {
        for(int j = 0; j < x * y - 1; j++) {
            if(temp[j] > temp[j + 1]) {
                t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;

            }
        }
    }
}
void spiral(int **arr, int x, int y) {
    int max_h = y - 1;
    int max_w = x - 1;
    int min_h = 0;
    int min_w = 0;
    int  *temp = malloc(sizeof(int) * x * y);
    sort(arr, temp, x, y);
    for(int i = 0; i < x * y; i++) {
        printf("%d ", temp[i]);
    }
    printf("\n");
    int k = 0;
    while(k < x * y) {
        for(int j = min_h; j <= max_h; j++) {
            int i = min_w;
            arr[i][j] = temp[k];
            k++;
           
        }
        min_w++;
       for(int i = min_w; i <= max_w; i++) {
           int j = max_h;
           arr[i][j] = temp[k];
           k++;
           
       }
       max_h--;
       for(int j = max_h; j >= min_h; j--) {
           int i = max_w;
           arr[i][j] = temp[k];
           k++;
           
       }
       max_w--;
       for(int i = max_w; i >= min_w; i--) {
           int j = min_h;
           arr[i][j] = temp[k];
           k++;
           
       }
       min_h++;
    }
    free(temp);
}