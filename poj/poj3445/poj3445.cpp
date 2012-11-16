#include <stdio.h>
#include <string.h>

const int MAX_NUM = 15;
const int MAX_LEN = 90000;
char number[MAX_NUM+1][MAX_LEN];
int main()
{
	strcpy(number[0],"{}");
	for (int i=1;i<=15;i++)
	{
		strcpy(number[i],"{");
		for (int j=0;j<i-1;j++)
		{
			strcat(number[i],number[j]);
			strcat(number[i],",");
		}
		strcat(number[i],number[i-1]);
		strcat(number[i],"}");
	}
//	printf("%s\n",number[3]);
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		char s1[MAX_LEN];
		char s2[MAX_LEN];
		scanf("%s%s",s1,s2);
		int n1,n2;
		for (int i=0;i<=15;i++)
		{
			if (!strcmp(s1,number[i]))
			{
				n1 = i;
				break;
			}
		}
		for (int i=0;i<=15;i++)
		{
			if (!strcmp(s2,number[i]))
			{
				n2 = i;
				break;
			}
		}
		printf("%s\n",number[n1+n2]);
	}
	return 0;
}
