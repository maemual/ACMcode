#include<cstdio>
#include<string.h>
#include<vector>

using namespace std;

struct node{
    vector<int> next;
}nodes[100005];
bool flag[100005];
int n, D;
void dfs(int k, int f){
    if (k >= D) return ;
    for (int i = 0; i < nodes[f].next.size(); i++){
        if (flag[nodes[f].next[i]]) continue;
        flag[nodes[f].next[i]] = true;
        dfs(k + 1, nodes[f].next[i]);
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &n, &D);
        int u, v;
        for (int i = 0; i < n; i++){
            nodes[i].next.clear();
        }
        for (int i = 0; i < n - 1; i++){
            scanf("%d %d", &u, &v);
            nodes[u].next.push_back(v);
            nodes[v].next.push_back(u);
        }
        memset(flag, false, sizeof(flag));
        flag[0] = true;
        dfs(0, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (flag[i] == false)
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
