#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
int m[3000][3000];
struct node
{
	int x,y;
}a[200005];
struct node2
{
	double dis1,dis2;
}b[200005];
bool cmp(const node2 &b1,const node2 &b2)
{
	if (b1.dis1 < b2.dis1)
	  return true;
	return false;
}
int main()
{
	int n;
	int cas = 1;
	int i,j,k;
	int ax,ay,bx,by,q;
	int r1,r2;
	int aa,bb;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		memset(m,0,sizeof(m));
		for (i = 0; i < n; i++)
		  scanf("%d %d",&a[i].x,&a[i].y);
		scanf("%d %d %d %d %d",&ax,&ay,&bx,&by,&q);
		for (i = 0; i < n; i++)
		{
			b[i].dis1 = sqrt((double)(a[i].x-ax)*(a[i].x-ax)+(a[i].y-ay)*(a[i].y-ay));
			b[i].dis2 = sqrt((double)(a[i].x-bx)*(a[i].x-bx)+(a[i].y-by)*(a[i].y-by));
		}
		sort(b,b+n,cmp);
//		printf("---------------------------\n");
//		for (i = 0; i < n; i++)
//		  printf("%lf %lf\n",b[i].dis1,b[i].dis2);
		printf("Case %d:\n",cas++);
		for (i = 0; i < q; i++)
		{
			scanf("%d %d",&r1,&r2);
			int sum = 0;
			for (j = 0; j < n; j++)
			{
				if (b[j].dis2 <= r2)
				{
					if (b[j].dis1 <= r1)
					  sum++;
					else
					  break;
				}
			}
			printf("%d\n",sum);
		}
	}
	return 0;
}
