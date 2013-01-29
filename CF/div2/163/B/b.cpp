#include <stdio.h>

int main()
{
	int n,t;
	scanf("%d %d",&n,&t);
	char str[55];
	scanf("%s",str);
	int i,j;
	for (i = 0; i < t; i++)
	{
		for (j = 0; j < n;)
		{
			if (j+1 < n && str[j] == 'B' && str[j+1] == 'G')
			{
				str[j] = 'G';
				str[j+1] = 'B';
				j = j + 2;
			}else
			  j++;
		}
	}
	printf("%s\n",str);
	return 0;
}
