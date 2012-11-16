#include <stdio.h>

int main()
{
	int cas;
	scanf("%d",&cas);
	for (int k=1;k<=cas;k++)
	{
		int sum;
		scanf("%d",&sum);
		bool flag = false;
		for (int q=sum/25;q>=0;q--)
		{
			for (int d=sum/10;d>=0;d--)
			{
				for (int n=sum/5;n>=0;n--)
				{
					if (q*25+d*10+n*5<=sum)
					{
						printf("%d %d QUARTER(S), %d DIME(S), %d NICKEL(S), %d PENNY(S)\n",k,q,d,n,sum-q*25-d*10-n*5);
						flag = true;
						break;
					}
				}
				if (flag)
				  break;
			}
			if (flag)
			  break;
		}
	}
	return 0;
}
