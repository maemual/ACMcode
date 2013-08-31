#include<cstdio>
#include<iostream>
using namespace std;

#define eps 1e-7
#define MAX_LEN 55
int n, m;
struct point{
    double x, y;
}p1[MAX_LEN], p2[MAX_LEN];

inline double dist(const point &p1, const point &p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
int nearest(const point &p){
    int k = 0;
    double mmin = 999999999;
    for (int i = 0; i < m; i++){
        double d = dist(p, p2[i]);
        if (d < mmin){
            mmin = d;
            k = i;
        }
    }
    return k;
}
int solve(const point &a, const point &b){
    int k1 = nearest(a);
    int k2 = nearest(b);
    if (k1 == k2) return 0;
    if (dist(a, b) < eps) return 1;
    point pt;
    pt.x = (a.x + b.x) / 2;
    pt.y = (a.y + b.y) / 2;
    return solve(a, pt) + solve(pt, b);
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF){
        for (int i = 0; i < n; i++)
            scanf("%lf %lf", &p1[i].x, &p1[i].y);
        for (int i = 0; i < m; i++)
            scanf("%lf %lf", &p2[i].x, &p2[i].y);
        int k;
        scanf("%d", &k);
        int u, v;
        while (k--){
            scanf("%d %d", &u, &v);
            u--;v--;
            printf("%d\n", solve(p1[u], p1[v]));
        }
    }
    return 0;
}
