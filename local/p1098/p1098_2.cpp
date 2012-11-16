#include <cstdio>
#include <cstring>
const int MAX_LEN = 1000000;
char s[MAX_LEN+5];
int next[MAX_LEN+5];
void getNext(char s[])
{
	int j=-1,len;
	len=strlen(s);
	next[0]=-1;
	for(int i=1;i<len;i++)
	{
		while(j>=0 && s[j+1]!=s[i])
			j=next[j];
		if(s[j+1]==s[i])
		  j++;
		next[i]=j;
	}
}


int main()
{
	while (1)
	{
		scanf("%s",s);
		if (s[0] == '.' && strlen(s) == 1)
		  break;
		getNext(s);
		int k = strlen(s)-1,pre;
		while (next[k] != -1)
		{
			k = next[k];
		}
		printf("%d\n",strlen(s)/(k+1));
	}
	return 0;
}

