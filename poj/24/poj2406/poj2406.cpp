#include <cstdio>
#include <cstring>
const int MAX_LEN = 1000000;
char s[MAX_LEN+5];
int next[MAX_LEN+5];
void getNext(char s[])
{
	int j=-1,len;
	len = strlen(s);
	next[0] = -1;
	for(int i = 1; i < len; i++)
	{
		while(j>=0 && s[j+1]!=s[i])
		  j=next[j];
		if(s[j+1] == s[i])
		  j++;
		next[i] = j;
	}
}
int main()
{
	while (1)
	{
		scanf("%s",s);
		int len = strlen(s);
		if (s[0] == '.' && len == 1)
		  break;
		getNext(s);
		if (len % (len - next[len-1] - 1) == 0)
			printf("%d\n",len / (len - next[len-1] - 1));
		else
			printf("1\n");
	}
	return 0;
}
