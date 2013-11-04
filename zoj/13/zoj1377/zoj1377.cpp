#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

#define eps 1e-8

#define zero(x) (((x)>0?(x):(-x))<eps)
struct point{
    int x, y;
}points[1005];

struct line{
    point a, b;
    line() {}
    line(point _a, point _b): a(_a), b(_b) {}
};
point convex[1005];
int num;
int n;

int _sign(int a) {return a ? a > 0 ? 1 : -1 : 0;}

int xmult(const point &p1, const point &p2, const point &p0){
    return (p2.x-p0.x)*(p1.y-p0.y)-(p1.x-p0.x)*(p2.y-p0.y);
}
int dots_inline(const point p1, const point p2, const point p3){
    return zero(xmult(p1, p2, p3));
}
int cmp(const point &a, const point &b){
    return (a.y == b.y) ? (a .x < b.x ) : (a.y < b.y);
}
void graham(int n, point p[], point s[], int &top){
    sort(p, p + n, cmp);
    s[0] = p[0];
    s[1] = p[1];
    top = 1;
    for (int i = 2; i < n; i++){
        while (top > 0 && _sign(xmult(s[top-1], p[i], s[top])) < 0) --top;
        s[++top] = p[i];
    }
    int ltop = top;
    s[++top] = p[n-2];
    for (int i = n - 3; i >= 0; i--){
        while (top > ltop && _sign(xmult(s[top-1], p[i], s[top])) < 0) --top;
        s[++top] = p[i];
    }
}
bool check(){
    if (num == 2)
        return false;
    for (int i = 1; i <= num; i++){
        int cnt = 0;
        for (int j = 0; j < n; j++){
            if (dots_inline(points[j], convex[i], convex[i-1]))
                cnt++;
        }
        if (cnt < 3)
            return false;
    }
    return true;
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d %d", &points[i].x, &points[i].y);
        }
        if (n < 6){
            printf("NO\n");
            continue;
        }
        graham(n, points, convex, num);
        if (check())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
