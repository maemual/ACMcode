#include<cstdio>
#include<limits.h>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX_LEN 1000
int arr[MAX_LEN];
char sss[MAX_LEN];
char str[2*MAX_LEN], s[MAX_LEN];
int p[2 * MAX_LEN];
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
    memset(p, 0, sizeof(p));
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
    int m;
    int nn;
    scanf("%d%d", &m, &nn);
    n = nn;
    //strcpy(s, "aaaab");
    //printf("%s\n", s);
    for (int i = 0; i < nn; i++){
        s[i] = 'a';
    }
    int aaa = INT_MAX;
    int mmax = pow(m, nn);
    for (int i = 0; i < mmax; i++){
        int jin = 1;
        for (int j = nn-1; j>= 0; j--){
            s[j] += jin;
            jin = (s[j] - 'a') / m;
            s[j] = (s[j] - 'a') % m + 'a';
        }
        //printf("%s\n", s);
        //break;
        init();
        palindrome();
        int ans = 0;
        for (int x = 0; x < n; x++){
            if (p[x] > ans)
                ans = p[x];
        }
        ans--;
        //printf("%d\n", ans);
        n = nn;
        if (ans < aaa){
            aaa = ans;
            strcpy(sss, s);
        }
    }
    printf("%d\n", aaa);
    printf("%s\n", sss);
    return 0;
}
