#include <cstdio>
#include <cstring>
const int MAX_LEN_W = 10000;
const int MAX_LEN_T = 1000000;
char W[MAX_LEN_W+5];
char T[MAX_LEN_T+5];
int next[MAX_LEN_W+5];
void getNext(const char s[])
{
	int i=0,j=-1,len = strlen(s);
	next[0] = -1;
	while (i<len)
	{
		if (j==-1 || s[i] == s[j])
		{
			j++;i++;
			next[i] = j;
		}else 
			j = next[j];
	}
}
int KMP(const char s[],const char p[])
{
	int i=0,j=0;
	int lens = strlen(s);
	int lenp = strlen(p);
	int sum=0;
	while (i < lens)
	{
		if (j==-1 || s[i] == p[j])
		{
			i++;
			j++;
		}else
			j = next[j];
		if (j == lenp)
		{ 
			sum++;
			printf("%d ",i-j);
			j = next[j];
		}
	}
	return sum;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%s",W);
		scanf("%s",T);
		getNext(W);
		int sum = KMP(T,W);
		printf("%d\n",sum);
	}
	return 0;
}
