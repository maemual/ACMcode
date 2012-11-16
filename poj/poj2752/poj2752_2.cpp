#include <cstdio>
#include <cstring>
const int MAX_LEN = 400000;
char s[MAX_LEN+5];
int next[MAX_LEN+5];
int ans[MAX_LEN+5];
int length;
void getNext(char s[])
{
	int j=-1;
	next[0] = -1;
	for (int i=1;i<length;i++)
	{
		while (j>=0 && s[j+1] != s[i])
		  j = next[j];
		if (s[j+1] == s[i])
		  j++;
		next[i] = j;
	}
}
int main()
{
	while (scanf("%s",s) != EOF)
	{
		length = strlen(s);
		getNext(s);
		//for (int i=0;i<length;i++)
		//  printf("%d ",next[i]);
		//printf("\n");
		int j=0;
		for (int i=length-1;i != -1;i=next[i])
			ans[j++] = i+1;
		for (int i=j-1;i>0;i--)
		  printf("%d ",ans[i]);
		printf("%d\n",ans[0]);
	}
	return 0;
}
