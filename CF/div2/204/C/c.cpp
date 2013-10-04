#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

#define MAX_LEN 2005
double arr[MAX_LEN];

int main()
{
    int n;
    cin >> n;
    double x;
    double sum = 0;
    int cnt = 0;
    for (int i = 0; i < 2 * n; i++){
        cin >> x;
        if (x - floor(x) != 0)
            cnt++;
        sum += x - floor(x);
    }
    int mmax = min(cnt, n);
    int mmin = max(0, cnt - n);
    double ans = 1e100;
    for (int tmp = mmin; tmp <= mmax; tmp++){
        if (fabs(sum - tmp) < ans)
            ans = fabs(sum - tmp);
    }
    printf("%.3lf\n", ans);
    return 0;
}
