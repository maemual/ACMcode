#include <cstdio>
#include <cstring>
const int MAX_LEN = 1005;
bool arr[MAX_LEN];
int main()
{
	int n,m,k;
	int cas = 0;
	while (scanf("%d%d%d",&n,&m,&k) != EOF)
	{
		memset(arr,0,sizeof(arr));
		int p=0,q;
		int cnt = 1;
		int ans;
		int mt = m;
		while (1)
		{
			q = 0;
			mt = m % (n-cnt+1);
			if (mt == 0)
				mt = n-cnt+1;
			while (q != mt)
			{
				p++;	
				if (p > n)
					p = 1;
				if (!arr[p])
					q++;
			}
			if (p == k)
			{
				ans = cnt;
				break;
			}
			arr[p] = true;
			cnt++;
		}
		printf("Case %d: %d\n",++cas,ans);
	}
	return 0;
}
