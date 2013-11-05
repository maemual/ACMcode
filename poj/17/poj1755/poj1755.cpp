#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define eps 1e-8
#define MAX_LEN 1005

struct Point{
    double x, y;
    Point() {}
    Point(double _x, double _y):x(_x), y(_y){}
};

struct Node{
    double x, y, z;
    Node() {}
    Node(double _x, double _y, double _z):x(_x), y(_y), z(_z) {}
};
Point points[MAX_LEN], p[MAX_LEN], q[MAX_LEN];
Node nodes[MAX_LEN];

int n;
double r;
int cCnt, curCnt;
int flag;

inline int sign(double x){
    return (x < -eps) ? -1 : (x > eps);
}

inline void getABC(const Node &x, const Node &y, double &a, double &b, double &c){
    a = (x.x - y.x) / (y.x * x.x);
    b = (x.y - y.y) / (y.y * x.y);
    c = (x.z - y.z) / (y.z * x.z);
}

inline void initial(){
    p[1] = Point(0, 0);
    p[2] = Point(1000000, 0);
    p[3] = Point(1000000, 1000000);
    p[4] = Point(0, 1000000);
    p[5] = p[1];
    p[0] = p[4];
    cCnt = 4;
}

inline Point intersection(const Point &x, const Point &y, double a, double b, double c){
    double u = fabs(a * x.x + b * x.y + c);
    double v = fabs(a * y.x + b * y.y + c);
    return Point( (x.x * v + y.x * u) / (u + v), (x.y * v + y.y * u) / (u + v));
}

void cut(double a, double b, double c){
    curCnt = 0;
    if (a == 0 && b == 0 && c == 0){
        flag = 0;
        return ;
    }
    for (int i = 1; i <= cCnt; i++){
        if (sign(a * p[i].x + b * p[i].y + c) >= 0)
            q[++curCnt] = p[i];
        else {
            if (sign(a * p[i-1].x + b * p[i-1].y + c) > 0){
                q[++curCnt] = intersection(p[i], p[i-1], a, b, c);
            }
            if (sign(a * p[i+1].x + b * p[i+1].y + c) > 0){
                q[++curCnt] = intersection(p[i], p[i+1], a, b, c);
            }
        }
    }
    double area = 0;
    for (int i = 1; i <= curCnt; i++)
        area += p[i].x * p[i + 1].y - p[i + 1].x * p[i].y;
    area = fabs(area / 2.0);
    if (area <= eps) flag = 0;
    for (int i = 1; i <= curCnt; i++)
        p[i] = q[i];
    p[curCnt+1] = q[1];
    p[0] = p[curCnt];
    cCnt = curCnt;
}
void solve(int k){
    initial();
    flag = 1;
    for (int i = 1; i <= n; i++){
        if (i == k) continue;
        double a, b, c;
        getABC(nodes[k], nodes[i], a, b, c);
        cut(a, b, c);
        if (flag == 0){
            break;
        }
    }
    if (flag)
        printf("Yes\n");
    else
        printf("No\n");
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lf %lf %lf", &nodes[i].x, &nodes[i].y, &nodes[i].z);
    for (int i = 1; i <= n; i++){
        solve(i);
    }
    return 0;
}
