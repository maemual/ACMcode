#include <stdio.h>

#define RED 0
#define BLUE 1

int n,m;
int a[200005];
int i;
int p1,v1;
int p2,v2;
void doit(int k,int &p,int &v)
{
	a[0] = k;
	int red = n;
	int blue = m;
	if (k == RED)
	  red--;
	else 
	  blue--;
	for (i = 1; i < n+m; i++)
	{
		if (i % 2 == 0)
		{
			if (a[i-1] == RED && red > 0)
			{
				a[i] = RED;
				red--;
			}else if (a[i-1] == RED && red <= 0)
			{
				a[i] = BLUE;
				blue--;
			}
			if (a[i-1] == BLUE && blue > 0)
			{
				a[i] = BLUE;
				blue--;
			}else if (a[i-1] == BLUE && blue <= 0)
			{
				a[i] = RED;
				red--;
			}
		}
		else{
			if (a[i-1] == RED && blue > 0)
			{
				a[i] = BLUE;
				blue--;
			}else if (a[i-1] == RED && blue <= 0)
			{
				a[i] = RED;
				red--;
			}
			if (a[i-1] == BLUE && red > 0)
			{
				a[i] = RED;
				red--;
			}else if (a[i-1] == BLUE && red <= 0)
			{
				a[i] = BLUE;
				blue--;
			}
		}
	}
	p = v = 0;
	for (i = 0; i < n+m-1; i++)
	{
		if (a[i] == a[i+1])
		  p++;
		else
		  v++;
	}
}
int main()
{
	scanf("%d %d",&n,&m);	
	doit(RED,p1,v1);
	doit(BLUE,p2,v2);
	if (p1 > p2)
	  printf("%d %d\n",p1,v1);
	else
	  printf("%d %d\n",p2,v2);
	return 0;
}
