#include<iostream>        //dfs
#include <cstring>
using namespace std;
int r,c,mr,mc,num,ans[25][25],vis[25][25];
int pos[4][2]={{-1,0},{0,1},{1,0},{0,-1}},slo[4][2]={{-1,1},{1,1},{1,-1},{-1,-1}};
void dfs(int x,int y)
{
    vis[x][y]=1;
    int px,py;
    for(int i=0;i<4;++i)
    {
        px=x+pos[i][0];py=y+pos[i][1];
        if(ans[px][py]==0)
            num++;
        if(px>0&&px<=r&&py>0&&py<=c&&ans[px][py]&&!vis[px][py])
        {
            dfs(px,py);
        }
        px=x+slo[i][0];py=y+slo[i][1];
        if(px>0&&px<=r&&py>0&&py<=c&&ans[px][py]&&!vis[px][py])
        {
            dfs(px,py);
        }        
    }
}
int main()
{
    char ch;
    while(cin>>r>>c>>mr>>mc&&r)
    {
        memset(ans,0,sizeof(ans));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=r;++i)
            for(int j=1;j<=c;++j)
            {
                cin>>ch;
                if(ch=='X')
                    ans[i][j]=1;
            }
        num=0;
        dfs(mr,mc);
        cout<<num<<endl;
    }
    return 0;
}
