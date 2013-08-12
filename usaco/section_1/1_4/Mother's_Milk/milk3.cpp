/*
ID: maemual
PROB: milk3
LANG: C++
*/
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
#define MAX_LEN 20
bool vis[MAX_LEN+5][MAX_LEN+5][MAX_LEN+5];
bool can[MAX_LEN+5];
struct node{
    int a, b, c;
}now, cur;
queue<node> que;
int main()
{
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    int A, B, C;
    memset(can, false, sizeof(can));
    scanf("%d%d%d", &A, &B, &C);
    now.a = now.b = 0;
    now.c = C;
    can[now.c] = true;
    que.push(now);
    vis[0][0][C] = true;
    while (!que.empty()){
        now = que.front();
        que.pop();
        //a->b
        if (now.a > 0 && now.b < B){
            cur.c = now.c;
            cur.b = (now.a + now.b >= B)?B:(now.a + now.b);
            cur.a = (now.a + now.b >= B)?(now.a - B + now.b):0;
            if (!vis[cur.a][cur.b][cur.c]){
                que.push(cur);
                if (cur.a == 0)
                    can[cur.c] = true;
                vis[cur.a][cur.b][cur.c] = true;
            }
        }
        //a->c
        if (now.a > 0 && now.c < C){
            cur.b = now.b;
            cur.c = (now.a + now.c >= C)?C:(now.a + now.c);
            cur.a = (now.a + now.c >= C)?(now.a - C + now.c):0;
            if (!vis[cur.a][cur.b][cur.c]){
                que.push(cur);
                if (cur.a == 0)
                    can[cur.c] = true;
                vis[cur.a][cur.b][cur.c] = true;
            }
        }
        //b->a
        if (now.b > 0 && now.a < A){
            cur.c = now.c;
            cur.a = (now.a + now.b >= A)?A:(now.a + now.b);
            cur.b = (now.a + now.b >= A)?(now.b - A + now.a):0;
            if (!vis[cur.a][cur.b][cur.c]){
                que.push(cur);
                if (cur.a == 0)
                    can[cur.c] = true;
                vis[cur.a][cur.b][cur.c] = true;
            }
        }
        //b->c
        if (now.b > 0 && now.c < C){
            cur.a = now.a;
            cur.c = (now.b + now.c >= C)?C:(now.b + now.c);
            cur.b = (now.b + now.c >= C)?(now.b - C + now.c):0;
            if (!vis[cur.a][cur.b][cur.c]){
                que.push(cur);
                if (cur.a == 0)
                    can[cur.c] = true;
                vis[cur.a][cur.b][cur.c] = true;
            }
        }
        //c->a
        if (now.c > 0 && now.a < A){
            cur.b = now.b;
            cur.a = (now.a + now.c >= A)?A:(now.a + now.c);
            cur.c = (now.a + now.c >= A)?(now.c - A + now.a):0;
            if (!vis[cur.a][cur.b][cur.c]){
                que.push(cur);
                if (cur.a == 0)
                    can[cur.c] = true;
                vis[cur.a][cur.b][cur.c] = true;
            }
        }
        //c->b
        if (now.c > 0 && now.b < B){
            cur.a = now.a;
            cur.b = (now.c + now.b >= B)?B:(now.c + now.b);
            cur.c = (now.c + now.b >= B)?(now.c - B + now.b):0;
            if (!vis[cur.a][cur.b][cur.c]){
                que.push(cur);
                if (cur.a == 0)
                    can[cur.c] = true;
                vis[cur.a][cur.b][cur.c] = true;
            }
        }
    }
    int k;
    for (k = 0; k <= 20; k++){
        if (can[k]){
            printf("%d", k);
            break;
        }
    }
    for (int i = k + 1; i <= 20; i++){
        if (can[i]){
            printf(" %d", i);
        }
    }
    printf("\n");
    return 0;
}
