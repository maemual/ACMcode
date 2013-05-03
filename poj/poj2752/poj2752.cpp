#include <cstdio>
#include <cstring>
const int MAX_LEN = 400000;
char s[MAX_LEN+5];
int next[MAX_LEN+5];
int ans[MAX_LEN+5];
int length;
void getNext(char s[])
{
	int j = -1;
	next[0] = -1;
	for (int i=1; i<length; i++)
	{
		while (j>=0 && s[j+1] != s[i])
		  j = next[j];
		if (s[j+1] == s[i])
		  j++;
		next[i] = j;
	}
}
void print(int x){
	if (next[x] == -1){
		printf("%d", x+1);
		return ;
	}
	print(next[x]);
	printf(" %d",x+1);
}
int main()
{
	while (scanf("%s",s) != EOF)
	{
		length = strlen(s);
		getNext(s);
		int j = 0;
		print(length-1);
		printf("\n");
	}
	return 0;
}
