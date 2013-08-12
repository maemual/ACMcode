/*
ID: maemual
PROB: ariprog
LANG: C++
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX_LEN 125000

bool ari[MAX_LEN+5];
int arr[MAX_LEN+5];
int n, m;
int k = 0;
struct node{
    int a, b;
    node() {}
    node(int _a, int _b):a(_a), b(_b){}
};
bool check(int a, int b){
    int cnt = 1;
    for (int i = a + b; i <= arr[k-1]; i += b){
        if (ari[i]) cnt++;
        if (cnt >= n) return true;
        if (!ari[i]) return false;
    }
    return false;
}
bool cmp(const node &n1, const node &n2){
    if (n1.b < n2.b)
        return true;
    else if (n1.b == n2.b){
        if (n1.a < n2.a)
            return true;
    }
    return false;
}
int main()
{
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    memset(ari, false, sizeof(ari));
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= m; j++)
            ari[i * i + j * j] = true;
    for (int i = 0; i <= m*m + m*m; i++){
        if (ari[i])
            arr[k++] = i;
    }
    bool flag = true;
    vector<node> vec;
    for (int i = 0; i < k; i++){
        for (int j = i + 1; j < k; j++){
            if (arr[i] + (arr[j] - arr[i]) * (n - 1) > arr[k-1]) break;
            if (check(arr[i], arr[j] - arr[i])){
                flag = false;
                node tmp(arr[i], arr[j] - arr[i]);
                vec.push_back(tmp);
            }
        }
    }
    if (flag){
        printf("NONE\n");
        return 0;
    }
    sort(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < vec.size(); i++){
        printf("%d %d\n", vec[i].a, vec[i].b);
    }
    return 0;
}
