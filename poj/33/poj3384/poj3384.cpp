#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

#define eps 1e-10
#define MAX_LEN 1005

struct Point{
    double x, y;
    Point() {}
    Point(double _x, double _y):x(_x), y(_y) {}
};

Point points[MAX_LEN], p[MAX_LEN], q[MAX_LEN];
int n;
double r;
int cCnt, curCnt;

double dist(const Point &p1, const Point &p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
void getLine(const Point &x, const Point &y, double &a, double &b, double &c){
    a = y.y - x.y;
    b = x.x - y.x;
    c = y.x * x.y - x.x * y.y;
}
void initial(){
    for (int i = 1; i <= n; i++)
        p[i] = points[i];
    p[n+1] = p[1];
    p[0] = p[n];
    cCnt = n;
}
Point intersection(const Point &x, const Point &y, double a, double b, double c){
    double u = fabs(a * x.x + b * x.y + c);
    double v = fabs(a * y.x + b * y.y + c);
    return Point((x.x * v + y.x * u)/(u + v), (x.y*v + y.y*u)/(u + v));
}
void cut(double a, double b, double c){
    curCnt = 0;
    for (int i = 1; i <= cCnt; ++i){
        if (a * p[i].x + b * p[i].y + c >= 0)
            q[++curCnt] = p[i];
        else {
            if (a * p[i-1].x + b * p[i-1].y + c > 0)
                q[++curCnt] = intersection(p[i], p[i-1], a, b, c);
            if (a * p[i+1].x + b * p[i+1].y + c > 0)
                q[++curCnt] = intersection(p[i], p[i+1], a, b, c);
        }
    }
    for (int i = 1; i <= curCnt; i++)
        p[i] = q[i];
    p[curCnt+1] = q[1];
    p[0] = p[curCnt];
    cCnt = curCnt;
}
void solve(){
    initial();
    for (int i = 1; i <= n; ++i){
        Point ta, tb, tt;
        tt.x = points[i+1].y - points[i].y;
        tt.y = points[i].x - points[i+1].x;
        double k = r / sqrt(tt.x * tt.x + tt.y * tt.y);
        tt.x = tt.x * k;
        tt.y = tt.y * k;
        ta.x = points[i].x + tt.x;
        ta.y = points[i].y + tt.y;
        tb.x = points[i+1].x + tt.x;
        tb.y = points[i+1].y + tt.y;
        double a, b, c;
        getLine(ta, tb, a, b, c);
        cut(a, b, c);
    }

    double tmp = 0;
    double mmax = 0;
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i <= cCnt; i++){
        for (int j = i + 1; j <= cCnt; j++){
            tmp = dist(p[i], p[j]);
            if (tmp > mmax){
                mmax = tmp;
                ans1 = i;
                ans2 = j;
            }
        }
    }
    printf("%.4lf %.4lf %.4lf %.4lf\n", p[ans1].x, p[ans1].y, p[ans2].x, p[ans2].y);
}

int main()
{
    while (scanf("%d %lf", &n, &r) != EOF){
        for (int i = 1; i <= n; i++)
            scanf("%lf %lf", &points[i].x, &points[i].y);
        points[n+1] = points[1];
        solve();
    }
    return 0;
}
