#include <cstdio>
#include <cstring>
const int MAX_LEN = 1100;
bool prime[MAX_LEN+5];

int main()
{
	int p = 4;
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
	prime[1] = true;
	int n,c;
	int sum;
	while (scanf("%d %d",&n,&c) != EOF)
	{
		sum = 0;
		for (int i=1;i<=n;i++)
		  if (prime[i])
			sum++;
		int num;
		if (sum%2==0)
		  num=2*c;
		else 
		  num=2*c-1;
		if (num>=sum)
		{
			printf("%d %d:",n,c);
			for (int i=1;i<=n;i++)
			  if (prime[i])
				printf(" %d",i);
			printf("\n\n");
		}else {
			printf("%d %d:",n,c);
			int k=0;
			int pos = 0;
			for (int i=1;i<=n;i++)
			{
				if (prime[i])
					k++;
				if (k>(sum/2-num/2))
				{
					pos = i;
					break;
				}
			}
			k = 0;
			for (int i=pos;i<=n;i++)
			{
				if (prime[i])
				{
					printf(" %d",i);
					k++;
				}
				if (k>=num)
				  break;
			}
			printf("\n\n");
		}
	}
	return 0;
}
