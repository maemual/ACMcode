#include <cstdio>
#include <cstring>
const int MAX_LEN = 10;
int a[MAX_LEN];
char s[MAX_LEN];
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%s",s);
		//getchar();
		int len = strlen(s);
		if (len==1)
		{
			printf("%s\n",s);
			continue;
		}
		memset(a,0,sizeof(a));
		int j=len-1;
		for (int i=MAX_LEN-1;i>=MAX_LEN-len;i--)
			a[i] = s[j--]-'0';
		//for (int i=0;i<MAX_LEN;i++)
		//  printf("%d",a[i]);
		//printf("\n");
		int k = 0;
		for (int i=MAX_LEN-1;i>MAX_LEN-len;i--)
		{
			a[i]+=k;
			if (a[i]>=5)
				k=1;
			else 
				k=0;
			a[i] = 0;
		}
		a[MAX_LEN-len] += k;
		int pos=0;
		for (int i=0;i<MAX_LEN;i++)
		{
			if (a[i] != 0)
			{
				pos = i;
				break;
			}
		}
		for (int i=pos;i<MAX_LEN;i++)
		  printf("%d",a[i]);
		printf("\n");
	}
	return 0;
}
