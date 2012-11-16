#include <cstdio>

int main()
{
	int x;
	int ans;
	bool flag=true;
	while (scanf("%d",&x) != EOF)
	{
		if (flag&&x<=168)
		{
			ans = x;
			flag = false;
		}
	}
	if (flag)
	  printf("NO CRASH\n");
	else 
	  printf("CRASH %d\n",ans);
	return 0;
}
