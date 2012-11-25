#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_LEN = 200000;

int rank[MAX_LEN+5];
int v[MAX_LEN+5];
int find_set(int x)
{
	if (v[x] != x)
		v[x] = find_set(v[x]);
	return v[x];
}
void Union(int x,int y)
{
	if (rank[x] > rank[y])
		v[y] = x;
	else if (rank[x] < rank[y])
		v[x] = y;
	else if (rank[x] == rank[y])
	{
		v[x] = y;
		rank[y]++;
	}
}
struct Edge
{
	int x,y,w;
}e[MAX_LEN+5];
bool cmp(const Edge &e1,const Edge &e2)
{
	if (e1.w<e2.w)
		return true;
	else 
		return false;
}
int main()
{
	int n,m,s1,s2;
	long long ans,sum;
	while (1)
	{
		memset(e,0,sizeof(e));
		memset(rank,0,sizeof(rank));
		memset(v,0,sizeof(v));
		sum = 0;
		scanf("%d%d",&n,&m);
		if (n == 0 && m == 0)
			break;
		for (int i=0;i<m;i++)
		{
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
			sum += e[i].w;
		}
		sort(e,e+m,cmp);

		for (int i=1;i<=n;i++)
			v[i] = i;
		ans = 0;
		for (int i=0;i<m;i++)
		{
			s1=find_set(e[i].x);
			s2=find_set(e[i].y);
			if (s1 != s2)
			{
				ans += e[i].w;
				Union(s1,s2);
			}
		}
		printf("%lld\n",sum - ans);
	}
}
