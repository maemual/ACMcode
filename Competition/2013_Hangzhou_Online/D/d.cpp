#include<cstdio>
#include<cmath>
using namespace std;

#define eps 1e-6
struct point3{
    double x, y, z;
    point3() {}
    point3(double _x, double _y, double _z): x(_x), y(_y), z(_z) {}
}p1, p2, p3, p4;
struct line3{
    point3 a, b;
    line3() {}
    line3(point3 pa, point3 pb):a(pa), b(pb) {}
};

inline point3 xmult(const point3& u, const point3& v){
    point3 ret;
    ret.x = u.y * v.z - v.y * u.z;
    ret.y = u.z * v.x - u.x * v.z;
    ret.z = u.x * v.y - u.y * v.x;
    return ret;
}
inline double dmult(const point3& u, const point3& v){
    return u.x * v.x + u.y * v.y + u.z * v.z;
}
inline point3 subt(const point3 u, const point3 v){
    point3 ret;
    ret.x = u.x - v.x;
    ret.y = u.y - v.y;
    ret.z = u.z - v.z;
    return ret;
}
inline double vlen(const point3& p){
    return sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
}
double linetoline(const line3& u, const line3& v){
    point3 n = xmult(subt(u.a, u.b), subt(v.a, v.b));
    return fabs(dmult(subt(u.a, v.a), n)) / vlen(n);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &p1.z, &p2.x, &p2.y, &p2.z, &p3.x, &p3.y, &p3.z, &p4.x, &p4.y, &p4.z);
        double dis = linetoline(line3(p1, p2), line3(p3, p4));
        point3 p11 = subt(p2, p1);
        point3 p22 = subt(p4, p3);
        point3 p = xmult(p11, p22);

        double t1 = dmult(xmult(subt(p3, p1), p22), xmult(p11, p22));
        t1 /= vlen(p)*vlen(p);

        double t2 = dmult(xmult(subt(p3, p1), p11), xmult(p11, p22));
        t2 /= vlen(p)*vlen(p);
        point3 mid1, mid2;
        mid1.x = p1.x + p11.x * t1;
        mid1.y = p1.y + p11.y * t1;
        mid1.z = p1.z + p11.z * t1;

        mid2.x = p3.x + p22.x * t2;
        mid2.y = p3.y + p22.y * t2;
        mid2.z = p3.z + p22.z * t2;

        printf("%.6lf\n", dis);
        printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n", mid1.x, mid1.y, mid1.z, mid2.x, mid2.y, mid2.z);
    }
    return 0;
}
