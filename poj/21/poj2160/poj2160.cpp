#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	int x,y;
}a[6];
int swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
bool cmp(const node &n1,const node &n2)
{
	if(n1.x==n2.x) 
	  return n1.y>n2.y;
	else 
	  return n1.x>n2.x;
}
int main()
{
	for (int i=0;i<6;i++)
	{ 
		scanf("%d%d",&a[i].x,&a[i].y);
		if (a[i].x < a[i].y)
		  swap(a[i].x,a[i].y);
	}
	sort(a,a+6,cmp);
	if (a[0].x==a[1].x&&a[0].x==a[2].x&&a[0].x==a[3].x
		&& a[0].y==a[1].y&&a[0].y==a[4].x&&a[0].y==a[5].x
		&& a[2].y==a[3].y&&a[2].y==a[4].y&&a[2].y==a[5].y)
	  printf("POSSIBLE\n");
	else
	  printf("IMPOSSIBLE\n");
	return 0;
}
