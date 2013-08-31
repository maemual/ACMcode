#include<cstdio>
#include<algorithm>
using namespace std;

#define eps 1e-10
struct point{
    int x, y;
}p[305];
inline double xmult(const point &p1, const point &p2, const point &p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i].x, &p[i].y);
    double maxarea = -1;
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            double mmax1 = -1, mmax2 = -1;
            for (int k = 0; k < n; k++){
                if (k == i || k == j) continue;
                if (xmult(p[i], p[j], p[k]) < 0)
                    mmax1 = max(mmax1, -xmult(p[i], p[j], p[k]));
                else if (xmult(p[i], p[j], p[k]) > 0)
                    mmax2 = max(mmax2, xmult(p[i], p[j], p[k]));
            }
            if (mmax1 + mmax2 > maxarea)
                maxarea = mmax1 + mmax2;
        }
    }
    printf("%lf\n", maxarea * 0.5);
    return 0;
}
