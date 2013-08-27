#include<cstdio>
#include<string.h>
#include<iostream>
using namespace std;

int arr[5];
int main()
{
    char str[200];
    scanf("%s", str);
    int len = strlen(str);
    int cnt = 0;
    for (int i = 0; i < len; i++){
        if (str[i] != '+' ){
            arr[str[i] - '0']++;
        }
        else
            cnt++;
    }
    for (int i = 1; i <= 3; i++){
        while (arr[i]){
            printf("%d", i);
            if (cnt) {
                printf("+");
                cnt--;
            }
            arr[i]--;
        }
    }
    printf("\n");
    return 0;
}
