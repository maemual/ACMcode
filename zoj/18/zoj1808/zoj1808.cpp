#include <cstdio>
#include <cstring>
const int MAX_LEN = 10;
char s[MAX_LEN+5][MAX_LEN+5];
bool check(char s1[],char s2[])
{
	int len = strlen(s1)<strlen(s2)?strlen(s1):strlen(s2);
	for (int i=0;i<len;i++)
	{
		if (s1[i] != s2[i])
		  return false;
	}
	return true;
}
int main()
{
	int cas = 0;
	int n = 0;
	while (scanf("%s",s[0]) != EOF)
	{
		n = 0;
		while (1)
		{
			scanf("%s",s[++n]);
			if (s[n][0] == '9')
			  break;
		}
		//for (int i=0;i<n;i++)
		//  printf("%s\n",s[i]);
		bool flag = true;
		for (int i=0;i<n-1;i++)
		{
			for (int j=i+1;j<n;j++)
			{
				if (check(s[i],s[j]))
				{
					flag = false;
					break;
				}
			}
		}
		if (flag)
		  printf("Set %d is immediately decodable\n",++cas);
		else 
		  printf("Set %d is not immediately decodable\n",++cas);
	}
	return 0;
}
