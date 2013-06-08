/*************************************************************************
	> File Name: zoj1078.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月02日 星期六 15时37分16秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
char str[20];
void conv(char s[],int num,int radix)
{
	int i;
	for (i = 0; ; i++)
	{
		s[i] = (num % radix) + '0';
		num /= radix;
		if (num == 0)
			break;
	}
	s[i+1] = '\0';
	/*printf("radix %d : %s\n",radix,s);*/
}
int check(char s[])
{
	int len = strlen(s);
	/*printf("check : %s\n",s);*/
	int i,j;
	for (i = 0; i < len; i++)
	{
		if (s[i] != s[len - i - 1])
			return 0;
	}
	return 1;
}
int main()
{
	int num;
	int k,flag;
	int i;
	int ans[20];
	while (1)
	{
		scanf("%d",&num);
		if (num == 0)
			break;
		k = 0;
		for (i = 2; i <= 16; i++)
		{
			conv(str,num,i);
			if (check(str))
			{
				ans[k++] = i;
				/*printf("%s\n",str);*/
			}
		}
		if (!k)
			printf("Number %d is not a palindrom\n",num);
		else{
			printf("Number %d is palindrom in basis",num);
			for (i = 0; i < k; i++)
				printf(" %d",ans[i]);
			printf("\n");
		}
	}
	return 0;
}
