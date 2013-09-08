#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x)) < eps)
struct point{
    double x, y;
    point() {}
    point(double _x, double _y):x(_x), y(_y){}
}p[105], px[5];
int n;

inline double xmult(const point& p1, const point& p2, const point& p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
inline int dots_inline(const point& p1, const point& p2, const point& p3){
    return zero(xmult(p1, p2, p3));
}
bool check(){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                if (!dots_inline(p[i], p[j], p[k]))
                    return false;
            }
        }
    }
    return true;
}
double area_of_polygon(int n, point pt[]){
    double s = pt[0].y * (pt[n-1].x - pt[1].x);
    for (int i = 1; i < n; i++)
        s += pt[i].y * (pt[i-1].x - pt[(i+1)%n].x);
    return fabs(s) / 2.0;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%lf %lf", &p[i].x, &p[i].y);
        }
        if (n < 3 || check()){
            printf("Impossible\n");
            continue;
        }
        double mmin = 1e100;
        for (int i = 0; i < n; i++){
            for (int j = i + 1; j < n; j++){
                for (int k = j + 1; k < n; k++){
                    if (dots_inline(p[i], p[j], p[k])) continue;
                    px[0] = p[i];
                    px[1] = p[j];
                    px[2] = p[k];
                    double area = area_of_polygon(3, px);
                    if (area < mmin)
                        mmin = area;
                }
            }
        }
        printf("%.2lf\n", mmin);
    }
    return 0;
}
