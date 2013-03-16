/*************************************************************************
	> File Name: b.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月16日 星期六 09时45分43秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int a,g;
	int suma,sumg;
	int n;
	suma = sumg = 0;

	scanf("%d",&n);
	int flag = 0;
	while (n--)
	{
		scanf("%d %d",&a,&g);
		if (abs(suma + a - sumg) <= 500){
			printf("A");
			suma += a;
		}else if (abs(sumg + g - suma) <= 500){
			printf("G");
			sumg += g;
		}else{
			flag = 1;
			break;
		}
	}
	if (flag)
		printf("-1\n");
	else
		printf("\n");
	return 0;
}
