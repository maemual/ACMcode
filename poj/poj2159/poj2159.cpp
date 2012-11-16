#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAX_LEN = 100;
char s1[MAX_LEN+5];
char s2[MAX_LEN+5];
int num1[26];
int num2[26];
int main()
{
	while (scanf("%s%s",s1,s2) != EOF)
	{
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		for (int i=0;i<len1;i++)
		{
			num1[s1[i]-'A']++;
			num2[s2[i]-'A']++;
		}
		std::sort(num1,num1+26);
		std::sort(num2,num2+26);
		bool flag = true;
		for (int i=0;i<26;i++)
		{
			if (num1[i] != num2[i])
			{
				printf("NO\n");
				flag = false;
				break;
			}
		}
		if (flag)
		  printf("YES\n");
	}
	return 0;
}
