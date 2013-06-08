#include <stdio.h>
#include <string.h>

#define MAX_LEN 105
int main()
{
	int cas;
	int i,j;
	scanf("%d",&cas);
	char s[MAX_LEN];
	while (cas--)
	{
		scanf("%s",s);
		int len = strlen(s);
		int k = 0;
		for (i = 0; i < len; i++)
		{
			if (s[i+1] == s[i])
			  k++;
			else {
				if (k != 0)
				{
					printf("%d",k+1);
					k = 0;
				}
				printf("%c",s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
