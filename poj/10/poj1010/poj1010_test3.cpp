#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAX_LEN = 10;
const int MAX_SIZE = 100;
int stamps[MAX_SIZE+5];
int request[MAX_SIZE+5];
int result[MAX_LEN+5];
int ans[MAX_LEN+5];
int hash[MAX_SIZE+5];
int need,n,m,k;
bool Tie;
void init()
{
	memset(stamps,0,sizeof(stamps));
	memset(request,0,sizeof(request));
	memset(result,0,sizeof(result));
	memset(ans,0,sizeof(ans));
	memset(hash,0,sizeof(hash));
	n=m=0;
}
void refresh()
{
	if ((result[0] > ans[0])
		|| (result[0]==ans[0] && result[1]<ans[1])
		|| (result[0]==ans[0] && result[1]==ans[1] && result[2]>ans[2])
		|| (result[0]==ans[0] && result[1]==ans[1] && result[2]==ans[2]))
		for (int i=0;i<k;i++)
		  ans[i] = result[i];
}
void dfs(int p,int val)
{
	if (result[1]>4)
	  return;
	if (val==need)
	  refresh();
}
void print()
{
	printf("%d ",need);
	if (Tie)
	  printf("(%d): tie\n",ans[0]);
	else if (ans[0] == 0)
	  printf("---- none\n");
	else {
		printf("(%d):",ans[0]);
		for (int i=3;i<k;i++)
		  for (int j=0;j<ans[i];j++)
			printf(" %d",stamps[i-3]);
		printf("\n");
	}
}
void work(int i)
{
	need = request[i];
	memset(result,0,sizeof(result));
	memset(ans,0,sizeof(ans));
	Tie = false;
	k = 3;
	dfs(n-1,0);
	print();
}
int main()
{
	int x;
	while (scanf("%d",&x) != EOF)
	{
		init();
		while (x!=0)
		{
			hash[x]++;
			if (hash[x] < 5)
			  stamps[n++] = x;
			scanf("%d",&x);
		}
		scanf("%d",&x);
		while (x != 0)
		{
			request[m++] = x;
			scanf("%d",&x);
		}
		sort(stamps,stamps+n);
		
		for (int i=0;i<n;i++)
		  work(i);
	}
	return 0;
}
