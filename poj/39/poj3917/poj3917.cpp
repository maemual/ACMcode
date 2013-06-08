#include <cstdio>
#include <cstring>
const int MAX_LEN = 75;
char s1[MAX_LEN+5];
char s2[MAX_LEN+5];
int main()
{
	while (1)
	{
		scanf("%s%s",s1,s2);
		if (!strcmp(s1,"E") && !strcmp(s2,"E"))
		  break;
		int len1=strlen(s1);
		int len2=strlen(s2);
		int p1=0,p2=0;
		for (int i=0;i<len1;i++)
		{
			if (s1[i] == 'R' && s2[i] == 'S' 
				|| s1[i] == 'P' && s2[i] == 'R'
				|| s1[i] == 'S' && s2[i] == 'P')
			  p1++;
			if (s1[i] == 'S' && s2[i] == 'R' 
				|| s1[i] == 'R' && s2[i] == 'P'
				|| s1[i] == 'P' && s2[i] == 'S')
			  p2++;
		}
		printf("P1: %d\nP2: %d\n",p1,p2);
	}
	return 0;
}
