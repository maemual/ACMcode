#include <cstdio>
#include <cstring>
const int MAX_LEN = 10000;
char s[MAX_LEN+5];
char t[MAX_LEN+5];
char ss[MAX_LEN+5];
char tt[MAX_LEN+5];
int send,tend;
int len1,len2;
bool check(char st[],int len)
{
	int length = strlen(st);
	for (int i=0;i<length;i+=len)
	{
		for (int j=0;j<len;j++)
		  if (st[j] != st[i+j])
			return false;
	}
	return true;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%s",s);
		scanf("%s",t);
		len1 = strlen(s);
		len2 = strlen(t);
		for (int i=1;i<=len1;i++)
		{
			if (len1%i==0)
			{
				if (check(s,i))
				{
					for (int j=0;j<i;j++)
					  ss[j] = s[j];
					ss[i] = '\0';
					break;
				}
			}
		}
		
		for (int i=1;i<=len2;i++)
		{
			if (len2%i==0)
			{
				if (check(t,i))
				{
					for (int j=0;j<i;j++)
					  tt[j] = t[j];
					tt[i] = '\0';
					break;
				}
			}
		}

		if (!strcmp(ss,tt))
		  printf("%s\n",ss);
		else
		  printf("I am just kidding!\n");
	}
	return 0;
}
