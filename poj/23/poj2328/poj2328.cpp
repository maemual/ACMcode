#include <cstdio>
#include <cstring>
char s[10];

int main()
{
	while (1)
	{
		int n;
		int begin=1,end=10;
		bool flag = false;
		while (1)
		{
			scanf("%d",&n);
			//printf("%d\n",n);
			if (n == 0)
			{
				flag = true;
				break;
			}
			getchar();
			gets(s);
			//printf("%s\n",s);
			//getchar();
			if (!strcmp(s,"right on"))
			  break;
			if (!strcmp(s,"too high"))
			  end = n-1;
			else
			  begin = n+1;
		}
		if (flag)
		  break;
		if (n>=begin && n<=end)
		  printf("Stan may be honest\n");
		else 
		  printf("Stan is dishonest\n");
	}
	return 0;
}
