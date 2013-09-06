#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;
#define eps 1e-10
const int MAXN = 105;
struct Point{
    double x,y;
    Point(){}
    Point(double _x,double _y):x(_x),y(_y){}
};
/*半平面相交（直线切割多边形）（点标号从1开始）*/
Point points[MAXN],p[MAXN],q[MAXN];
int n;
double r;
int cCnt,curCnt;

inline void getline(Point x,Point y,double &a,double &b,double &c){
    a = y.y - x.y;
    b = x.x - y.x;
    c = y.x * x.y - x.x * y.y;
}
inline void initial(){
    for(int i = 1; i <= n; ++i)
        p[i] = points[i];
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
        if(a*p[i].x + b*p[i].y + c >= 0)
            q[++curCnt] = p[i];
        else {
            if(a*p[i-1].x + b*p[i-1].y + c > 0){
                q[++curCnt] = intersect(p[i],p[i-1],a,b,c);
            }
            if(a*p[i+1].x + b*p[i+1].y + c > 0){
                q[++curCnt] = intersect(p[i],p[i+1],a,b,c);
            }
        }
    }
    for(int i = 1; i <= curCnt; ++i)
        p[i] = q[i];
    p[curCnt+1] = q[1];
    p[0] = p[curCnt];
    cCnt = curCnt;
}
bool solve(){
    //注意：默认点是顺时针，如果题目不是顺时针，规整化方向
    initial();
    for(int i = 1; i <= n; ++i){
        double a,b,c;
        getline(points[i],points[i+1],a,b,c);
        cut(a,b,c);
    }
    //此时cCnt为最终切割得到的多边形的顶点数，p为存放顶点的数组
    if (cCnt == 0)
        return false;
    else
        return true;
}
inline void GuiZhengHua(){
     //规整化方向，逆时针变顺时针，顺时针变逆时针
    for(int i = 1; i < (n+1)/2; i ++)
      swap(points[i], points[n-i]);//头文件加iostream
}

int main()
{
    int T = 0;
    scanf("%d", &T);
    while (T--){
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
            scanf("%lf%lf", &points[i].x, &points[i].y);
        points[n+1] = points[1];
        if (solve())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
