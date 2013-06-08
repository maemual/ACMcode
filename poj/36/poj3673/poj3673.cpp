#include <cstdio>
#include <cstring>
const int MAX_LEN = 15;
char s1[MAX_LEN+5];
char s2[MAX_LEN+5];
int main()
{
	while (scanf("%s%s",s1,s2) != EOF)
	{
		int len1=strlen(s1);
		int len2=strlen(s2);
		long long sum = 0;
		for (int i=0;i<len1;i++)
		{
			for (int j=0;j<len2;j++)
			{
				sum += (s1[i]-'0')*(s2[j]-'0');
			}
		}
		printf("%lld\n",sum);
	}
	return 0;
}
