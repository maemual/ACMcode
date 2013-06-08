#include <stdio.h>
#include <algorithm>
using namespace std;

struct P{
	int x,y;
	char d;
}p[80];
bool cmp(P a,P b)
{
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
int main()
{
	int i,j,k = 0,sum = 0,x;
	char d,y,c;
	scanf("White:");
	while (scanf("%c",&c) && c != '\n')
	{
		scanf("%c",&d);
		if (d < 'a'){
			scanf("%c%d",&y,&x);
			p[sum].d = d;
			p[sum].x = 9 - x;
			p[sum].y = y - 'a' + 1;
		}else {
			scanf("%d",&x);
			p[sum].d = 'P';
			p[sum].x = 9 - x;
			p[sum].y = d - 'a' + 1;
		}	
		sum++;
	}
	scanf("Black:");
	while (scanf("%c",&c) && c != '\n')
	{
		scanf("%c",&d);
		if (d < 'a'){
			scanf("%c%d",&y,&x);
			p[sum].d = d + 32;
			p[sum].x = 9 - x;
			p[sum].y = y - 'a' + 1;
		}else{
			scanf("%d",&x);
			p[sum].d = 'p';
			p[sum].x = 9 - x;
			p[sum].y = d - 'a' + 1;
		}
		sum++;
	}
	sort(p,p+sum,cmp);
	for (int i = 1; i <= 8; i++)
	{
		printf("+---+---+---+---+---+---+---+---+\n|");
		for (int j = 1; j <= 8; j++)
		{
			if ((i+j) % 2)
			  c = ':';
			else
			  c = '.';
			if (p[k].x == i && p[k].y == j && k < sum)
			  printf("%c%c%c|",c,p[k++].d,c);
			else
			  printf("%c%c%c|",c,c,c);
		}
		printf("\n");
	}
	printf("+---+---+---+---+---+---+---+---+\n");
	return 0;
}
