#include <cstdio>
#include <set>

using namespace std;

const int maxn = 500000 + 10;
const long long INF = (1LL<<60);
int n, x[maxn], y[maxn];

struct Point{
    int x;
    int y;
    bool operator < (const Point& e) const{
        return x < e.x;
    }
};

void read(int *a){
    int A, B, C, i;
    a[0] = 0;
    scanf("%d%d%d", &A, &B, &C);
    for(i = 1; i <= n; i++){
        a[i] = ((long long)a[i-1] * A + B) % C;
    }
}

long long solve(){
    int i;
    long long Min = INF, ret = 0;
    multiset<Point> se;
    se.clear();
    Point v;
    v.x = x[1];
    v.y = y[1];
    se.insert(v);
    for(i = 2; i <= n; i++){
        v.x = x[i];
        v.y = y[i];
        multiset<Point>::iterator p = se.lower_bound(v), iter;
        for(iter = p; iter != se.end(); iter++){        //从p开始，一直到se.end()前一个位置
            long long dx = v.x - iter->x;
            dx *= dx;
            if(dx >= Min) break;        //剪枝
            long long dy = v.y - iter->y;
            dy *= dy;
            Min = min(Min, dx + dy);
        }
        for(iter = p; iter != se.begin();){     //从p的上一个位置开始，一直算完se.begin()
            iter--;
            long long dx = v.x - iter->x;
            dx *= dx;
            if(dx >= Min) break;        //剪枝
            long long dy = v.y - iter->y;
            dy *= dy;
            Min = min(Min, dx + dy);
        }
        ret += Min;
        se.insert(v);
    }
    return ret;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        read(x);
        read(y);
        printf("%lld\n", solve());
    }
    return 0;
}

