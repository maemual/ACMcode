/*
ID: maemual
PROB: numtri
LANG: C++
*/

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define MAX_LEN 1000

int tri[MAX_LEN+5][MAX_LEN+5];
int main()
{
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    int r;
    scanf("%d", &r);
    memset(tri, 0, sizeof(tri));
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= i; j++){
            scanf("%d", &tri[i][j]);
        }
    }
    for (int i = 2; i <= r; i++){
        for (int j = 1; j <= i; j++){
            tri[i][j] += max(tri[i-1][j-1], tri[i-1][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= r; i++){
        ans = max(ans, tri[r][i]);
    }
    printf("%d\n", ans);
    return 0;
}
