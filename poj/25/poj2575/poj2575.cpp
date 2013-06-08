#include <cstdio>
#include <cstdlib>
#include <string.h>
int main()
{
	int n;
	int a[3005];
	int b[3005];
	while (scanf("%d",&n) != EOF)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for (int i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		for (int i=0;i<n-1;i++)
		{
			a[abs(b[i]-b[i+1])] = 1;
		}
		bool flag = true;
		for (int i=1;i<n;i++)
		{
			if (a[i] == 0)
			{
				printf("Not jolly\n");
				flag = false;
				break;
			}
		}
		if (flag)
			printf("Jolly\n");
	}
	return 0;
}
