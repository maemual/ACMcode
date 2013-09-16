#include<cstdio>
using namespace std;

#define MAX_LEN 100005
typedef long long llg;
llg arr[MAX_LEN];
int main()
{
    int T;
    int n, m;
    scanf("%d", &T);
    for (int k = 1; k <= T; k++){
       scanf("%d%d", &n, &m);
       for (int i = 0; i < n; i++)
           scanf("%lld", &arr[i]);
       llg ans = 0;
       for (int i = 0; i < n; i++){
           llg tmp = arr[i];
           if (tmp >= m) continue;
           ans++;
           int j;
           for (j = i + 1; j < n; j++){
               tmp |= arr[j];
               if (tmp >= m) break;
               ans++;
           }
           //ans += j - i - 1;
       }
       printf("Case #%d: %lld\n", k, ans);
    }
    return 0;
}
