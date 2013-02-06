#include <stdio.h>
#include <string.h>
#define MAX_LEN 35000
int table[MAX_LEN];
int main()
{
	memset(table,0,sizeof(table));
	int a,b,c,d;
	int aa,bb,cc,dd;
	for (a = 0; a < 200; a++)
	{
		aa = a*a;
		if (aa < MAX_LEN)
		{
			for (b = a; b < 200; b++)
			{
				bb = b*b;
				if (aa+bb < MAX_LEN)
				{
					for (c = b; c < 200; c++)
					{
						cc = c*c;
						if (aa+bb+cc<MAX_LEN)
						{
							for (d = c; d < 200; d++)
							{
								dd = d*d;
								if (aa+bb+cc+dd < MAX_LEN)
								{
									table[aa+bb+cc+dd]++;
								}
							}
						}
					}
				}
			}
		}
	}
	int n;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		printf("%d\n",table[n]);
	}
	return 0;
}
