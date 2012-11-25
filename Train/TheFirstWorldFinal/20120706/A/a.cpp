#include <cstdio>
const int MAX_LEN = 1024;
char map[MAX_LEN+5][MAX_LEN+5];
const int dx[6]={1,4,16,64,256,1024};
const int dy[6]={1,3,9,27,81,243};
int pow(int a,int b)
{
	int sum = 1;
	for (int i=0;i<b;i++)
		sum *= a;
	return sum;
}
void f(int x,int y,int k)
{
	if (k==0)
		map[x][y] = '+';
	else{	
								f(x+0*dx[k-1]	,y+dy[k-1],k-1);
		f(x+1*dx[k-1]	,y,k-1);f(x+1*dx[k-1]	,y+dy[k-1],k-1);f(x+1*dx[k-1]	,y+2*dy[k-1],k-1);
								f(x+2*dx[k-1]	,y+dy[k-1],k-1);
								f(x+3*dx[k-1]	,y+dy[k-1],k-1);
	}
}
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		for (int i=0;i<=pow(4,n);i++)
			for (int j=0;j<=pow(3,n);j++)
				map[i][j] = ' ';

		f(0,0,n);

		for (int i=0;i<pow(4,n);i++)
		{
			for (int j=0;j<pow(3,n);j++)
			{
				printf("%c",map[i][j]);
			}
			printf("\n");
		}
		printf("END\n");
	}
	return 0;
}
