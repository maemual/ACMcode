#include <stdio.h>
#include <string.h>
#define MAX_LEN 50

int n;
int seq[MAX_LEN+5];
void P2I(int s[])
{
	int hash[MAX_LEN+5];
	memset(hash,0,sizeof(hash));
	int i,j;
	for (i = 0; i < n; i++)
	{
		int cnt = 0;
		for (j = 0; j < i; j++)
		{
			if (s[j] > s[i])
			  cnt++;
		}
		hash[s[i]] = cnt;
	}
	for (i = 1; i < n; i++)
	  printf("%d ",hash[i]);
	printf("%d\n",hash[n]);
}
void I2P(int s[])
{
	int hash[MAX_LEN+5];
	memset(hash,0,sizeof(hash));
	int i,j;
	for (i = 0; i < n; i++)
	{
		int cnt = 0;
		for (j = 0; j < n; j++)
		{
			if (hash[j] == 0)
			  cnt++;
			if (cnt > s[i])
			  break;
		}
		hash[j] = i+1;
	}
	for (i = 0; i < n-1; i++)
	  printf("%d ",hash[i]);
	printf("%d\n",hash[n-1]);
}
int main()
{
	char ch;
	int i;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		scanf("%c",&ch);
		for (i = 0; i < n; i++)
		  scanf("%d",&seq[i]);
		if (ch == 'P')
		  P2I(seq);
		else if (ch == 'I') 
		  I2P(seq);
	}
	return 0;
}
