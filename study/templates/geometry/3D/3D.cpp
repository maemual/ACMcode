#include<math.h>

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)

struct point3{
    double x, y, z;
    point3() {}
    point3(double _x, double _y, double _z):x(_x), y(_y), z(_z){}
};
struct line3{
    point3 a, b;
    line3() {}
    line3(point3 p1, point3 p2):a(p1), b(p2){}
};
struct plane3{
    point3 a, b, c;
    plane3() {}
    plane3(point3 p1, point3 p2, point3 p3):a(p1), b(p2), c(p3) {}
};

//xmult
point3 xmult(point3 u, point3 v){
    point3 ret;
    ret.x = u.y * v.z - v.y * u.z;
    ret.y = u.z * v.x - u.x * v.z;
    ret.z = u.x * v.y - u.y * v.x;
    return ret;
}

//dmult
double dmult(point3 u, point3 v){
    return u.x * v.x + u.y * v.y + u.z * v.z;
}

//subt矢量差，U - V
point3 subt(point3 u, point3 v){
    point3 ret;
    ret.x = u.x - v.x;
    ret.y = u.y - v.y;
    ret.z = u.z - v.z;
    return ret;
}

//pvec取平面法向量
point3 pvec(plane3 s){
    return xmult(subt(s.a, s.b), subt(s.b, s.c));
}

//dist两点距离
double dist(point3 p1, point3 p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}

//vlen向量大小
double vlen(point3 p){
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}

//dots_inline判三点共线
int dots_inline(point3 p1, point3 p2, point3 p3){
    return vlen(xmult(subt(p1, p2), subt(p2, p3))) < eps;
}

//dots_onplane判四点共面
int dots_onplane(point3 a, point3 b, point3 c, point3 d){
    return zero(dmult(pvec(plane3(a, b, c)), subt(d, a)));
}

//dot_online判点是否在线段上
//包括端点
int dot_online_in(point3 p, line3 l){
    return zero(vlen(xmult(subt(p, l.a), subt(p, l.b))))
        && (l.a.x-p.x)*(l.b.x-p.x)<eps
        && (l.a.y-p.y)*(l.b.y-p.y)<eps
        && (l.a.z-p.z)*(l.b.z-p.z)<eps;
}
//不包括端点
int dot_online_ex(point3 p, line3 l){
    return dot_online_in(p, l)
        && (!zero(p.x-l.a.x)||!zero(p.y-l.a.y)||!zero(p.z-l.a.z))
        && (!zero(p.x-l.b.x)||!zero(p.y-l.b.y)||!zero(p.z-l.b.z));
}

//dot_inplane判点是否在空间三角形上
//包括边界，三点共线无意义
int dot_inplane_in(point3 p, plane3 s){
    return zero(vlen(xmult(subt(s.a, s.b), subt(s.a, s.c)))
            - vlen(xmult(subt(p, s.a), subt(p, s.b)))
            - vlen(xmult(subt(p, s.b), subt(p, s.c)))
            - vlen(xmult(subt(p, s.c), subt(p, s.a))));
}
//不包括边界，三点共线无意义
int dot_inplane_ex(point3 p, plane3 s){
    return dot_inplane_in(p, s)
        && vlen(xmult(subt(p, s.a), subt(p, s.b)))>eps
        && vlen(xmult(subt(p, s.b), subt(p, s.c)))>eps
        && vlen(xmult(subt(p, s.c), subt(p, s.a)))>eps;
}

//same_side判两点在线段同侧
int same_side(point3 p1, point3 p2, line3 l){
    return dmult(xmult(subt(l.a, l.b), subt(p1, l.b))
            , xmult(subt(l.a, l.b), subt(p2, l.b))) > eps;
}

//opposite_side判两点在线段异侧
int opposite_side(point3 p1, point3 p2, line3 l){
    return dmult(xmult(subt(l.a, l.b), subt(p1, l.b))
            , xmult(subt(l.a, l.b), subt(p2, l.b))) < -eps;
}

//same_side判两点在平面同侧
int same_side(point3 p1, point3 p2, plane3 s){
    return dmult(pvec(s), subt(p1, s.a))
        * dmult(pvec(s), subt(p2, s.a)) > eps;
}

//opposite_side判两点咋平面异侧
int opposite_side(point3 p1, point3 p2, plane3 s){
    return dmult(pvec(s), subt(p1, s.a))
        * dmult(pvec(s), subt(p2, s.a)) < -eps;
}

//parallel判两直线平行
//包括重合
int parallel(line3 u, line3 v){
    return vlen(xmult(subt(u.a, u.b), subt(v.a, v.b))) < eps;
}

//parallel判两平面平行
int parallel(plane3 u, plane3 v){
    return vlen(xmult(pvec(u), pvec(v))) < eps;
}

//parallel判直线与平面平行
//包括直线在平面内
int parallel(line3 l, plane3 s){
    return zero(dmult(subt(l.a, l.b), pvec(s)));
}

//perpendicular判两直线垂直
int perpendicular(line3 u, line3 v){
    return zero(dmult(subt(u.a, u.b), subt(v.a, v.b)));
}

