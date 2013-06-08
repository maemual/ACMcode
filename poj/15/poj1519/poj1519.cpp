#include <cstdio>
#include <string.h>
#define M 10000

int root(int n)
{
	int t=0;
	if(n>9)
	{
		while(n)
		{
			t+=n%10;
			n=n/10;
		}
		return root(t);
	}
	return n;
}

int main()
{
	char n[M];
	int i,t;
	while(scanf("%s",n)>0)
	{
		if(strcmp(n,"0")==0)
		  break;
		t=0;
		for(i=0;i<strlen(n);i++)
			t+=n[i]-'0';
		printf("%d\n",root(t));
	}
	return 0;
}

