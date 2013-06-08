#include <cstdio>
#include <cmath>
void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	double x = (1+sqrt(5.0)) /2;
	int ak,bk;
	while(scanf("%d%d",&ak,&bk) != EOF)
	{
		if (ak > bk)
			swap(ak,bk);
		int k = bk - ak;
		int p = (int)(k*x);
		if (ak == p)
		  printf("0\n");
		else 
		  printf("1\n");
	}
	return 0;
}
