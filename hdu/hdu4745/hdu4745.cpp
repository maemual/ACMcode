#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX_LEN 1005
int dp[MAX_LEN][MAX_LEN];
int arr[MAX_LEN];
int main()
{
    int n;
    while (1){
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = n-1; i >= 0; i--){
            for (int j = i + 1; j < n; j++){
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                if (arr[i] == arr[j])
                    dp[i][j] = max(dp[i][j], dp[i+1][j-1]+2);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, dp[0][i] + dp[i+1][n-1]);
        printf("%d\n", ans);
    }
    return 0;
}
