#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_LEN = 100;
int gra[MAX_LEN][MAX_LEN];
bool visit[MAX_LEN];
int pre[MAX_LEN];
int path[MAX_LEN];
int n;
void dfs(int x)
{
	printf("%3d",x);
	for (int j=1;j<=n;j++)
	{
		if (gra[x][j] == 1 && visit[j] == false)
		{
			//pre[j] = x;
			//cout << x << endl;
			visit[j] = true;
			dfs(j);
			//visit[j] = false;
		}
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	  for (int j=1;j<=n;j++)
		scanf("%d",&gra[i][j]);
	memset(visit,0,sizeof(visit));
	//memset(path,0,sizeof(path));
	//memset(pre,0,sizeof(pre));
	for (int i=1;i<=n;i++)
	{
		if (visit[i] == false)
		{
			//pre[i] = -1;
			visit[i] = true;
			dfs(i);
			//visit[i] = false;
		}
	}
	//for (int i=1;i<=n;i++)
	//	printf("%3d",pre[i]);
	return 0;
}
