#include<math.h>
#include<cstdio>
#include<time.h>
#include<stdlib.h>

#define MAX_LEN 1000
#define eps 1e-8
#define PI acos(-1.0)

//zero(x)判断一个数是否为0 ok
//判断一个数是否为0，是则返回true，否则返回false
#define zero(x) (((x)>0?(x):-(x))<eps)

//_sign(x)返回一个数的符号
//返回一个数的符号，正数返回1，负数返回2，否则返回0
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))

struct point{
    double x, y;
    point() {}
    point(double _x, double _y):x(_x), y(_y){}
};
struct line{
    point a, b;
    line() {}
    line(point p1, point p2):a(p1), b(p2) {}
};
struct Line{double a, b, c;};

//xmult求矢量[p0,p1],[p0,p2]的叉积 ok
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

//dist两点间距离 ok
double dist(point p1, point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

//dist2两点间距离的平方
double dist2(point p1, point p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}


//dots_inline判三点共线 ok
int dots_inline(point p1, point p2, point p3){
    return zero(xmult(p1, p2, p3));
}

//dot_line判断点是否在线段上
//包括端点 ok
int dot_online_in(point p, line l){
    return zero(xmult(p, l.a, l.b))&&(l.a.x-p.x)*(l.b.x-p.x)<eps&&(l.a.y-p.y)*(l.b.y-p.y)<eps;
}
//不包括端点 ok
int dot_online_ex(point p, line l){
    return dot_online_in(p,l)&&(!zero(p.x-l.a.x)||!zero(p.y-l.a.y))&&(!zero(p.x-l.b.x)||!zero(p.y-l.b.y));
}

//same_side判断点在线段同侧 ok
//点在线段上返回0
int same_side(point p1, point p2, line l){
    return xmult(l.a, p1, l.b)*xmult(l.a, p2, l.b)>eps;
}

//opposite_side判两点在线段异侧 ok
//点在线段上返回0
int opposite_side(point p1, point p2, line l){
    return xmult(l.a, p1, l.b)*xmult(l.a, p2, l.b)<-eps;
}

//parallel判两直线平行 ok
//两直线共线时，也判为平行
int parallel(line u, line v){
    return zero((u.a.x-u.b.x)*(v.a.y-v.b.y)-(v.a.x-v.b.x)*(u.a.y-u.b.y));
}

//perpendicular判两直线垂直 ok
int perpendicular(line u, line v){
    return zero((u.a.x-u.b.x)*(v.a.x-v.b.x)+(u.a.y-u.b.y)*(v.a.y-v.b.y));
}

//intersect判两线段相交
//包括端点和部分重合 ok
int intersect_in(line u, line v){
    if (!dots_inline(u.a, u.b, v.a) || !dots_inline(u.a, u.b, v.b))
        return !same_side(u.a, u.b, v)&&!same_side(v.a, v.b, u);
    return dot_online_in(u.a, v)||dot_online_in(u.b, v)||dot_online_in(v.a, u)||dot_online_in(v.b,u);
}
//不包括端点和部分重合 ok
int intersect_ex(line u, line v){
    return opposite_side(u.a, u.b, v)&&opposite_side(v.a, v.b, u);
}

//intersection计算两直线交点 ok
//计算两直线交点，注意先判断直线是否平行
//线段交点请另外判断线段相交
//线段端点相交也可以使用
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

//ptoline点到直线上的最近点 ok
point ptoline(point p, line l){
    point t = p;
    t.x += l.a.y - l.b.y;
    t.y += l.b.x - l.a.x;
    return intersection(p, t, l.a, l.b);
}

//disptoline点到直线距离 ok
double disptoline(point p, line l){
    return fabs(xmult(p, l.a, l.b)) / dist(l.a, l.b);
}

//ptoseg点到线段上的最近点 ok
point ptoseg(point p, line l){
    point t = p;
    t.x += l.a.y - l.b.y;
    t.y += l.b.x - l.a.x;
    if (xmult(l.a, t, p)*xmult(l.b, t, p)>eps)
        return dist(p,l.a)<dist(p,l.b)?l.a:l.b;
    return intersection(p, t, l.a, l.b);
}

//disptoseg点到线段的距离 ok
double disptoseg(point p, line l){
    point t = p;
    t.x += l.a.y - l.b.y;
    t.y += l.b.x - l.a.x;
    if (xmult(l.a, t, p)*xmult(l.b, t, p)>eps)
        return dist(p, l.a)<dist(p, l.b)?dist(p, l.a):dist(p, l.b);
    return fabs(xmult(p, l.a, l.b)) / dist(l.a, l.b);
}

//symmetricalPoint点关于点的对称点 ok
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

//isSimple判断是否是简单多边形 ok
//注意传入的点要去重，下标从0开始
bool isSimple(point p[], int n){
    if (n < 3) return false;
    line l1, l2;
    for (int i = 0; i < n - 1; i++){
        l1 = line(p[i], p[i+1]);
        for (int j = i + 1; j < n; j++){
            l2 = line(p[j], p[(j+1)%n]);
            if (j == i + 1){
                if (dot_online_in(l2.b, l1) || dot_online_in(l1.a, l2))
                    return false;
            }else if (j == n - i - 1){
                if (dot_online_in(l2.a, l1) || dot_online_in(l1.b, l2))
                    return false;
            }else if (intersect_ex(l1, l2))
                return false;
        }
    }
    return true;
}

//is_convex判定凸多边形
//顶点按顺时针或逆时针给出，允许相邻边共线 ok
int is_convex(int n, point p[]){
    int i, s[3] = {1, 1, 1};
    for (i = 0; i < n && s[1]|s[2]; i++)
        s[_sign(xmult(p[(i+1)%n], p[(i+2)%n], p[i]))] = 0;
    return s[1] | s[2];
}
//不允许相邻边共线 ok
int is_convex_v2(int n, point p[]){
    int i, s[3] = {1, 1, 1};
    for (i = 0; i < n && s[0] && s[1] | s[2]; i++)
        s[_sign(xmult(p[(i+1)%n], p[(i+2)%n], p[i]))] = 0;
    return s[0] && s[1] | s[2];
}

//inside_convex判点在凸多边形内
//顶点按顺时针或逆时针给出 ok
int inside_convex(point q, int n, point p[]){
    int i, s[3] = {1, 1, 1};
    for (i = 0; i < n && s[1]|s[2]; i++)
        s[_sign(xmult(p[(i+1)%n], q, p[i]))] = 0;
    return s[1] | s[2];
}
//在多边形边上返回0 ok
int inside_convex_v2(point q, int n, point p[]){
    int i, s[3] = {1, 1, 1};
    for (i = 0; i < n && s[0] && s[1] | s[2]; i++)
        s[_sign(xmult(p[(i+1)%n], q, p[i]))] = 0;
    return s[0]&&s[1]|s[2];
}

//inside_polygon判点在任意多边形内 ok
//on_edge表示点在多边形边上时的返回值，offset为多边形坐标上限
//on_edge设为1表示点在多边形边上视为在多边形内部，设为0视为在多边形外部
//默认情况下on_edge = 1
int inside_polygon(point q, int n, point p[], int offset, int on_edge = 1){
    point q2;
    int i = 0, count;
    srand((unsigned)time(NULL));
    while (i < n){
        count = 0;
        q2.x = rand() + offset;
        q2.y = rand() + offset;
        for (i = 0; i < n; i++){
            if (zero(xmult(q, p[i], p[(i+1)%n]))
                &&(p[i].x-q.x)*(p[(i+1)%n].x-q.x)<eps
                &&(p[i].y-q.y)*(p[(i+1)%n].y-q.y)<eps)
                return on_edge;
            else if (zero(xmult(q, q2, p[i])))
                break;
            else if (xmult(q, p[i], q2)*xmult(q, p[(i+1)%n], q2)<-eps
                    && xmult(p[i], q, p[(i+1)%n])*xmult(p[i], q2, p[(i+1)%n])<-eps)
                count++;
        }
    }
    return count&1;
}

//inside_polygon判断线段在任意多边形内，与边界相交返回1 ok
int inside_polygon(line l1, int n, point p[]){
    point t[MAX_LEN], tt;
    int i, j, k = 0;
    //inside_polygon第四个参数默认为1（点在多边形上视为在内部）
    if (!inside_polygon(l1.a, n, p, MAX_LEN/*offset*/) || !inside_polygon(l1.b, n, p, MAX_LEN))
        return 0;
    for (i = 0; i < n; i++){
        if (opposite_side(l1.a, l1.b, line(p[i], p[(i+1)%n]))
            && opposite_side(p[i], p[(i+1)%n], l1))
            return 0;
        else if (dot_online_in(l1.a, line(p[i], p[(i+1)%n])))
            t[k++] = l1.a;
        else if (dot_online_in(l1.b, line(p[i], p[(i+1)%n])))
            t[k++] = l1.b;
        else if (dot_online_in(p[i], l1))
            t[k++] = p[i];
    }
    for (i = 0; i < k; i++){
        for (j = i + 1; j < k; j++){
            tt.x = (t[i].x + t[j].x) * 0.5;
            tt.y = (t[i].y + t[j].y) * 0.5;
            if (!inside_polygon(tt, n, p, MAX_LEN))
                return 0;
        }
    }
    return 1;
}

//barycenter任意多边形的重心
//适用于凸多边形和凹多边形，顶点顺序
point barycenter(int n, point p[]){
    point center;
    double sumx, sumy, suma;
    double x0, y0, x1, y1, x2, y2;
    double x, y, s;
    x0 = p[0].x;
    y0 = p[0].y;
    x1 = p[1].x;
    y1 = p[1].y;
    sumx = sumy = suma = 0;
    for (int i = 2; i < n; i++){
        x2 = p[i].x;
        y2 = p[i].y;
        x = x0 + x1 + x2;
        y = y0 + y1 + y2;
        s = x0*y1 + x1*y2 + x2*y0 - x1*y0 - x2*y1 - x0*y2;
        suma += s;
        sumx += s * x;
        sumy += s * y;
        x1 = x2;
        y1 = y2;
    }
    center.x = sumx / suma / 3;
    center.y = sumy / suma / 3;
    return center;
}

//area_of_polygon多边形面积 ok
//输入顶点按逆时针，返回正值，否则返回负值
double area_of_polygon(int n, point p[]){
    int i;
    double s;
    if (n < 3) return 0;
    s = p[0].y * (p[n-1].x - p[1].x);
    for (i = 1; i < n; i++)
        s += p[i].y * (p[i-1].x - p[(i+1)%n].x);
    return s / 2;
}

//Diameter凸多边形直径 ok
//输入凸包
//旋转卡壳
double AreaTria(point a, point b, point c){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

double Diameter(point p[], int n){
    int i, j, k;
    double dia = 0;
    if (n == 2) return dist(p[0], p[1]);
    for (i = 0, j = 1, k = 1; true; i = (i + 1)%n, j = (j + 1) % n){
        double a = AreaTria(p[i], p[j], p[k]);
        int l = (k + 1) % n;
        double b = AreaTria(p[i], p[j], p[l]);
        while (a <= b){
            k = l;
            a = b;
            l = (l + 1) % n;
            b = AreaTria(p[i], p[j], p[l]);
        }
        double tmp = dist(p[j], p[k]);
        if (tmp > dia) dia = tmp;
        if (i == n - 1) break;
    }
    return dia;
}

//polygon_cut多边形切割
//将多边形沿直线l1切割在side侧，保证l1和side不共线
void polygon_cut(int &n, point p[], line l1, point side){
    point pp[MAX_LEN];
    int m = 0, i;
    for (i = 0; i < n; i++){
        if (same_side(p[i], side, l1))
            pp[m++] = p[i];
        if (!same_side(p[i], p[(i+1)%n], l1)
            && !(zero(xmult(p[i], l1.a, l1.b)))
            && zero(xmult(p[(i+1)%n], l1.a, l1.b)))
            pp[m++] = intersection(p[i], p[(i+1)%n], l1.a, l1.b);
    }
    for (n = i = 0; i < m; i++){
        if (!i || !zero(pp[i].x-pp[i-1].x) || !zero(pp[i].y - pp[i-1].y))
            p[n++] = pp[i];
    }
    if (zero(p[n-1].x-p[0].x)&&zero(p[n-1].y-p[0].y))
        n--;
    if (n < 3) n = 0;
}

int main()
{
    return 0;
}
