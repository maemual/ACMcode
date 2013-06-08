#include <cstdio>
#include <cstring>
int main()
{
	char s[100];
	scanf("%s",s);
	char st[100];
	int len = strlen(s);
	while (scanf("%s",st) != EOF)
	{
		for (int i=0;i<len;i++)
		{
			s[i]+= st[i]-'0';
			if (s[i]>'9')
			  s[i] -= 10;
		}
	}
	printf("%s\n",s);
	return 0;
}
