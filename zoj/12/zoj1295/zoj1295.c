#include <stdio.h>
#include <string.h>

#define MAX_LEN 75

char s[MAX_LEN];
int main()
{
	int n;
	scanf("%d\n",&n);
	int len;
	int i;
	while (n--)
	{
		gets(s);
		len = strlen(s);
		for (i = len - 1; i >= 0; i--)
		  printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}
