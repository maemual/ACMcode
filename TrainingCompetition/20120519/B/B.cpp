#include <iostream>
using namespace std;
int a[20][20];
int vis[20];
int mk[20];
long long count=0;
void dfs(int n,int x){
    if (x == n)
    {
        count++;
        return;
    }else {
        for (int i=1;i<=n;i++)
        {
            if (vis[i] == 0){
                bool pan = true;
                for (int k=0;k<x;k++){
                    if (a[i][mk[k]] == 1)
                    {
                        pan = false;
                        break;
                    }
                }
                if (pan)
                {
                    mk[x]=i;
                    vis[i] = 1;
                    dfs(n,x+1);
                    vis[i] = 0;
                    mk[x]=0;
                }else continue;
            }
        }
    }
}
bool check(int n){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i != j && a[i][j]==1 && a[j][i] == 1)
                return false;
    return true;
}
bool totalZero(int n){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (a[i][j]!=0)
                return false;
    return true;
}
int main()
{
    int n;
    while(cin >> n)
    {
        for (int i=0;i<20;i++)
            for (int j=0;j<20;j++)
                a[i][j] = 0;

        for (int i=0;i<20;i++){
            vis[i]=0;
            mk[i] = 0;
        }

        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                cin >> a[i][j];

        if (check(n)){
            if (totalZero(n))
            {
                count = 1;
                for (int i=1;i<=n;i++)
                    count*=i;
            }else{
                count=0;
                dfs(n,0);
            }
            cout << count%10007 <<endl;
        }else cout << 0 << endl;
    }
    return 0;
}
