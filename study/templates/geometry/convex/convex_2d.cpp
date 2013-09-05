#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define MXN 30050
#define eps 1e-8
struct point {
    double x,y;
};

int _sign(double a) {return fabs(a)<eps? 0: (a>0)? 1: -1;}
int _sign(int a) {return a? a>0? 1 : -1 : 0;}

int xmult(const point &p1,const point p2,const point p0) {
    return (p2.x-p0.x)*(p1.y-p0.y)-(p1.x-p0.x)*(p2.y-p0.y);
}

int cmp(const point &a,const point &b) {
    return (a.y==b.y)?(a.x<b.x):(a.y<b.y);
}

void graham(int n, point p[], point s[], int &top) {
    sort(p, p + n, cmp);
    s[0] = p[0];
    s[1] = p[1];
    top = 1;
    for (int i = 2; i < n; i++) {
        while (top > 0 && _sign(xmult(s[top-1],p[i],s[top])) < 0) --top;
        s[++top]=p[i];
    }
    int ltop=top;
    s[++top] = p[n-2];
    for (int i = n-3; i >= 0; i--) {
        while (top > ltop && _sign(xmult(s[top-1],p[i],s[top])) < 0) --top;
        s[++top]=p[i];
    }
}

int main() {
    point p[MXN], s[MXN];
    int n;
    int top;
    scanf("%d",&n);
    for (int i=0;i<n;++i) {
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    graham(n, p, s, top);
    for (int i=0;i<=top;++i) {
        printf("(%.2lf,%.2lf)\n",s[i].x,s[i].y);
    }
    return 0;
}
