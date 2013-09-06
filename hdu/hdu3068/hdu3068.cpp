#include<cstdio>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX_LEN 110005
char str[3 * MAX_LEN], s[MAX_LEN];
int p[3 * MAX_LEN];
int n;
void palindrome(){
    for (int i = n; str[i] != 0; i++)
        str[i] = 0;
    int mx = 0;
    int id;
    for (int i = 1; i < n; i++){
        if (mx > i)
            p[i] = min(p[2 * id - i], p[id] + id - i);
        else
            p[i] = 1;
        for (; str[i+p[i]] == str[i-p[i]]; p[i]++) ;
        if (p[i] + i > mx){
            mx = p[i] + i;
            id = i;
        }
    }
}
void init(){
    str[0] = '$';
    str[1] = '#';
    for (int i = 0; i < n; i++){
        str[i * 2 + 2] = s[i];
        str[i * 2 + 3] = '#';
    }
    n = n * 2 + 2;
    s[n] = 0;
}
int main()
{
    while (scanf("%s", s) != EOF){
       n = strlen(s);
       init();
       palindrome();
       int ans = 0;
       for (int i = 0; i < n; i++){
           if (p[i] > ans)
               ans = p[i];
       }
       printf("%d\n", ans - 1);
    }
    return 0;
}
