#include <cstdio>
#include <cstring>
#include <cstdlib>
const int MAX_LEN = 10000;
char s[MAX_LEN+5][10];
bool check(const char s1[],const char s2[])
{
	int len = strlen(s1)<strlen(s2)?strlen(s1):strlen(s2);
	for (int i=0;i<len;i++)
	{
		if (s1[i] != s2[i])
		  return false;
	}
	return true;
}
int cmp(const void* s1,const void* s2)
{
	return strcmp((char *)s1,(char*)s2);
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		int n;
		scanf("%d",&n);
		for (int i=0;i<n;i++)
		  scanf("%s",s[i]);
		qsort(s,n,sizeof(s[0]),cmp);
		//for (int i=0;i<n;i++)
		//  printf("%s\n",s[i]);
		bool flag = true;
		for (int i=0;i<n-1;i++)
		{
			if (check(s[i],s[i+1]))
			{
				flag = false;
				break;
			}
		}
		if (flag)
		  printf("YES\n");
		else
		  printf("NO\n");
	}
	return 0;
}
