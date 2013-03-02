/*************************************************************************
	> File Name: zoj1629.c
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月02日 星期六 20时03分39秒
 ************************************************************************/

#include<stdio.h>

int main()
{
	int a[505];
	int i;
	a[1] = 1;
	for (i = 2; i <= 500; i++)
		a[i] = a[i-1] + i*(i+1) / 2 + i / 2 * (i - i / 2);
	int n;
	while (scanf("%d",&n) != EOF)
		printf("%d\n",a[n]);
	return 0;
}
