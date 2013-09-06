#include<cstdio>
#include<cstdlib>

struct point{
    int x, y;
};

int gcd(int a, int b){
    return b?gcd(b, a%b):a;
}

//多边形边上格点数目
int grid_onedge(int n, point p[]){
    int ret = 0;
    for (int i = 0; i < n; i++)
        ret += gcd(abs(p[i].x-p[(i+1)%n].x), abs(p[i].y-p[(i+1)%n].y));
    return ret;
}

//多边形内格点数目
int grid_inside(int n, point p[]){
    int ret = 0;
    for (int i = 0; i < n; i++){
        ret += p[(i+1)%n].y * (p[i].x-p[(i+2)%n].x);
    }
    return (abs(ret)-grid_onedge(n, p)) / 2 + 1;
}

int main()
{
    point p[5];
    while (1){
        scanf("%d%d%d%d%d%d", &p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y);
        if (p[0].x == 0 && p[0].y == 0 && p[1].x == 0 && p[1].y == 0 && p[2].x == 0 && p[2].y == 0)
            break;
        int onedge = grid_onedge(3, p);
        int inside = grid_inside(3, p);
        //double area = inside + onedge / 2.0 - 1;
        printf("%d\n", inside);
    }
    return 0;
}