//perpendicular判两平面垂直
int perpendicular(plane3 u, plane3 v){
    return zero(dmult(pvec(u), pvec(v)));
}

//perpendicular判直线与平面垂直
int perpendicular(line3 l, plane3 s){
    return vlen(xmult(subt(l.a, l.b), pvec(s))) < eps;
}

//intersect两线段相交
//包括端点和部分重合
int intersect_in(line3 u, line3 v){
    if (!dots_onplane(u.a, u.b, v.a, v.b))
        return 0;
    if (!dots_inline(u.a, u.b, v.a)||!dots_inline(u.a, u.b, v.b))
        return !same_side(u.a, u.b, v) && !same_side(v.a, v.b, u);
    return dot_online_in(u.a, v)||dot_online_in(u.b, v)
        || dot_online_in(v.a, u)||dot_online_in(v.b, u);
}
//不包括端点和部分重合
int intersect_ex(line3 u, line3 v){
    return dots_onplane(u.a, u.b, v.a, v.b)
        && opposite_side(u.a, u.b, v)&&opposite_side(v.a, v.b, u);
}

//intersect判线段和空间三角形相交
//包括交于边界和部分包含
int intersect_in(line3 l, plane3 s){
    return !same_side(l.a, l.b, s)&&!same_side(s.a, s.b, plane3(l.a, l.b, s.c))
        && !same_side(s.b, s.c, plane3(l.a, l.b, s.a))&&!same_side(s.c, s.a, plane3(l.a, l.b, s.b));
}
//不包括边界和部分包含
int intersect_ex(line3 l, plane3 s){
    return opposite_side(l.a, l.b, s)&&opposite_side(s.a, s.b, plane3(l.a, l.b, s.c))
        && opposite_side(s.b, s.c, plane3(l.a, l.b, s.a))&&opposite_side(s.c, s.a, plane3(l.a, l.b, s.b));
}

//intersection计算两直线交点
//请事先判断两直线是否共面和平行
//线段交点请另外判断线段相交
point3 intersection(line3 u, line3 v){
    point3 ret = u.a;
    double t = ((u.a.x-v.a.x)*(v.a.y-v.b.y)-(u.a.y-v.a.y)*(v.a.x-v.b.x))
        / ((u.a.x-u.b.x)*(v.a.y-v.b.y)-(u.a.y-u.b.y)*(v.a.x-v.b.x));
    ret.x += (u.b.x-u.a.x) * t;
    ret.y += (u.b.y-u.a.y) * t;
    ret.z += (u.b.z-u.a.z) * t;
    return ret;
}

//intersection计算直线与平面交点
//注意事先判断是否平行，并保证三点不共线
//线段和空间三角形交点请另外判断
point3 intersection(line3 l, plane3 s){
    point3 ret = pvec(s);
    double t = (ret.x*(s.a.x-l.a.x)+ret.y*(s.a.y-l.a.y)+ret.z*(s.a.z-l.a.z))
        / (ret.x*(l.b.x-l.a.x)+ret.y*(l.b.y-l.a.y)+ret.z*(l.b.z-l.a.z));
    ret.x = l.a.x+(l.b.x-l.a.x)*t;
    ret.y = l.a.y+(l.b.y-l.a.y)*t;
    ret.z = l.a.z+(l.b.z-l.a.z)*t;
    return ret;
}
//intersection计算两平面交线
line3 intersection(plane3 u, plane3 v){
    line3 ret;
    ret.a = parallel(line3(v.a, v.b), u)?
        intersection(line3(v.b, v.c), u):
        intersection(line3(v.a, v.b), u);
    ret.b = parallel(line3(v.c, v.a), u)?
        intersection(line3(v.b, v.c), u):
        intersection(line3(v.c, v.a), u);
    return ret;
}

//ptoline点到直线距离
double ptoline(point3 p, line3 l){
    return vlen(xmult(subt(p, l.a), subt(l.b, l.a))) / dist(l.a, l.b);
}

//ptoplane点到平面距离
double ptoplane(point3 p, plane3 s){
    return fabs(dmult(pvec(s), subt(p, s.a))) / vlen(pvec(s));
}

//linetoline直线到直线的距离
double linetoline(line3 u, line3 v){
    point3 n = xmult(subt(u.a, u.b), subt(v.a, v.b));
    return fabs(dmult(subt(u.a, v.a), n)) / vlen(n);
}

//angle_cos两直线夹角的cos值
double angle_cos(line3 u, line3 v){
    return dmult(subt(u.a, u.b), subt(v.a, v.b))
        / vlen(subt(u.a, u.b))
        / vlen(subt(v.a, v.b));
}

//angle_cos两平面夹角的cos值
double angle_cos(plane3 u, plane3 v){
    return dmult(pvec(u), pvec(v)) / vlen(pvec(u)) / vlen(pvec(v));
}

//angle_sin直线平面夹角的sin值
double angle_sin(line3 l, plane3 s){
    return dmult(subt(l.a, l.b), pvec(s)) / vlen(subt(l.a, l.b)) / vlen(pvec(s));
}

//旋转待补充
//。。。。。。


int main()
{
    return 0;
}
