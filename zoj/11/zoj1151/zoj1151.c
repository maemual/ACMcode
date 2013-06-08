#include <stdio.h>
#include <string.h>

#define MAX_LEN 200
char word[MAX_LEN];

int main()
{
	int cas;
	scanf("%d",&cas);
	int i,j;
	while (cas--)
	{
		int n;
		scanf("%d",&n);
		for (i = 0; i < n;)
		{
			scanf("%s",word);
			int len = strlen(word);
			for (j = len -1; j >= 0; j--)
			  printf("%c",word[j]);
			if (getchar() == '\n')
			{
				printf("\n");
				i++;
				continue;
			}
			else 
				printf(" ");
		}
		if (cas)
		  printf("\n");
	}
	return 0;
}
