#include <cstdio>
#include <cstring>
const int MAX_LEN = 255;
char s[MAX_LEN+5];

int main()
{
	int len;
	int sum;
	while (1)
	{
		gets(s);
		if (s[0] == '#')
		  break;
		len = strlen(s);
		sum = 0;
		for (int i=1;i<=len;i++)
		{
			if (s[i-1]>='A' && s[i-1]<='Z')
				sum += i*(s[i-1]-'A'+1);
		}
		printf("%d\n",sum);
		//printf("%s\n",s);
	}
	return 0;
}
