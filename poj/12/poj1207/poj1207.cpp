#include <cstdio>
#include <cstring>
const int MAX_LEN = 10000;
int a[MAX_LEN+5];

int main()
{
	memset(a,0,sizeof(a));
	int x;
	for (int i=1;i<MAX_LEN;i++)
	{
		x = i;
		while (x != 1)
		{
			if (x%2==1)
			  x=3*x+1;
			else 
			  x/=2;
			a[i]++;
		}
		a[i]++;
	}
	int m,n,mm,nn;
	while (scanf("%d %d",&m,&n) != EOF)
	{
		if (m>n)
		{
			mm = n;
			nn = m;
		}else {
			mm = m;
			nn = n;
		}
		int max = -1;
		for (int i=mm;i<=nn;i++)
		{
			if (max < a[i])
			  max = a[i];
		}
		printf("%d %d %d\n",m,n,max);
	}
	//printf("%d\n",a[1]);
	return 0;
}
