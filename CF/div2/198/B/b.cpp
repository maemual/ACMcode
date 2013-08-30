#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<cstdio>
using namespace std;

#define eps 1e-10
#define delt(a) fabs(a)<eps?0:a>0?1:-1
struct point{
    int x, y;
}p[305], po[4], st;
int gcd(int a, int b){
    return !b?a:gcd(b, a % b);
}
double xmult(const point &p1, const point &p2, const point &p0){
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double dist(const point &p1, const point &p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
bool cmp1(const point &p1, const point &p2){
    if (p1.y < p2.y)
        return true;
    else if (p1.y == p2.y && p1.x < p2.x)
        return true;
    return false;
}
bool cmp2(const point &p1, const point &p2){
    if (p1.x < p2.x)
        return true;
    else if (p1.x == p2.x && p1.y < p2.y)
        return true;
    return false;
}
bool ncmp(const point &p1, const point &p2){
    int d1 = delt(xmult(p1, p2, st));
    return d1 > 0 || (d1 == 0 && dist(st, p1) < dist(st, p2));
}
double area_polygon(){
    double s1 = 0.0, s2 = 0.0;
    for (int i = 0; i < 4; i++){
        s1 += po[(i + 1)%4].y * po[i].x;
        s2 += po[(i + 1)%4].y * po[(i + 2)%4].x;
    }
    return fabs(s1 - s2) / 2.0;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
    double mmax = -1;
    sort(p, p + n, cmp1);
    po[0] = st = p[0];
    for (int i = 1; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                po[1].x = p[i].x;po[1].y = p[i].y;
                po[2].x = p[j].x;po[2].y = p[j].y;
                po[3].x = p[k].x;po[3].y = p[k].y;
                sort(po, po + 4, ncmp);
                double s = area_polygon();
               if (s > mmax)
                   mmax = s;
                po[0] = st;
            }
        }
    }
    sort(p, p + n, cmp2);
    po[0] = st = p[0];
    for (int i = 1; i < n; i++){
        for (int j = i + 1; j < n; j++){
            for (int k = j + 1; k < n; k++){
                po[1].x = p[i].x;po[1].y = p[i].y;
                po[2].x = p[j].x;po[2].y = p[j].y;
                po[3].x = p[k].x;po[3].y = p[k].y;
                sort(po, po + 4, ncmp);
                double s = area_polygon();
               if (s > mmax)
                   mmax = s;
                po[0] = st;
            }
        }
    }
    printf("%.9lf\n", mmax);
    return 0;
}
