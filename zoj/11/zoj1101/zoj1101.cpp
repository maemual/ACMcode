/*
 * Time:400MS
 */
#include <cstdio>
#include <algorithm>
const int MAX_LEN = 1000;
int a[MAX_LEN+5];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	while (1)
	{
		scanf("%d",&n);
		if (n==0)
		  break;
		for (int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		std::sort(a,a+n,cmp);
		bool flag = false;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (j==i)
				  continue;
				for (int k=j+1;k<n;k++)
				{
					if (k==i)
					  continue;
					for (int m=k+1;m<n;m++)
					{
						if (m == i)
						  continue;
						if (a[i] == a[j]+a[k]+a[m])
						{
							printf("%d\n",a[i]);
							flag = true;
							break;
						}
					}
					if (flag)
					  break;
				}
				if (flag)
				  break;
			}
			if (flag)
			  break;
		}
		if (!flag)
		  printf("no solution\n");
	}
	return 0;
}
