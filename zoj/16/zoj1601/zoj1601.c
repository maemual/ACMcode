#include<stdio.h>
#include<math.h>
#define inf 99999999

int main()
{
	int l,n,d,ansn,ansd;
	double a,min,now,kk;
	while(scanf("%lf%d",&a,&l)!=EOF)
	{
		n=1,d=1,min=99999999;
		while(n<=l&&d<=l)
		{
			kk=a-(double)n/d;
			now=fabs(kk);
			if(now<min)
			{
				min=now;
				ansn=n;
				ansd=d;
			}
			if(kk<=0)
				d++;
			else
				n++;
		}
		printf("%d %d\n",ansn,ansd);
	}
	return 0;
}
