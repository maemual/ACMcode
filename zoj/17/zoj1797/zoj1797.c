/*************************************************************************
	> File Name: zoj1797.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月02日 星期六 19时37分59秒
 ************************************************************************/

#include<stdio.h>

int gcd(int a,int b)
{
	return !b?a:gcd(b,a%b);
}
int lcm(int a,int b)
{
	return a / gcd(a,b) * b;
}
int main()
{
	int a,b;
	int cas;
	scanf("%d",&cas);
	int i;
	int n;
	while (cas--)
	{
		scanf("%d",&n);
		scanf("%d",&a);
		for (i = 0; i < n-1; i++)
		{
			scanf("%d",&b);
			a = lcm(a,b);
		}
		printf("%d\n",a);
	}
	return 0;
}
