#include <cstdio>

int main()
{
	int A,a,B,b,p;
	while (scanf("%d%d%d%d%d",&A,&a,&B,&b,&p) != EOF)
	{
		if( B<=p&&b>=A || A<=p&&a>=B || A+B<=p )
			printf("Yes\n");
		else 
			printf("No\n");
	}
	return 0;
}
