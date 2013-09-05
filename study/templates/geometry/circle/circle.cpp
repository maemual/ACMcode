#include<math.h>

#define eps 1e-8
#define PI acos(-1.0)

struct point{
    double x, y;
    point() {}
    point(double _x, double _y):x(_x), y(_y) {}
};
struct line{
    point a, b;
    line() {}
    line(point p1, point p2):a(p1), b(p2){}
};
struct circle{
    point center;
    double r;
    circle() {}
    circle(point p, double _r): center(p), r(_r){}
};
double xmult(point p1, point p2, point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

double dist(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double disptoline(point p, line l){
    return fabs(xmult(p, l.a, l.b)) / dist(l.a, l.b);
}

point intersection(line l1, line l2){
    point ret = l1.a;
    double t = ((l1.a.x-l2.a.x)*(l2.a.y-l2.b.y)-(l1.a.y-l2.a.y)*(l2.a.x-l2.b.x))
            / ((l1.a.x-l1.b.x)*(l2.a.y-l2.b.y)-(l1.a.y-l1.b.y)*(l2.a.x-l2.b.x));
    ret.x += (l1.b.x-l1.a.x)*t;
    ret.y += (l1.b.y-l1.a.y)*t;
    return ret;
}

point rotate(point p, double angle){
    point res;
    res.x = p.x * cos(angle) - p.y * sin(angle);
    res.y = p.x * sin(angle) + p.y * cos(angle);
    return res;
}

//判直线和圆相交，包括相切
int intersect_line_circle(circle c, line l){
    return disptoline(c.center, l) < c.r + eps;
}

//判断线段和圆相交，包括端点和相切
int intersect_seg_circle(circle c, line l){
    double t1 = dist(c.center, l.a) - c.r;
    double t2 = dist(c.center, l.b) - c.r;
    point t = c.center;
    if (t1 < eps || t2 < eps)
        return t1 > -eps || t2 > -eps;
    t.x += l.a.y - l.b.y;
    t.y += l.b.x - l.a.x;
    return xmult(l.a, c.center, t) * xmult(l.b, c.center, t) < eps
        && disptoline(c.center, l) - c.r < eps;
}

//判圆和圆相交，包括相切
int intersect_circle_circle(circle c1, circle c2){
    return dist(c1.center, c2.center) < c1.r + c2.r + eps
        && dist(c1.center, c2.center) > fabs(c1.r-c2.r) - eps;
}

//计算圆上到点p最近的点，如果p与圆心重合，返回p本身
point dot_to_circle(circle c, point p){
    point u, v;
    if (dist(p, c.center) < eps)
        return p;
    u.x = c.center.x + c.r * fabs(c.center.x - p.x) / dist(c.center, p);
    u.y = c.center.y + c.r * fabs(c.center.y - p.y) / dist(c.center, p)
        * ((c.center.x-p.x)*(c.center.y-p.y)<0?-1:1);
    v.x = c.center.x - c.r * fabs(c.center.x - p.x) / dist(c.center, p);
    v.y = c.center.y - c.r * fabs(c.center.y - p.y) / dist(c.center, p)
        * ((c.center.x-p.x)*(c.center.y-p.y)<0?-1:1);
    return dist(u, p) < dist(v, p)?u:v;
}

//计算直线与圆的交点，保证直线与圆有交点
//计算线段与圆的交点，可用这个函数后判断点是否在线段上
void intersection_line_circle(circle c, line l, point &p1, point &p2){
    point p = c.center;
    double t;
    p.x += l.a.y - l.b.y;
    p.y += l.b.x - l.a.x;
    p = intersection(line(p, c.center), l);
    t = sqrt(c.r*c.r-dist(p, c.center)*dist(p, c.center)) / dist(l.a, l.b);
    p1.x = p.x + (l.b.x-l.a.x) * t;
    p1.y = p.y + (l.b.y-l.a.y) * t;
    p2.x = p.x - (l.b.x-l.a.x) * t;
    p2.y = p.y - (l.b.y-l.a.y) * t;
}

//计算圆与圆的交点保证圆与圆有交点，圆心不重合
void intersection_circle_circle(circle c1, circle c2, point &p1, point &p2){
    point u, v;
    double t = (1 + (c1.r*c1.r-c2.r*c2.r)) / dist(c1.center, c2.center)
            / dist(c1.center, c2.center) / 2;
    u.x = c1.center.x + (c2.center.x-c1.center.x)*t;
    u.y = c1.center.y + (c2.center.y-c1.center.y)*t;
    v.x = u.x + c1.center.y - c2.center.x;
    v.y = u.y - c1.center.x + c2.center.x;
    intersection_line_circle(c1, line(u, v), p1, p2);
}

//求圆外一点，对圆的两个切点
void tangentPoint_PC(circle c, point p, point &res1, point &res2){
    double angle = acos(c.r / dist(p, c.center));
    point u, v;
    v.x = p.x - c.center.x;
    v.y = p.y - c.center.y;
    u.x = v.x / sqrt(v.x*v.x+v.y*v.y) * c.r;
    u.y = v.y / sqrt(v.x*v.x+v.y*v.y) * c.r;
    res1 = rotate(u, -angle);
    res2 = rotate(u, angle);
    res1.x += c.center.x;
    res1.y += c.center.y;
    res2.x += c.center.x;
    res2.y += c.center.y;
}

int main()
{
    return 0;
}
