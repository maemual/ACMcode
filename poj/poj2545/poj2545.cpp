#include <cstdio>
const int MAX_LEN = 1000000;
long long hamm[MAX_LEN+5];
long long min(long long a,long long b,long long c)
{
	if (a>b)
	  a=b;
	if (a>c)
	  a=c;
	return a;
}
int main()
{
	int p1,p2,p3;
	int pp1=0,pp2=0,pp3=0;
	int k;
	while (scanf("%d %d %d %d",&p1,&p2,&p3,&k) != EOF)
	{
		pp1=pp2=pp3=0;
		hamm[0]=1;
		for (int i=1;i<=k;i++)
		{
			hamm[i] = min(hamm[pp1]*p1,hamm[pp2]*p2,hamm[pp3]*p3);
			if (hamm[i] == hamm[pp1]*p1)
			  pp1++;
			if (hamm[i] == hamm[pp2]*p2)
			  pp2++;
			if (hamm[i] == hamm[pp3]*p3)
			  pp3++;
		}
		printf("%lld\n",hamm[k]);
	}
	return 0;
}
