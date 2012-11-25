#include <cstdio>
#include <cstring>
const int MAX_LEN = 10000;
char s1[MAX_LEN+5];
char s2[MAX_LEN+5];
int next1[MAX_LEN+5];
int next2[MAX_LEN+5];
void getNext(const char s[],int next[])
{
	int i=1,j=-1,len=strlen(s);
	next[0] = -1;
	while (i<len)
	{
		if (j==-1 || s[i-1] == s[j])
		{
			j++;
			next[i] = j;
			i++;
		}else
			j = next[j];
	}
}
int main()
{
	int cas;
	scanf("%d",&cas);
	while (cas--)
	{
		scanf("%s",s1);
		scanf("%s",s2);
		int len1 = strlen(s1),len2 = strlen(s2);
		getNext(s1,next1);
		getNext(s2,next2);

		int k1,k2;
		if (len1 % (len1-1-next1[len1-1]) == 0 && s1[len1-1] == s1[next1[len1-1]])
		  k1 = len1-1-next1[len1-1];
		else 
		  k1 = len1;

		if (len2 % (len2-1-next2[len2-1]) == 0 && s2[len2-1] == s2[next2[len2-1]])
		  k2 = len2-1-next2[len2-1];
		else 
		  k2 = len2;
		char ss1[MAX_LEN+5],ss2[MAX_LEN+5];
		for (int i=0;i<k1;i++)
		  ss1[i] = s1[i];
		for (int i=0;i<k2;i++)
		  ss2[i] = s2[i];

		ss1[k1] = '\0';
		ss2[k2] = '\0';

		if (!strcmp(ss1,ss2))
		  printf("%s\n",ss1);
		else 
		  printf("I am just kidding!\n");
	}
	return 0;
}
