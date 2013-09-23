#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX_LEN 105
struct node{
    int x, y;
    bool operator < (const node &a) const {
        return x < a.x || (x == a.x) && (y < a.y);
    }
}p[MAX_LEN];
bool vis[MAX_LEN];
int n;
int s;
void dfs(int ans){
    if (ans > s) s = ans;
    for (int i = 0; i < n; i++){
        if (vis[i]) continue;
        for (int j = i + 1; j < n; j++){
            if (vis[j]) continue;
            if (p[i].x == p[j].x || p[i].y == p[j].y) continue;
            if (p[i].x - p[j].x != p[i].y - p[j].y) continue;

            int t1 = -1, t2 = -1;
            int tx = p[i].x, ty = p[j].y;
            for (int k = 0; k < n; k++){
                if (!vis[k] && k != i && k != j && p[k].x == tx && p[k].y == ty){
                    t1 = k;
                    break;
                }
            }
            if (t1 == -1) continue;
            tx = p[j].x, ty = p[i].y;
            for (int k = 0; k < n; k++){
                if (!vis[k] && k != i && k != j && p[k].x == tx && p[k].y == ty){
                    t2 = k;
                    break;
                }
            }
            if (t2 == -1) continue;
            vis[i] = vis[j] = vis[t1] = vis[t2] = true;
            dfs(ans+1);
            vis[i] = vis[j] = vis[t1] = vis[t2] = false;
        }
    }
}
int main()
{
    while (1){
        scanf("%d", &n);
        if (n == -1)
            break;
        for (int i = 0; i < n; i++)
            scanf("%d %d", &p[i].x, &p[i].y);
        if (n < 4){
            printf("0\n");
            continue;
        }
        memset(vis, false, sizeof(vis));
        s = 0;
        sort(p, p + n);
        dfs(0);
        printf("%d\n", 4 * s);
    }
    return 0;
}
