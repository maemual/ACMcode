#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;

#define MAX_LEN 100005
typedef long long ll;

int left[MAX_LEN], right[MAX_LEN];
int vis[MAX_LEN];
int main()
{
    int n, m, x;
    while (scanf("%d %d", &n, &m) != EOF){
        ll sum = 0;
        int num;
        memset(vis, 0, sizeof(vis));
        memset(left, 0, sizeof(left));
        for (int i = 1; i <= n; i++){
            scanf("%d", &x);
            sum += x;
            num = (sum % m + m) % m;
            if (left[num] == 0){
                left[num] = i;
            }
            /*
            if (!vis[num]){
                vis[num] = 1;
                left[num] = i;
            }
            */
            right[num] = i;
        }
        int mmax = 0;
        for (int i = 0; i < m; i++){
            if (left[i])
            //if (vis[i])
                mmax = max(mmax, right[i] - left[i]);
        }
        printf("%d\n", mmax);
    }
    return 0;
}
