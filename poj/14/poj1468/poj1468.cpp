#include <cstdio>
const int MAX_LEN = 5000;
struct rectangle
{
	int xmin,xmax;
	int ymin,ymax;
}a[MAX_LEN+5];
int main()
{
	int n;
	while (scanf("%d",&n) != EOF)
	{
		for (int i=0;i<n;i++)
		  scanf("%d%d%d%d",&a[i].xmin,&a[i].xmax,&a[i].ymin,&a[i].ymax);
		int sum = 0;
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (i != j 
					&& a[i].xmin>=a[j].xmin && a[i].xmax<=a[j].xmax
					&& a[i].ymin>=a[j].ymin && a[i].ymax<=a[j].ymax)
				{
					sum++;
					break;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
