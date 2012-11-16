#include <cstdio>
#include <cstring>
const int MAX_LEN = 1000000;
char s[MAX_LEN+5];
int length;
bool check(int len)
{
	for (int i=0;i<length;i+=len)
	{
		for (int j=0;j<len;j++)
		{
			if (s[i+j] != s[j])
			  return false;
		}
	}
	return true;
}
int main()
{
	while (1)
	{
		scanf("%s",s);
		if (s[0] == '.' && strlen(s))
		  break;
		length = strlen(s);
		if (length % 2 == 1)
		{
			printf("%d\n",1);
		}else {
			for (int i=1;i<=length;i++)
			{
				if (length % i == 0)
				{
					if (check(i))
					{
						printf("%d\n",length/i);
						break;
					}
				}
			}
		}
	}
	return 0;
}
