#include <cstdio>

int main()
{
	int a,b;
	while (1)
	{
		scanf("%d%d",&a,&b);
		if (a==0 && b==0)
		  break;
		if (a == b)
		{
			printf("Stan wins\n");
			continue;
		}
		while (1)
		{
			if (a>b)
			{
				a %= b;
				if (a == 0)
				{
					printf("Ollie wins\n");
					break;
				}
			}
			if (a<b)
			{
				b %= a;
				if (b == 0)
				{
					printf("Stan wins\n");
					break;
				}
			}
		}
	}
	return 0;
}
