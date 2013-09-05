#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

#define eps 1e-8
const int maxn = 200001;
const double INF = 1e100;

struct point{
    double x, y;
    point() {}
    point(double _x, double _y):x(_x), y(_y){}
}p[maxn];
int n;
int cmp(double x, double y){
    if (x == y) return 0;
    if (x > y) return 1;
    return -1;
}
bool cmp1(const point& a, const point& b){
    if (a.x != b.x)
        return a.x < b.x;
    else
        return a.y < b.y;
}
bool cmp2(int i, int j){
    return cmp(p[i].y, p[j].y) < 0;
}
double dist2(const point& a, const point& b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}
int y[maxn], len;
double cp(point p[], int left, int right){
    int i, j;
    int mid = (left + right) >> 1;
    double ret = INF;
    if (left >= right) return ret;
    for (i = mid; i >= left && !cmp(p[i].x, p[mid].x); i--) ;
    double t1 = cp(p, left, i);
    for (i = mid; i <= right && !cmp(p[i].x, p[mid].x); i++) ;
    double t2 = cp(p, i, right);
    if (t1 < t2)
        ret = t1;
    else
        ret = t2;

    len = 0;
    for (i = left; i <= right; i++){
        if (fabs(p[i].x-p[mid].x)<ret)
            y[++len] = i;
    }
    sort(y+1, y+len+1, cmp2);
    for (i = 1; i <= len; i++){
        int cnt = 1;
        for (j = i + 1; j <=len && cnt <= 7; j++){
            ret = min(ret, dist2(p[y[i]], p[y[j]]));
            cnt++;
        }
    }
    return ret;
}

bool check(int n){
    for (int i = 2; i <= n; i++){
        if (p[i].x == p[i-1].x && p[i].y == p[i-1].y)
            return true;
    }
    return false;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF){
        if (n == 0) break;
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        sort(p+1, p+n+1, cmp1);
        if (check(n)){
            printf("0.00\n");
            continue;
        }
        double ans = sqrt(cp(p, 1, n));
        printf("%.2lf\n", ans);
    }
    return 0;
}
