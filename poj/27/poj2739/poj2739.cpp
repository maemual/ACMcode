#include <cstdio>
#include <cmath>
const int Max=1229;
int a[Max];
int isprime(int x)
{   
	if(x==1) return 0;
	if(x==2) return 1;
	if(x%2==0) return 0;
	int i;
	for(i=3;i<=sqrt(x);i+=2)
	  if(x%i==0) return 0;
	return 1;
}

int main()
{
	int i,j,sum,count,n;
	for(i=2,j=0;i<10000;i++)
	  if(isprime(i)==1)
		a[j++]=i;
	while(1)
	{
		scanf("%d",&n);
		if (n==0)
		  break;
		for(i=count=0;i<Max;i++)
		{
			for(j=i,sum=0;j<Max && sum<n;j++)
			  sum+=a[j];
			if(sum==n)
			  count++;
		}
		printf("%d\n",count);
	}
	return 0;
} 
