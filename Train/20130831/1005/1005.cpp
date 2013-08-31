#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_LEN 100005
double arr[MAX_LEN];
int main()
{
    //ios::sync_with_stdio(false);
    int n, m;
    int u, v;
    double w;
    while (scanf("%d %d", &n, &m) != EOF){
        double sum = 0;
        for (int i = 1; i <= n; i++){
            scanf("%lf", &arr[i]);
            sum += arr[i];
        }
        arr[0] = 0;
        for (int i = 0; i < m; i++){
            scanf("%d%d%lf", &u, &v, &w);
            arr[u] += w * 0.5;
            arr[v] += w * 0.5;
        }
        sort(arr + 1, arr + 1 + n);
        double ans = 0;
        for (int i = n; i > 0; i -= 2){
           ans += arr[i] - arr[i-1];
        }
        printf("%.lf\n", ans);
    }
    return 0;
}
