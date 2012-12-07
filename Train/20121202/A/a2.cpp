#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int MAX_LEN = 200005;
struct node
{
	int k;
	int dis;
}dis1[MAX_LEN],dis2[MAX_LEN];
bool p1[MAX_LEN],p2[MAX_LEN];
int xx[MAX_LEN],yy[MAX_LEN];
bool cmp(const node &n1,const node &n2)
{
	if (n1.dis < n2.dis)
	  return true;
	return false;
}
int main()
{
	int n;
	int ax,ay,bx,by,q;
	while (1)
	{
		scanf("%d",&n);
		if (n == 0)
		  break;
		memset(p1,false,sizeof(p1));
		memset(p2,false,sizeof(p2));
		for (int i = 0; i < n; i++)
		  scanf("%d %d",&xx[i],&yy[i]);
		scanf("%d %d %d %d %d",&ax,&ay,&bx,&by,&q);
		for (int i = 0; i < n; i++)
		{
			dis1[i].dis = (xx[i]-ax)*(xx[i]-ax)+(yy[i]-ay)*(yy[i]-ay);
			dis2[i].dis = (xx[i]-bx)*(xx[i]-bx)+(yy[i]-by)*(yy[i]-by);
			dis1[i].k = dis2[i].k = i;
		}
		sort(dis1,dis1+n,cmp);
		sort(dis2,dis2+n,cmp);
		//printf("%d",dis1[0].dis-dis1[1].dis);
		
		int i = 0,j = n-1;
		int mid = (i+j)/2;
		while (1)
		{
			if ()
		}
	}
	return 0;
}
