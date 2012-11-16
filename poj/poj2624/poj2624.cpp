#include <cstdio>
struct node
{
	double x,y;
}a[4];
void swap(node &m,node &n)
{
	double temp = m.x;
	m.x = n.x;
	n.x = temp;
	temp = m.y;
	m.y = n.y;
	n.y = temp;
}
int main()
{
	while (scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a[0].x,&a[0].y,&a[1].x,&a[1].y,&a[2].x,&a[2].y,&a[3].x,&a[3].y) != EOF)
	{
		if (a[0].x == a[2].x && a[0].y == a[2].y)
		{
			swap(a[0],a[1]);
		}else if (a[1].x == a[3].x && a[1].y == a[3].y)
		{
			swap(a[2],a[3]);
		}else if (a[0].x == a[3].x && a[0].y == a[3].y)
		{
			swap(a[0],a[1]);
			swap(a[2],a[3]);
		}
		printf("%.3lf %.3lf\n",a[0].x-a[1].x+a[3].x,a[0].y-a[1].y+a[3].y);
	}
	return 0;
}
