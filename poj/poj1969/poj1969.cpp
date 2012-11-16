#include <cstdio>

int main()
{
	int t,n,i,a,b;
	while(scanf("%d",&n)>0)
	{
		t=0;
		for(i=1;;i++)
		{
			t=t+i;
			if(t>=n)
				break;
		}
		if(i%2==0)
		{
			a=n-(t-i);
			b=i-a+1;
			printf("TERM %d IS %d/%d\n",n,a,b);
		}
		else
		{
			a=n-(t-i);
			b=i-a+1;
			printf("TERM %d IS %d/%d\n",n,b,a);
		}
	}
	return 0;
}
