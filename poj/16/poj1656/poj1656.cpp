#include <cstdio>
#include <cstring>
const int MAX_LEN = 100;
int board[MAX_LEN+5][MAX_LEN+5];
char s[10];
void work_black(int x,int y,int d)
{
	for (int i=x;i<=x+d-1;i++)
		for (int j=y;j<=y+d-1;j++)
			board[i][j] = 1;
}
void work_white(int x,int y,int d)
{
	for (int i=x;i<=x+d-1;i++)
	  for (int j=y;j<=y+d-1;j++)
		board[i][j] = 0;
}
void work_test(int x,int y,int d)
{
	int sum = 0;
	for (int i=x;i<=x+d-1;i++)
		for (int j=y;j<=y+d-1;j++)
			if (board[i][j]==1)
			  sum++;
	printf("%d\n",sum);
}
int main()
{
	int n;
	scanf("%d",&n);
	memset(board,0,sizeof(0));
	int x,y,d;
	while (n--)
	{
		scanf("%s %d %d %d",s,&x,&y,&d);
		if (!strcmp(s,"BLACK"))
		{
			work_black(x,y,d);
		}else if (!strcmp(s,"WHITE"))
		{
			work_white(x,y,d);
		}else {
			work_test(x,y,d);
		}
	}
	return 0;
}
