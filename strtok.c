#include<stdio.h>
#include<stdlib.h>
void output(char *str, int n);
void input(char *str);
int find_last(char *str, char *str2, int s1, int s2);
void out_res(char *arr, int s1, int s2, int find);
int str_len(char *str);

int main() {
    char *str = NULL;
    char *str2 = NULL;
    str2 = realloc(str2, sizeof(char));
    str = realloc(str, sizeof(char));
    input(str);
    printf("\n");
    input(str2);
    int s1 = str_len(str);
    int s2 = str_len(str2);
    if(s1 > 0 ) {
        out_res(str, s1, s2, find_last(str, str2, s1 , s2));
    }
    else
        printf("n/a");
    
    return 0;
}
void input(char *str) {
    char c;
    int i = 0;
    while(c != '\n') {
        scanf("%c", &c);
        if(c == '\n')
            break;
        str[i] = c;
        i++;
    }
}
void output(char *str, int n) {
    int i = 0;
    while(i < n) {
        printf("%c", str[i]);
        i++;
    }
}

int find_last(char *str, char *str2, int s1, int s2) {
    int flag = 0;
    int i = s1 - s2;
    while(i >= 0) {
        if(str[i] == str2[0]) {
            int check = 0;
            int l = i;
            for(int k = 0; k < s2; k++) {
                if(str2[k] == str[l]) {
                    l++;
                    check++;
                }
            }
            if(check == s2) {
                    flag = i;
                    break;
                }
        }
        i--;
    }
    return flag;
}
void out_res(char *arr, int s1, int s2, int find) {
    int i = 0;
    while(i < s1) {
        if(i < find || i >= find + s2)
            printf("%c",arr[i]);
        i++;
    }
}
int str_len(char *str) {
    int i = 0;
    while(str[i] != '\0')
        i++;
    return i;
}