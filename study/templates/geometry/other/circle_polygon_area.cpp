#include<stdio.h>
#include<math.h>

const double PI = acos(-1.0);
double R;

template<class _T> _T sqr(const _T &a) {return a * a;}
template<class _T> _T abs(const _T &a) {return a>=0?a:-a;}
double dist2(double x, double y){return sqr(x)+sqr(y);}
double arcArea(double lx, double ly, double x, double y){
    double ang = abs(atan2(lx, ly)-atan2(x, y));
    if (ang > PI) ang = 2 * PI - ang;
    return R * R * ang / 2;
}

double addition(double lx, double ly, double x, double y){
    double area = 0;
    bool sign;
    if (x * ly - y * lx < 0)
        sign = false;
    else
        sign = true;
    if (dist2(x, y) > dist2(lx, ly)){
        double tx = x, ty = y;
        x = lx, y = ly;
        lx = tx, ly = ty;
    }
    double dx = lx - x, dy = ly - y;
    double a = sqr(dx) + sqr(dy), b = 2 * (x * dx + y * dy), c = sqr(x) + sqr(y) - sqr(R);
    double dt = b * b - 4 * a * c;
    if (dt <= 0)
        area += arcArea(lx, ly, x, y);
    else{
        dt = sqrt(dt);
        double k1 = (-b-dt) / (a * 2), k2 = (-b+dt) / (a * 2);
        if (k2 <= 0 || k1 >= 1)
            area += arcArea(lx, ly, x, y);
        else if (k1 <= 0 && k2 >= 1)
            area += abs(x * ly - y * lx) / 2;
        else if (k1 <= 0){
            double mx = x + dx * k2, my = y + dy * k2;
            area += abs(x * my - y * mx) / 2;
            area += arcArea(mx, my, lx, ly);
        }else{
            double x1 = x + dx * k1, y1 = y + dy * k1, x2 = x + dx * k2, y2 = y + dy * k2;
            area += arcArea(x, y, x1, y1);
            area += arcArea(x2, y2, lx, ly);
            area += abs(x1 * y2 - x2 * y1) / 2;
        }
    }
    if (!sign)
        return -area;
    else
        return area;
}

int main()
{
    const int N = 3;
    while (1){
        int i;
        double rx, ry, area = 0;
        double pos[3][2];
        for (i = 0; i < 3; i++){
            if (scanf("%lf%lf", &pos[i][0], &pos[i][1]) != 2)
                return 0;
        }
        scanf("%lf%lf%lf", &rx, &ry, &R);
        for (i = 1; i < N; i++)
            area += addition(pos[i-1][0]-rx, pos[i-1][1]-ry, pos[i][0]-rx, pos[i][1]-rx);
        area += addition(pos[N-1][0]-rx, pos[N-1][1]-ry, pos[0][0]-rx, pos[0][1]-ry);
        printf("%.2lf\n", abs(area));
    }
    return 0;
}
