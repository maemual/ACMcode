#include <stdio.h>
#include <string.h>
#define MAX_LEN 100005
char num[MAX_LEN];
int main()
{
	scanf("%s",num);
	int len = strlen(num);
	int flag = 1;
	int i;
	int pos = 0;
	for (i = 0; i < len; i++)
	{
		if (num[i] == '0')
		{
			flag = 0;
			pos = i;
			break;
		}
	}
	if (flag)
	{
		for (i = 0; i < len-1; i++)
		  printf("%c",num[i]);
		printf("\n");
		return 0;
	}
	for (i = 0; i < pos; i++)
	{
		printf("%c",num[i]);
	}
	for (i = pos+1; i < len; i++)
	{
		printf("%c",num[i]);
	}
	printf("\n");
	return 0;
}
