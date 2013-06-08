#include <cstdio>
#include <algorithm>
using namespace std;
struct Pieces{
	int x,y,p;
	char b;
}w[65],b[65];
bool cmp_w(Pieces a,Pieces b)
{
	if (a.p != b.p) return a.p < b.p;
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool cmp_b(Pieces a,Pieces b)
{
	if (a.p != b.p) return a.p < b.p;
	if (a.x != b.x) return a.x > b.x;
	return a.y < b.y;
}
int power(char p)
{
	if (p == 'K' || p == 'k') return 1;
	if (p == 'Q' || p == 'q') return 2;
	if (p == 'R' || p == 'r') return 3;
	if (p == 'B' || p == 'b') return 4;
	if (p == 'N' || p == 'n') return 5;
	if (p == 'P' || p == 'p') return 6;
}
int main()
{
	int sum_b = 0,sum_w = 0;
	char a,d,c,str[100];
	for (int i = 8; i >= 1; i--)
	{
		scanf("%s",str);
		getchar();
		for (int j = 0; j < 8; j++)
		{
			getchar();
			scanf("%c%c%c",&a,&d,&c);
			if (d == '.' || d == ':')
			  continue;
			if (d >= 'a' && d <= 'z'){
				b[sum_b].x = i;
				b[sum_b].y = j;
				b[sum_b].b = d - 32;
				b[sum_b++].p = power(d);
			}else {
				w[sum_w].x = i;
				w[sum_w].y = j;
				w[sum_w].b = d;
				w[sum_w++].p = power(d);
			}
		}
		getchar();getchar();
	}
	scanf("%s",str);getchar();
	sort(b,b+sum_b,cmp_b);
	sort(w,w+sum_w,cmp_w);
	printf("White: ");
	for (int i = 0; i < sum_w; i++)
	{
		if (w[i].b != 'P') 
		  printf("%c",w[i].b);
		printf("%c%d%c",w[i].y+'a',w[i].x,(i == sum_w-1)?'\n':',');
	}
	printf("Black: ");
	for (int i = 0; i < sum_b; i++)
	{
		if (b[i].b != 'P')
		  printf("%c",b[i].b);
		printf("%c%d%c",b[i].y+'a',b[i].x,(i == sum_b-1)?'\n':',');
	}
	return 0;
}
