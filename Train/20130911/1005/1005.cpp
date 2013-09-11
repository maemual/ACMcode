#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)

struct point{
    double x, y;
    point() {}
    point(double _x, double _y):x(_x), y(_y) {}
};
struct line{
    point a, b;
    line(){}
    line(point p1, point p2):a(p1), b(p2){}
};

int flag;
inline double xmult(const point& p1, const point& p2, const point& p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
inline double dmult(const point& p1, const point& p2, const point& p0){
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
inline int dots_inline(const point& p1, const point& p2, const point& p3){
    return zero(xmult(p1, p2, p3));
}
inline double dist(const point& p1, const point& p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
point intersection(const line& u, const line& v){
    point ret = u.a;
    double t = ((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
            / ((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x += (u.b.x - u.a.x) * t;
    ret.y += (u.b.y - u.a.y) * t;
    return ret;
}
point circumcenter(const point& a, const point& b, const point& c){
    line u, v;
    u.a.x = (a.x + b.x) / 2;
    u.a.y = (a.y + b.y) / 2;
    u.b.x = u.a.x - a.y + b.y;
    u.b.y = u.a.y + a.x - b.x;
    v.a.x = (a.x + c.x) / 2;
    v.a.y = (a.y + c.y) / 2;
    v.b.x = v.a.x - a.y + c.y;
    v.b.y = v.a.y + a.x - c.x;
    return intersection(u, v);
}
inline int dot_online_in(const point& p, const line& l){
    return zero(xmult(p, l.a, l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps
        && (l.a.y-p.y)*(l.b.y-p.y)<eps;
}
bool has_dun(const point& p0, const point& p1, const point& p2){
    if (dmult(p1, p2, p0) < 0){
        flag = 0;
        return true;
    }else if (dmult(p0, p2, p1) < 0){
        flag = 1;
        return true;
    }else if (dmult(p0, p1, p2) < 0){
        flag = 2;
        return true;
    }
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);
    point p[5];
    point m;
    for (int k = 1; k <= T; k++){
        scanf("%lf%lf%lf%lf%lf%lf", &p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y);
        scanf("%lf%lf", &m.x, &m.y);
        flag = -1;
        if (dots_inline(p[0], p[1], p[2])){
            point center;
            double r;
            if (dot_online_in(p[0], line(p[1], p[2]))){
                center.x = (p[1].x + p[2].x) / 2;
                center.y = (p[1].y + p[2].y) / 2;
                r = dist(center, p[1]);
            }else if (dot_online_in(p[1], line(p[0], p[2]))){
                center.x = (p[0].x + p[2].x) / 2;
                center.y = (p[0].y + p[2].y) / 2;
                r = dist(center, p[0]);
            }else{
                center.x = (p[1].x + p[0].x) / 2;
                center.y = (p[1].y + p[0].y) / 2;
                r = dist(center, p[1]);
            }
            if (dist(center, m) <= r){
                printf("Case #%d: Danger\n", k);
            }else{
                printf("Case #%d: Safe\n", k);
            }
        }else if (has_dun(p[0], p[1], p[2])){
            point center;
            double r;
            if (flag == 0){
                center.x = (p[1].x + p[2].x) / 2;
                center.y = (p[1].y + p[2].y) / 2;
                r = dist(center, p[1]);
            }else if (flag == 1){
                center.x = (p[0].x + p[2].x) / 2;
                center.y = (p[0].y + p[2].y) / 2;
                r = dist(center, p[0]);
            }else if (flag == 2){
                center.x = (p[0].x + p[1].x) / 2;
                center.y = (p[0].y + p[1].y) / 2;
                r = dist(center, p[0]);
            }
            if (dist(center, m) <= r){
                printf("Case #%d: Danger\n", k);
            }else{
                printf("Case #%d: Safe\n", k);
            }
        }else{
            point center = circumcenter(p[0], p[1], p[2]);
            double r = dist(center, p[0]);
            if (dist(center, m) <= r){
                printf("Case #%d: Danger\n", k);
            }else{
                printf("Case #%d: Safe\n", k);
            }
        }
    }
    return 0;
}
