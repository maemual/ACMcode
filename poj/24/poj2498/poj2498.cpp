#include <cstdio>
#include <cstring>
int fac1[]={9,7,3,9,7,3,9};
int fac2[]={7,3,9,7,3,9};
char s[10];
int main()
{
	int cas;
	scanf("%d",&cas);
	for (int k=1;k<=cas;k++)
	{
		scanf("%s",s);
		//printf("%s\n",s);
		int pos = 0;
		int len = strlen(s);
		int sum = 0;
		if (len == 6)
		{
			for (int i=0;i<len;i++)
			{
				if (s[i] != '?')
				{
					sum+=(s[i]-'0')*fac2[i];
				}else
				  pos = i;
			}
			for (int i=0;i<=9;i++)
			{
				if ((sum+i*fac2[pos])%10 == 0)
				{
					s[pos] = i+'0';
					break;
				}
			}
		}else {
			for (int i=0;i<len;i++)
			{
				if (s[i] != '?')
				{
					sum+=(s[i]-'0')*fac1[i];
				}else
				  pos = i;
			}
			for (int i=0;i<=9;i++)
			{
				if ((sum+i*fac1[pos]) % 10 == 0)
				{
					s[pos] = i+'0';
					break;
				}
			}
		}
		printf("Scenario #%d:\n%s\n\n",k,s);
	}
	return 0;
}
