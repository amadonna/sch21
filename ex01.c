#include<stdio.h>
#include<stdlib.h>

int input(int *arr);
void output(int *arr, int n);
void unic(int *arr, int *buf, int n);
int intlen(int *arr);

int main() {
    int *arr = NULL;
    int *buf = NULL;
    buf = realloc(buf, sizeof(int));
    arr = realloc(arr, sizeof(int));
    int n = input(arr);
    if (n > 0) {
        unic(arr, buf, n);
        printf("\n");
        int n_2 = intlen(arr);
        output(buf, n_2);
    } else {
        printf("n/a");
    }
    free(arr);
    free(buf);
    return 0;
}
int input(int *arr) {
    int flag = 1;
    int check = 0;
    int i = 0;
    while (check != -1) {
        if (scanf("%d", &check)) {
            if (check == -1) {
                break;
            } else {
                arr[i] = check;
                i++;
                flag = i;
            }
        } else {
            flag = 0;
            break;
        }
    }
    return flag;
}
void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1)
            printf(" ");
    }
}
void unic(int *arr, int *buf, int n) {
    for (int i = 0; i < n; i++) {;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n; k++)
                    arr[k] = arr[k + 1];
                j--;
                n--;
            }
        }
        buf[i] = arr[i];
    }
}
int intlen(int *arr) {
    int i = 0;
    while (arr[i] != '\0')
        i++;
    return i;
}
