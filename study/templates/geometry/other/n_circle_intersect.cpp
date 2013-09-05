#include<cstdio>
#include<cmath>
#include<algorithm>
#include<complex>
#include<cstring>
#include<vector>

using namespace std;
#define eps 1e-8
#define zero(x) (((x)>0?x:-(x))<eps)
#define offset 1e100

const int maxn = 100;
const double PI = acos(-1.0);

struct point{
   double x, y;
   point() {}
   point(double _x, double _y):x(_x), y(_y) {}
};
struct circle{
    point center;
    double r;
    circle() {}
    circle(point c, double _r): center(c), r(_r){}
};
struct arc{
    double theta1, theta2;
    arc() {}
    arc(double t1, double t2): theta1(t1), theta2(t2) {}
    bool operator < (const arc& a) const {
        return theta1 - a.theta1 < -eps
            || theta1 - a.theta1 <= eps && theta2 - a.theta2 < -eps;
    }
};

inline double sqr(double x) {return x * x;}
inline double fmax(double a, double b) {return a>b?a:b;}
inline double fmin(double a, double b) {return a>b?b:a;}

vector<arc> interline(const circle c1, const circle c2){
    vector<arc> edge;
    edge.clear();
    complex<double> v(c2.center.x-c1.center.x, c2.center.y-c1.center.y);
    double d = abs(v);
    double a = ((sqr(c1.r)-sqr(c2.r)) / d + d) / 2;
    double dtheta = acos(a / c1.r), alpha = arg(v);
    double theta1 = alpha - dtheta, theta2 = alpha + dtheta;
    if (theta1 < -eps) theta1 += PI * 2;
    if (theta2 < -eps) theta2 += PI * 2;
    if (theta1 > theta2 + eps){
        edge.push_back(arc(theta1, PI*2));
        edge.push_back(arc(0, theta2));
    }
    else{
        edge.push_back(arc(theta1, theta2));
    }
    return edge;
}
arc tmp[maxn];
void inter(vector<arc>& v1, vector<arc> v2){
    int t = 0;
    for (int i = 0; i < v1.size(); i++){
        for (int j = 0; j < v2.size(); j++){
            double st = fmax(v1[i].theta1, v2[j].theta1);
            double en = fmin(v1[i].theta2, v2[j].theta2);
            if (en-st >= -eps){
                tmp[t++] = arc(st, en);
            }
        }
    }
    v1.clear();
    for (int i = 0; i < t; i++){
        v1.push_back(tmp[i]);
    }
}
//使用格林公式
double doarea(double a1, double a2, circle c){
    return sqr(c.r) / 2 * (a2-a1) + c.r / 2 * (c.center.x*sin(a2)-c.center.y*cos(a2)
            - c.center.x*sin(a1)+c.center.y*cos(a1));
}
//对待求交的圆进行预处理并消除冗余
//若其中两圆相离，直接返回0表示，公共面积为0
//对包含其他圆（包括内含、内切、相同)的圆直接删除，在以后处理中不予考虑
int preprocess(int& n, circle cir[]){
    bool exist[maxn];
    memset(exist, true, sizeof(exist));
    for (int i = 0; i < n; i++){
        if (!exist[i]) continue;
        for (int j = 0; j < n; j++){
            if ((!exist[j]) || j==i) continue;
            double deltar = cir[j].r - cir[i].r;
            double sumr = cir[j].r + cir[i].r;
            double dst_c1_c2 = sqrt(sqr(cir[i].center.x-cir[j].center.x)
                        + sqr(cir[i].center.y-cir[j].center.y));
            //cir[j]包含（内含、内切） cir[i] 或者
            //cir[j]与cir[i]相同
            if (deltar - dst_c1_c2 >= -eps)
                exist[j] = false;

            //cir[i]与cir[j]相离
            if (dst_c1_c2 - sumr > eps)
                return 0;
        }
    }
    int t = 0;
    for (int i = 0; i < n; i++){
        if (exist[i])
            cir[t++] = cir[i];
    }
    n = t;
    return 1;
}
//area为返回的所求的面积
//n为圆的个数
//若n个圆的公共部分仅为一个点，函数返回这一点，其他情况下返回值无意义
//可通过判断返回值是否是onlypt的缺省值来判断n个圆是否只交于一点
//offset为定义的表示无穷大的宏
point cal_cir_inter_area(double &area, int n, circle cir[], point onlypt = point(offset, offset)){
    area = 0;
    if (!preprocess(n, cir))
        return onlypt;
    for (int i = 0; i < n; i++){
        vector<arc> edge;
        edge.clear();
        edge.push_back(arc(0, PI * 2));
        for (int j = 0; j < n; j++)
            if (j != i)
                inter(edge, interline(cir[i], cir[j]));
        /*若不要求唯一的公共点，此段可删去*/
        if (edge.size() == 1){
            if (zero(edge[0].theta1 - edge[0].theta2)){
                onlypt.x = cir[i].center.x + cir[i].r * cos(edge[0].theta1);
                onlypt.y = cir[i].center.y + cir[i].r * sin(edge[0].theta1);
                return onlypt;
            }
        }
        /*若不要求唯一的公共点，此段可删去*/

        for (int j = 0; j < edge.size(); j++){
            area += doarea(edge[j].theta1, edge[j].theta2, cir[i]);
        }
    }
    if (zero(area)) area = 0;
    return onlypt;
}

int main()
{
    circle cir[101];
    int n;
    while (scanf("%d", &n) != EOF){
        for (int i = 0; i < n; i++){
            scanf("%lf%lf%lf", &cir[i].center.x, &cir[i].center.y, &cir[i].r);
        }
        double area = 0;
        point tp = cal_cir_inter_area(area, n, cir);
        if (zero(area)){
            if (zero(tp.x - offset)){
                printf("No common area\n");
            }else{
                printf("All circles intersect at point (%lf, %lf)\n", zero(tp.x)?0:tp.x, zero(tp.y)?0:tp.y);
            }
        }else{
            printf("%lf\n", area);
        }
    }
    return 0;
}









