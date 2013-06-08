#include <cstdio>
#include <cstring>
int main()
{
	int n;
	scanf("%d",&n);
	char s[1005];
	while (n--)
	{
		scanf("%s",s);
		int i=0,j=0;
		int len = strlen(s);
		while (1)
		{
			j=i;
			while (j+1 <= len && s[j+1] == s[i])
				j++;
			printf("%d%c",j-i+1,s[i]);
			i=j+1;
			if (i >= len)
				break;
		}
		printf("\n");
	}
	return 0;
}
