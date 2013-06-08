#include <stdio.h>
#include <string.h>
int main()
{
	int s[10],m[10],p[10],z[8];
	char str[30];
	int i,j;
	while (scanf("%s",str) != EOF)
	{
		int len = strlen(str);
		memset(s,0,sizeof(s));
		memset(m,0,sizeof(m));
		memset(p,0,sizeof(p));
		memset(z,0,sizeof(z));
		for (i = 0; i < len; i+=2)
		{
			if (str[i+1] == 's')
			{
				s[str[i] - '0']++;
			}else if (str[i+1] == 'm')
			{
				m[str[i] - '0']++;
			}else if (str[i+1] == 'p')
			{
				p[str[i] - '0']++;
			}else if (str[i+1] == 'z')
			{
				z[str[i] - '0']++;
			}
		}
		int sum = 0;
		for (i = 1; i < 10; i++)
		{
			if (s[i] == 2)
			  sum++;
			if (m[i] == 2)
			  sum++;
			if (p[i] == 2)
			  sum++;
			if (i <8 && z[i] == 2)
			  sum++;
		}
		if (sum == 7)
		{
			printf("Seven Pairs\n");
			continue;
		}
		int flag = 0;
		for (i = 2; i < 9; i++)
		{
			if (s[i]!=0 || m[i]!=0 || p[i] != 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
		{
			printf("Neither!\n");
			continue;
		}
		if (s[1]>=1 && s[9]>=1 && m[1]>=1 && m[9]>=1 && p[1]>=1 && p[9]>=1)
		{
			if (z[1]>=1&&z[2]>=1&&z[3]>=1&&z[4]>=1&&z[5]>=1&&z[6]>=1&&z[7]>=1)
			{
				printf("Thirteen Orphans\n");
				continue;
			}
		}
		printf("Neither!\n");
	}
	return 0;
}
