//note the input 0 and 0
#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

int num1[MAX_LEN+5],num2[MAX_LEN+5];
char map[]="0123456789abcdefghij";
int main()
{
	char s1[MAX_LEN+5],s2[MAX_LEN+5];
	int len1,len2;
	int i,j;
	while (scanf("%s\n%s",s1,s2) != EOF)
	{
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		len1 = strlen(s1);
		len2 = strlen(s2);
		for (i = len1 - 1; i >= 0; i--)
		{
			if (s1[i] <= '9')
			  num1[MAX_LEN+5-len1+i] = s1[i] - '0';
			else 
			  num1[MAX_LEN+5-len1+i] = s1[i] - 'a' + 10;
		}
		for (i = len2 - 1; i >= 0; i--)
		{
			if (s2[i] <= '9')
			  num2[MAX_LEN+5-len2+i] = s2[i] - '0';
			else
			  num2[MAX_LEN+5-len2+i] = s2[i] - 'a' + 10;
		}
		j = 0;
		for (i = MAX_LEN+5-1; i >= 0; i--)
		{
			num1[i] += num2[i] + j;
			if (num1[i] >= 20)
			{
				num1[i] -= 20;
				j = 1;
			}else
				j = 0;
		}
		for (i = 0; i < MAX_LEN+5; i++)
		  if (num1[i] != 0)
			break;
		if (i == MAX_LEN+5)
		{
			printf("0\n");
			continue;
		}
		for (j = i; j < MAX_LEN+5; j++)
		{
			printf("%c",map[num1[j]]);
		}
		printf("\n");
	}
	return 0;
}
