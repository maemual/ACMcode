#include <cstdio>
#include <climits>
#include <queue>
#include <time.h>
using namespace std;
int map[15][15];
int vis[15][15];
int dx[]={-2,-2,-1,1,2, 2, 1,-1,};
int dy[]={-1, 1, 2,2,1,-1,-2,-2,};
int ddx[]={-1,0,1, 0};
int ddy[]={ 0,1,0,-1};
int sum,len;
int xsta,ysta,xend,yend;
struct node
{
	int x,y,k;
};
void dfs(int x,int y,int k)
{
	if (k > len)
	  return;
	/*if (x == xend && y == yend && k <= vis[xend][yend])
	{
		//printf("OK\n");
		if (vis[xend][yend] == INT_MAX)
		{
			vis[xend][yend] = k;
			sum++;
		}else if (k == len)
		  sum++;
		else if (k < vis[xend][yend])
		{
			sum=1;
			vis[xend][yend] = k;
		}else 
			sum++;
		return;
	}*/
	if (x == xend && y == yend)
	{
		sum++;
		return;
	}
	vis[x][y] = k;
	for (int i=0;i<8;i++)
	{
		if (map[x+dx[i]][y+dy[i]] !=1 && map[x+ddx[i/2]][y+ddy[i/2]]==0)
		{
			if (vis[x+dx[i]][y+dy[i]] >= k+1)
			{
				dfs(x+dx[i],y+dy[i],k+1);
			}
		}
	}
}
int main()
{

	long long start = clock();
	int cas;
	//freopen("in.txt","r",stdin);
	//freopen("outs.txt","w",stdout);
	scanf("%d",&cas);
	while (cas--)
	{
		for (int i=0;i<15;i++)
		{
			for (int j=0;j<15;j++)
			{
				map[i][j] = 1;
				vis[i][j] = INT_MAX;
			}
		}
		//getchar();
		char ch;
		xsta=-1,xend=-1,ysta=-1,yend=-1;
		char st[13];
		for (int i=2;i<10;i++)
		{
			scanf("%s",st);
			for (int j=0;j<8;j++)
			{
				if (st[j] == '*')
				{
					map[i][j+2] = 1;
				}else if (st[j] == '#')
				{
					map[i][j+2] = 0;
				}else if (st[j] == 'T')
				{
					xend = i;
					yend = j+2;
					map[i][j+2] = 0;
				}else if (st[j] == 'S')
				{
					xsta = i;
					ysta = j+2;
					map[i][j+2] = 0;
				}
			}
			getchar();
		}
		//for (int i=2;i<10;i++)
		//{
		//	for (int j=2;j<10;j++)
		//	{
		//		printf("%2d",map[i][j]);
		//	}
		//	printf("\n");
		//}
		//printf("Begin: %d %d\n",xsta,ysta);
		//printf("End: %d %d\n",xend,yend);
		if (xsta==-1||xend==-1||ysta==-1||yend==-1)
		{
			printf("No way!\n");
			continue;
		}
		sum = 0;
		len = -1;
		queue<node> q;
		node ss;
		ss.x = xsta;
		ss.y = ysta;
		ss.k = 0;
		q.push(ss);
		bool flag = false;
		while (q.back().x != xend || q.back().y != yend)
		{
			node nn = q.front();
			for (int i=0;i<8;i++)
			{
				if (map[nn.x+dx[i]][nn.y+dy[i]] !=1 && map[nn.x+ddx[i/2]][nn.y+ddy[i/2]]==0)
				{
					if (vis[nn.x+dx[i]][nn.y+dy[i]] > nn.k+1)
					{
						node newnode;
						newnode.x = nn.x+dx[i];
						newnode.y = nn.y+dy[i];
						newnode.k = nn.k+1;
						vis[newnode.x][newnode.y] = nn.k+1;
						q.push(newnode);
						if (q.back().x == xend && q.back().y == yend)
						{
							flag = true;
							len = q.back().k;
							break;
						}
						//dfs(nn.x+dx[i],nn.y+dy[i],k+1);
					}
				}
			}
			if (flag)
			  break;
			q.pop();
		}
		if (len == -1)
		{
			printf("No way!\n");
			continue;
		}

		dfs(xsta,ysta,0);
		//for (int i=2;i<10;i++)
		//{
		//	for (int j=2;j<10;j++)
		//	  printf("%12d",vis[i][j]);
		//	printf("\n");
		//}
		if (sum == 0)
		{
			printf("No way!\n");
		}else 
			printf("%d %d\n",len,sum);
	}
	long long end = clock();
	printf("%lld\n",end-start);
	return 0;
}
