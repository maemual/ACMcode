#include <cstdio>
#include <cstring>
const int MAX_LEN = 10000000;
char s[MAX_LEN+5];
bool cmp(int begin1,int begin2,int k)
{
	for (int i=0;i<k;i++)
		if (s[begin1+i] != s[begin2+i])
			return false;
	return true;
}
int main()
{
	while (1)
	{
		scanf("%s",s);
		if (!strcmp(s,"."))
		  break;
		int len = strlen(s);
		if (len % 2 == 1)
		{
			bool flag = false;
			for (int i=0;i<strlen(s)-1;i++)
			{
				if (s[i] != s[i+1])
				{
					flag = true;
					break;
				}
			}
			if (flag)
			  printf("%d\n",1);
			else 
			  printf("%d\n",len);
		}
		for (int i=1;i<=len/2;i++)
		{
			if (len % i == 0)
			{
				bool flag = false;
				for (int j=1;j<=len/i-1;j++)
				{
					if (cmp(0,j*i,))
				}
			}
		}
	}
	return 0;
}
