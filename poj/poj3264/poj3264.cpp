#include <cstdio>
#include <string.h>
#include <climits>

#define min(a,b) ((a)>(b))?(b):(a)
#define max(a,b) ((a)>(b))?(a):(b)

const int MAX_LEN = 50000;
struct Tnode{
	int min,max,l,r;
};
Tnode node[MAX_LEN*4];
int v[MAX_LEN];
int mmin,mmax;
void Build(int t,int left,int right)
{
	node[t].l = left;
	node[t].r = right;
	if (left == right-1)
	{
		node[t].min = node[t].max = v[left];
		return;
	}
	int mid = (left+right) / 2;
	Build(t*2,left,mid);
	Build(t*2+1,mid,right);
	node[t].max = max(node[t*2].max,node[t*2+1].max);
	node[t].min = min(node[t*2].min,node[t*2+1].min);
}
void Query(int t,int left,int right)
{
	if (node[t].l == left && node[t].r == right)
	{
		mmax = max(node[t].max,mmax);
		mmin = min(node[t].min,mmin);
		return ;
	}
	int mid = (node[t].l+node[t].r) /2;
	if (left >= mid)
		Query(t*2+1,left,right);
	else 
		if (right <= mid)
			Query(t*2,left,right);
		else
		{
			Query(t*2+1,mid,right);
			Query(t*2,left,mid);
		}
}
int main()
{
	int n,m;
	int x,y;
	while (scanf("%d%d",&n,&m) != EOF)
	{
		memset(node,0,sizeof(node));
		for (int i=0;i<n;i++)
		  scanf("%d",&v[i]);
		Build(1,0,n);
		while (m--)
		{
			scanf("%d%d",&x,&y);
			mmin = INT_MAX;
			mmax = INT_MIN;
			Query(1,x-1,y);
			printf("%d\n",mmax-mmin);
		}
	}
	return 0;
}
