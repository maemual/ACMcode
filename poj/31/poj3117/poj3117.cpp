#include <stdio.h>

int main()
{
	int n,m;
	while (1)
	{
		scanf("%d %d",&n,&m);
		if (n==0 && m==0)
		  break;
		char s[20];
		int sum = 0,tmp;
		for (int i=0;i<n;i++)
		{
			scanf("%s %d",s,&tmp);
			sum += tmp;
		}
		printf("%d\n",3*m-sum);
	}
	return 0;
}
