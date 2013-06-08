#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000
char num[MAX_LEN+5];
int sum(char s[])
{
	int x = 0;
	int len = strlen(s);
	int i;
	for (i = 0; i < len; i++)
	  x += s[i] - '0';
	return x;
}
int main()
{
	int n;
	while (1)
	{
		scanf("%s",num);
		n = sum(num);
		if (n == 0)
		  break;
		int x = n % 9;
		if (x == 0)
		  printf("9\n");
		else
		  printf("%d\n",x);
	}
	return 0;
}
