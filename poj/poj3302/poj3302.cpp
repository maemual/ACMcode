#include <cstdio>
#include <cstring>
const int MAX_LEN = 100;
char s1[MAX_LEN+5];
char s2[MAX_LEN+5];
char s3[MAX_LEN+5];
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%s%s",s1,s2);
		int len1=strlen(s1);
		int len2=strlen(s2);
		for (int i=0;i<len2;i++)
		  s3[i]=s2[len2-i-1];
		s3[len2] = '\0';
	//	printf("S1:%s\nS2:%s\nS3:%s\n",s1,s2,s3);
		bool flag = false;
		int j = 0;
		for (int i=0;i<len1;i++)
		{
			if (s1[i] == s2[j])
			  j++;
		}
		if (j == len2)
		  flag = true;
		if (!flag)
		{
			j = 0;
			for (int i=0;i<len1;i++)
			{
				if (s1[i] == s3[j])
				  j++;
			}
			if (j == len2)
			  flag = true;
		}
		if (flag)
		  printf("YES\n");
		else
		  printf("NO\n");
	}
	return 0;
}
