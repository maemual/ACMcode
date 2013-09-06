#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define EPS 1e-10
const int MAXN = 200;
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
    void input(){
        scanf("%lf%lf",&x,&y);
    }
};
Point points[MAXN],p[MAXN],q[MAXN];
int n;
int cCnt,curCnt;
inline void getline(Point x,Point y,double &a,double &b,double &c){
     a = y.y - x.y;
    b = x.x - y.x;
    c = y.x * x.y - x.x * y.y;
}
inline void initial(){
    for(int i = 1; i <= n; ++i)p[i] = points[i];
    p[n+1] = p[1];
    p[0] = p[n];
    cCnt = n;
}
inline Point intersect(Point x,Point y,double a,double b,double c){
     double u = fabs(a * x.x + b * x.y + c);
    double v = fabs(a * y.x + b * y.y + c);
    return Point( (x.x * v + y.x * u) / (u + v) , (x.y * v + y.y * u) / (u + v) );
}
inline void cut(double a,double b ,double c){
    curCnt = 0;
    for(int i = 1; i <= cCnt; ++i){
        if(a*p[i].x + b*p[i].y + c >= 0)q[++curCnt] = p[i];
        else {
            if(a*p[i-1].x + b*p[i-1].y + c > 0){
                q[++curCnt] = intersect(p[i],p[i-1],a,b,c);
            }
            if(a*p[i+1].x + b*p[i+1].y + c > 0){
                q[++curCnt] = intersect(p[i],p[i+1],a,b,c);
            }
        }
    }
    for(int i = 1; i <= curCnt; ++i)p[i] = q[i];
    p[curCnt+1] = q[1];p[0] = p[curCnt];
    cCnt = curCnt;
}
inline int solve(double r){
    initial();
    for(int i = 1; i <= n; ++i){
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
        double a,b,c;
        getline(ta,tb,a,b,c);
        cut(a,b,c);
    }
    if(cCnt <= 0)return 0;
    return 1;
}
int main(){
    while(scanf("%d",&n) != EOF){
        if(n == 0)break;
        for(int i = 1; i <= n; ++i)points[i].input();
       for(int i = 1; i < (n+1)/2; i ++)
            swap(points[i], points[n-i]);
        points[n+1] = points[1];
        double high = 10000000;
        double low = 0,mid;
        while(low + EPS <= high){
            mid = (high + low)/2.0;
            if(solve(mid))low = mid;
            else high = mid;
        }
        printf("%lf\n",high);
    }
    return 0;
}

