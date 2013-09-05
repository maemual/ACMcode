#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

const double eps = 1e-12;
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
    circle(point p, double _r):center(p), r(_r) {}
};
struct arc{
    double theta1, theta2;
    arc() {}
    arc(double t1, double t2):theta1(t1), theta2(t2) {}
    bool operator < (const arc& a) const {
        return theta1 < a.theta1 - eps || theta1 <= a.theta1 + eps
            && theta2 < a.theta2 - eps;
    }
};

inline double sqr(double x) {return x * x;}
vector<arc> edge;
void interline(const circle& c1, const circle& c2){
    complex<double> v(c2.center.x - c1.center.x, c2.center.y - c1.center.y);
    double d = abs(v);
    double a = ((sqr(c1.r)-sqr(c2.r)) / d + d) / 2;
    double dtheta = acos(a / c1.r), alpha = arg(v);
    double theta1 = alpha - dtheta, theta2 = alpha + dtheta;
    if (theta1 < -eps) theta1 += PI * 2;
    if (theta2 < -eps) theta2 += PI * 2;
    if (theta1 > theta2 + eps){
        edge.push_back(arc(theta1, PI * 2));
        edge.push_back(arc(0, theta2));
    }
    else
        edge.push_back(arc(theta1, theta2));
}

bool nointer(const circle& c1, const circle& c2){
    return sqrt(sqr(c1.center.x-c2.center.x)+sqr(c1.center.y-c1.center.y)) >= c1.r + c2.r - eps
        || sqrt(sqr(c1.center.x-c2.center.x)+sqr(c1.center.y-c1.center.y)) <= fabs(c2.r-c1.r) + eps;
}

bool inner(const circle& c1, const circle& c2){
    return sqrt(sqr(c1.center.x-c2.center.x)+sqr(c1.center.y-c2.center.y)) < c2.r - c1.r - eps;
}
double doarea(double a1, double a2, circle& c){
    return sqr(c.r) / 2 * (a2-a1) + c.r / 2 * (c.center.x * sin(a2) - c.center.y*cos(a2)
            - c.center.x*sin(a1) + c.center.y*cos(a1));
}
bool same(const circle& c1, const circle& c2){
    return fabs(c1.center.x-c2.center.x) <= eps
        && fabs(c1.center.y-c2.center.y) <= eps
        && fabs(c1.r-c2.r) <= eps;
}
double area(int n, circle c[]){
    double ret = 0;
    for (int i = 0; i < n; i++){
        bool neglect = false;
        edge.clear();
        for (int j = 0; j < n; j++){
            if (i != j){
                if (same(c[i], c[j]) && i > j || !same(c[i], c[j]) && inner(c[i], c[j])){
                    neglect = true;
                    break;
                }
                if (nointer(c[i], c[j])) continue;
                interline(c[i], c[j]);
            }
        }
        if (!neglect){
            sort(edge.begin(), edge.end());
            double pre = 0;
            for (int j = 0; j < (int)edge.size(); j++){
                if (edge[j].theta1 <= pre + eps){
                    if (edge[j].theta2 > pre + eps)
                        pre = edge[j].theta2;
                }else{
                    ret += doarea(pre, edge[j].theta1, c[i]);
                    pre = edge[j].theta2;
                }
            }
            if (PI * 2 > pre + eps)
                ret += doarea(pre, PI*2, c[i]);
        }
    }
    return ret;
}

int main()
{
    int n;
    circle c[105];
    while (1){
        cin >> n;
        if (!n) break;
        for (int i = 0; i < n; i++)
            cin >> c[i].center.x >> c[i].center.y >> c[i].r;
        cout << area(n, c) << endl;
    }
    return 0;
}
