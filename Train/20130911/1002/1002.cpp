#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

#define eps 1e-8
#define MAX_LEN 305

struct point{
    double x, y;
    double vx, vy;
}p[MAX_LEN];
int n;
double calc(double t){
    double ret = 0;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            double x1 = p[i].x + p[i].vx * t;
            double y1 = p[i].y + p[i].vy * t;
            double x2 = p[j].x + p[j].vx * t;
            double y2 = p[j].y + p[j].vy * t;
            ret = max(ret, sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
        }
    }
    return ret;
}
double solve(){
    double left = 0, right = 1e20;
    while (right - left >= eps){
        double mid = (left + right) / 2;
        double midmid = (mid + right) / 2;
        double tmp1 = calc(mid);
        double tmp2 = calc(midmid);
        if (tmp2 > tmp1)
            right = midmid;
        else
            left = mid;
    }
    return left;
}
int main()
{
    int T;
    scanf("%d", &T);
    for (int k = 1; k <= T; k++){
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%lf%lf%lf%lf", &p[i].x, &p[i].y, &p[i].vx, &p[i].vy);
        double t = solve();
        printf("Case #%d: %.2lf %.2lf\n", k, t, calc(t));
    }
    return 0;
}
