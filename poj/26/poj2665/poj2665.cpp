#include <cstdio>

int main()
{
	int len,m;
	int start,end;
	while (1)
	{
		scanf("%d%d",&len,&m);
		if (len == 0 && m == 0)
			break;
		len++;
		for (int i=0;i<m;i++)
		{
			scanf("%d%d",&start,&end);
			len -= end-start+1;
		}
		printf("%d\n",len);
	}
	return 0;
}
