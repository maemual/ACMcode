#include <stdio.h>

int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		char s1[5],s2[5];
		scanf("%s %s",s1,s2);
		int n1 = 0,n2 = 0;
		for (int i=0;i<4;i++)
		{
			if (s1[i] == s2[i])
				n1++;
			for (int j=0;j<4;j++)
			{
				if (s1[i] == s2[j])
				  n2++;
			}
		}
		printf("%dA%dB\n",n1,n2-n1);
	}
	return 0;
}
