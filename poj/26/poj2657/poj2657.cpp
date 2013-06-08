#include <cstdio>
#include <cstring>
const int MAX_LEN = 1000;
bool a[MAX_LEN+5];
int main()
{
	int n,z,m;
	scanf("%d%d%d",&n,&z,&m);
	if (m == 0)
	{
		printf("%d\n",1);
		return 0;
	}
	memset(a,0,sizeof(a));
	int x;
	for (int i=0;i<m;i++)
	{
		scanf("%d",&x);
		a[x] = true;
	}
	int step = 0;
	bool flag;
	for (int i=1;i<=n;i++)
	{
		flag = false;
		int j = 1;
		while (j != z)
		{
			j += i;
			if (j>n)
			{ 
				j -= n;
				if (j == 1)
				{	
					flag = true;
					break;
				}
			}
			if (a[j])
			  break;
		}
		if (flag)
		  continue;
		if (j == z)
		{
			step = i;
			break;
		}
	}
	printf("%d\n",step);
	return 0;
}
