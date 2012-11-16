#include <cstdio>
#include <cstring>
#include <time.h>
const int MAX_LEN = 10000000;
bool prime[MAX_LEN];
int main()
{	
	clock_t start,finish;
	double totaltime;
	start=clock();
	int p =4;
	memset(prime,1,sizeof(prime));
	for (int i=2;i<MAX_LEN;i++)
	{
		if (prime[i])
		{
			while (p<MAX_LEN)
			{
				prime[p] = false;
				p += i;
			}
		}
		p = 2*(i+1);
	}
	prime[0] = false;
	prime[1] = false;
	//for (int i=2;i<1000;i++)
	//  if (prime[i])
	//	printf("%d ",i);
	//printf("\n");
	/*while (1)
	{
		int a,d,n;
		scanf("%d%d%d",&a,&d,&n);
		if (a==0&&d==0&&n==0)
		  break;
		if (a == 1)
		  a+=d;
		while (n != 0)
		{
			if (prime[a])
			  n--;
			a+=d;
		}
		printf("%d\n",a-d);
	}*/
	finish=clock();
	totaltime = (double)(finish-start)/CLOCKS_PER_SEC;
	printf("%lf\n",totaltime);
	return 0;
}
