#include <cstdio>
#include <cstring>
const int MAX_LEN = 100;
int map[MAX_LEN+5];
int main()
{
	int n,q;
	while (scanf("%d%d",&n,&q) != EOF)
	{
		if (n==0 && q==0)
		  break;
		memset(map,0,sizeof(map));
		for (int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			for (int j=0;j<x;j++)
			{
				int t;
				scanf("%d",&t);
				map[t]++;
			}
		}
		int max = -1;
		int maxId = 0;
		for (int i=0;i<MAX_LEN;i++)
		{
			if (map[i]>=q && map[i]>max)
			{
				max = map[i];
				maxId = i;
			}
		}
		printf("%d\n",maxId);
	}
	return 0;
}
