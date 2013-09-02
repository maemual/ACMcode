#include<math.h>
#include<cstdio>

#define eps 1e-8
#define PI acos(-1.0)

//zero(x)判断一个数是否为0
//判断一个数是否为0，是则返回true，否则返回false
#define zero(x) (((x)>0?(x):-(x))<eps)

//_sign(x)返回一个数的符号
//返回一个数的符号，正数返回1，负数返回2，否则返回0
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))

struct point{
    double x, y;
}p;
struct line{
    point a, b;
}l1, l2;
struct Line{double a, b, c;};

//xmult求矢量[p0,p1],[p0,p2]的叉积
//p0是顶点
//若结果等于0，则三点共线
//若结果大于0，则p0p2在p0p1的逆时针方向
//若结果小于0，则p0p2在p0p1的顺时针方向
double xmult(point p1, point p2, point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

//dmult计算点积(p1-p0)*(p2-p0)
double dmult(point p1, point p2, point p0){
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}

//dist两点间距离
double dist(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

//dots_inline判三点共线
int dots_inline(point p1, point p2, point p3){
    return zero(xmult(p1, p2, p3));
}
//dot_line判断点是否在线段上
//包括端点
int dot_online_in(point p, line l){
    return zero(xmult(p, l.a, l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
//不包括端点
int dot_online_ex(point p, line l){
    return dot_online_in(p,l)&&(!zero(p.x-l.a.x)||!zero(p.y-l.a.y))&&(!zero(p.x-l.b.x)||!zero(p.y-l.b.y));
}

//same_side判断点在线段同侧
int same_side(point p1, point p2, line l){
    return xmult(l.a, p1, l.b)*xmult(l.a, p2, l.b)>eps;
}

//opposite_side判两点在线段异侧
int opposite_side(point p1, point p2, line l){
    return xmult(l.a, p1, l.b)*xmult(l.a, p2, l.b)<-eps;
}

//parallel判两直线平行
//两直线重合，也判为平行
int parallel(line u, line v){
    return zero((u.a.x-u.b.x)*(v.a.y-v.b.y)-(v.a.x-v.b.x)*(u.a.y-u.b.y));
}

//perpendicular判两直线垂直
int perpendicular(line u, line v){
    return zero((u.a.x-u.b.x)*(v.a.x-v.b.x)+(u.a.y-u.b.y)*(v.a.y-v.b.y));
}

//intersect判两线段相交
//包括端点和部分重合
int intersect_in(line u, line v){
    if (!dots_inline(u.a, u.b, v.a) || !dots_inline(u.a, u.b, v.b))
        return !same_side(u.a, u.b, v)&&!same_side(v.a, v.b, u);
    return dot_online_in(u.a, v)||dot_online_in(u.b, v)||dot_online_in(v.a, u)||dot_online_in(v.b,u);
}
//不包括端点和部分重合
int intersect_ex(line u, line v){
    return opposite_side(u.a, u.b, v)&&opposite_side(v.a, v.b, u);
}

//intersection计算两直线交点
//计算两直线交点，注意先判断直线是否平行
//线段交点请另外判断线段相交
point intersection(line u, line v){
    point ret = u.a;
    double t = ((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
            / ((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x += (u.b.x-u.a.x)*t;
    ret.y += (u.b.y-u.a.y)*t;
    return ret;
}
point intersection(point ua, point ub, point va, point vb){
    point ret = ua;
    double t = ((ua.x-va.x)*(va.y-vb.y)-(ua.y-va.y)*(va.x-vb.x))
            / ((ua.x-ub.x)*(va.y-vb.y)-(ua.y-ub.y)*(va.x-vb.x));
    ret.x += (ub.x-ua.x)*t;
    ret.y += (ub.y-ua.y)*t;
    return ret;
}

//ptoline点到直线上的最近点
point ptoline(point p, line l){
    point t = p;
    t.x += l.a.y - l.b.y;
    t.y += l.b.x - l.a.x;
    return intersection(p, t, l.a, l.b);
}

//disptoline点到直线距离
double disptoline(point p, line l){
    return fabs(xmult(p, l.a, l.b)) / dist(l.a, l.b);
}

//ptoseg点到线段上的最近点
point ptoseg(point p, line l){
    point t = p;
    t.x += l.a.y - l.b.y;
    t.y += l.b.x - l.a.x;
    if (xmult(l.a, t, p)*xmult(l.b, t, p)>eps)
        return dist(p,l.a)<dist(p,l.b)?l.a:l.b;
    return intersection(p, t, l.a, l.b);
}

//disptoseg点到线段的距离
double disptoseg(point p, line l){
    point t = p;
    t.x += l.a.y - l.b.y;
    t.y += l.b.x - l.a.x;
    if (xmult(l.a, t, p)*xmult(l.b, t, p)>eps)
        return dist(p, l.a)<dist(p, l.b)?dist(p, l.a):dist(p, l.b);
    return fabs(xmult(p, l.a, l.b)) / dist(l.a, l.b);
}

//symmetricalPoint点关于点的对称点
point symmetricalPoint(point p1, point p2){
    point ret;
    ret.x = 2 * p2.x - p1.x;
    ret.y = 2 * p2.y - p1.y;
    return ret;
}

//symmetricalPointofLine点关于直线的对称点
point symmetricalPointofLine(point p, Line l){
    point ret;
    double d = l.a * l.a + l.b * l.b;
    ret.x = (l.b * l.b * p.x - l.a * l.a * p.x
            - 2 * l.a * l.b * p.y - 2 * l.a * l.c) / d;
    ret.y = (l.a * l.a * p.y - l.b * l.b * p.y
            - 2 * l.a * l.b * p.x - 2 * l.b * l.c) / d;
    return ret;
}

//lineFromSegment求线段所在直线（一般式）
//求线段所在直线，返回直线方程的三个系数
//两点式化为一般式
Line lineFromSegment(point p1, point p2){
    Line tmp;
    tmp.a = p2.y - p1.y;
    tmp.b = p1.x - p2.x;
    tmp.c = p2.x * p1.y - p1.x * p2.y;
    return tmp;
}

//lineInter一般式求直线交点
//注意平行无解，避免RE
point lineInter(Line l1, Line l2){
    point tmp;
    double a1 = l1.a;
    double b1 = l1.b;
    double c1 = l1.c;
    double a2 = l2.a;
    double b2 = l2.b;
    double c2 = l2.c;
    //注意这里b1 = 0
    if (fabs(b1) < eps){
        tmp.x = - c1 / a1;
        tmp.y = (-c2 - a2 * tmp.x) / b2;
    }else{
        tmp.x = (c1 * b2 - b1 * c2) / (b1 * a2 - b2 * a1);
        tmp.y = (-c1 - a1 * tmp.x) / b1;
    }
    return tmp;
}

//rotate二维点旋转
//矢量点v以p为顶点逆时针旋转angle（弧度）并放大scale倍
point rotate(point v, point p, double angle, double scale){
    point ret = p;
    v.x -= p.x;
    v.y -= p.y;
    p.x = scale * cos(angle);
    p.y = scale * sin(angle);
    ret.x += v.x * p.x - v.y * p.y;
    ret.y += v.x * p.y + v.y * p.x;
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    printf("INTERSECTING LINES OUTPUT\n");
    while (T--){
        scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &l1.a.x, &l1.a.y, &l1.b.x, &l1.b.y, &l2.a.x, &l2.a.y, &l2.b.x, &l2.b.y);
        if (parallel(l1, l2) && !(dots_inline(l1.a, l1.b, l2.a) && dots_inline(l1.a, l1.b, l2.b))){
            printf("NONE\n");
        }else{
            if (dots_inline(l1.a, l1.b, l2.a) && dots_inline(l1.a, l1.b, l2.b)){
                printf("LINE\n");
            }else{
                p = intersection(l1, l2);
                printf("POINT %.2f %.2f\n", p.x, p.y);
            }
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
