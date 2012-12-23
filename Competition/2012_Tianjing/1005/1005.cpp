#include <cstdio>
#include <cmath>
#include <time.h>
long long a[65535][32];
long long power(int a,int b)
{
	long long sum = 1;
	for (int i=0;i<b;i++)
	  sum *= a;
	return sum;
}
int main()
{
	int x,y,z,k;
	for (int i=1;i<=65535;i++)
	{
		for (int j=2;j<=31;j++)
		{
			a[i][j] = power(i,j);
		}
	}
	while (1)
	{
		scanf("%d",&k);
		clock_t start,end;
		double totaltime;
		start = clock();
		if (k == 0)
		  break;
		int count = 0;
		int p = (int) sqrt(k);
		int pp = k/2;
		for (z=2;z<=30;z++)
		{
			for (x=1;x<p;x++)
			{
				//long long xx = power(x,z);
				long long xx = a[x][z];
				if (xx>=k || xx*2>=k)
				  break;
				for (y=x+1;y<p;y++)
				{
					//long long yy = power(y,z);
					long long yy = a[y][z];
					if (yy>=k || xx+yy>=k)
					  break;
					if (xx+yy+x*y*z == k)
					{
						count++;
					}
				}
			}
		}
		printf("%d\n",count);
		end = clock();	
		totaltime=(double)(end-start)/CLOCKS_PER_SEC;
		printf("Time:%f\n",totaltime);
	}
	return 0;
}
