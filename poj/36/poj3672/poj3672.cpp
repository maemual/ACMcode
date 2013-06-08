#include <cstdio>

int main()
{
	int M, T, U, F, D;
	int cost;
	char ch;
	scanf("%d%d%d%d%d",&M,&T,&U,&F,&D);
	cost = U + D;
	int dis;
	getchar();
	for (int i=1;i<=T;i++)
	{
		scanf("%c",&ch);
		getchar();
		if (M>0)
		{
			if (ch == 'u' || ch == 'd')
			{
				M -= cost;
			}else if (ch == 'f')
			{
				M -= 2*F;
			}
			dis = i;
		}
	}
	printf("%d\n",dis-1);
	return 0;
}
