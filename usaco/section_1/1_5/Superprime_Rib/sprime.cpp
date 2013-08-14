/*
ID: maemual
PROB: sprime
LANG: C++
*/
#include<cstdio>
#include<cmath>
int n;
int num1[] = {2, 3, 5, 7};
int num2[] = {1, 3, 7, 9};
bool check(int x){
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    if (x == 4 || x == 5 || x == 6 || x == 8 || x == 9) return false;
    if (x == 7) return true;
    int num = x / 2;
    for (int i = 3; i <= num; i += 2){
        if (x % i == 0)
            return false;
    }
    return true;
}
void dfs(int k, int num){
    int tmp;
    if (k >= n) {
        printf("%d\n", num);
        return ;
    }
    if (k == 0){
        for (int i = 0; i < 4; i++){
            tmp = num * 10 + num1[i];
            dfs(k + 1, tmp);
        }
    }else{
        for (int i = 0; i < 4; i++){
            tmp = num * 10 + num2[i];
            if (check(tmp)){
                dfs(k + 1, tmp);
            }
        }
    }
}
int main()
{
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    scanf("%d", &n);
    dfs(0, 0);
    return 0;
}
