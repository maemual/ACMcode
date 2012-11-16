//计算几何，判断三点是否共线
#include <cstdio>

typedef struct
{
	int x,y,count;
}Point;


Point p[203];

double a[203];

int main()
{

	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d %d",&p[i].x,&p[i].y);
	}
	int temp,max=0;
	for(i=0;i<n;i++)
	{

		for(int j=i+1;j<n;j++)
		{

			temp=0;
			for(int k=j+1;k<n;k++)
			{
				int a=(p[i].x-p[k].x)*(p[j].y-p[k].y);
				int b=(p[i].y-p[k].y)*(p[j].x-p[k].x);
				if(a==b) temp++;
			}
			max=max>temp?max:temp;
		}
	}

	printf("%d\n",max+2);
	return 0;
}
