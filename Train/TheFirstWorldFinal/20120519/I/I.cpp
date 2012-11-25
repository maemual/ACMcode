#include <iostream>
#include <stdio.h>
using namespace std;
int count = 0;
int n,k;
int a[105][105];
int vis[105][105];
int m = -1;
void dfs(int row,int line,int step){
    for (int i=1;i<=k;i++)
    {
        count += a[row][line];
        if (m < count)
            m = count;
        if (row-i>=0 && vis[row-i][line] == 0 && a[row-i][line]>a[row][line]){
            vis[row][line] = 1;
            if (step+1 <= n*n)
                dfs(row-i,line,step+1);
            vis[row][line] = 0;
        }
        count -= a[row][line];
    }
    for (int i=1;i<=k;i++)
    {
        count += a[row][line];
        if (m < count)
            m = count;
        if (line+i<=n-1 && vis[row][line+i]==0 && a[row][line+i]>a[row][line]){
            vis[row][line] = 1;
            if (step+1 <= n*n)
                dfs(row,line+i,step+1);
            vis[row][line] = 0;
        }
        count -= a[row][line];
    }
    for (int i=1;i<=k;i++)
    {
        count += a[row][line];
        if (m < count)
            m = count;
        if (row+i<=n-1 && vis[row+i][line]==0 && a[row+i][line] > a[row][line]){
            vis[row][line] = 1;
            if (step+1 <= n*n)
                dfs(row+i,line,step+1);
            vis[row][line] = 0;
        }
        count -= a[row][line];
    }
    for (int i=1;i<=k;i++)
    {
        count += a[row][line];
        if (m < count)
            m = count;
        if (line-i>=0 && vis[row][line-i]==0 && a[row][line-i]>a[row][line]){
            vis[row][line] = 1;
            if (step+1 <= n*n)
                dfs(row,line-i,step+1);
            vis[row][line] = 0;
        }
        count -= a[row][line];
    }
}
int main()
{
    while (1)
    {
        scanf("%d%d",&n,&k);
        if (n == -1 && k == -1)
            break;

        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j){
                scanf("%d",&a[i][j]);
                vis[i][j] = 0;
            }

        dfs(0,0,1);
        printf("%d\n",m);
    }
    return 0;
}
