#include <cstdio>
#include <cstring>
const int MAX_LEN = 400000;
char s[MAX_LEN+5];
int length;
bool check(int k)
{
	int begin = length - k;
	for (int i=0;i<k;i++)
	{
		if (s[i] != s[begin + i])
		  return false;
	}
	return true;
}
int main()
{
	while (scanf("%s",s) != EOF)
	{
		length = strlen(s);
		for (int i=1;i<length;i++)
		{
			if (s[i-1] == s[length-1] && s[0] == s[length-i] && check(i))
			{
				printf("%d ",i);
			}
		}
		printf("%d\n",length);
	}
	return 0;
}
