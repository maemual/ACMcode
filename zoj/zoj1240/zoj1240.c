#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

char s[MAX_LEN+5];

char map[]="BCDEFGHIJKLMNOPQRSTUVWXYZA";
int main()
{
	int n;
	scanf("%d",&n);
	int k;
	int i;
	for (k = 1; k <= n; k++)
	{
		scanf("%s",s);
		int len = strlen(s);
		printf("String #%d\n",k);
		for (i = 0; i < len ; i++)
		  printf("%c",map[s[i] - 'A']);
		printf("\n\n");
	}
	return 0;
}
