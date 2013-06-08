#include <cstdio>
int main()
{
	int n,cas;
	scanf("%d%d",&n,&cas);
	while(cas--)
	{
		int s,t,r;
		scanf("%d%d%d",&s,&t,&r);
		if(n%(s*t)==0)
		  printf("%d\n",(n/(s*t)-1)*r+n/s);
		else if(n%s==0)
		  printf("%d\n",n/(s*t)*r+n/s);
		else
		  printf("%d\n",n/(s*t)*r+n/s+1);
	}
	return 0;
}
