/*************************************************************************
	> File Name: c.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月17日 星期日 13时47分53秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int arr[500];
int ss[100000005];
int main()
{
	int m;
	int sum;
	sum = 0;
	int	k = 1;
	int k3 = 8;
	for (int i = 1; i <= 100000000; i++)
	{
		if (k3 == i){
			k++;
			k3 = (k + 1) * (k + 1) * (k + 1);
		}
		if (i % k == 0)
			sum++;
		ss[i] = sum;
	}
	while (1){
		scanf("%d",&m);
		if (m == 0)
			break;
		if (m <= 100000000){
			printf("%.2lf\n",(ss[m] * 5 - (m - ss[m]))*1.0 / m * 100);
		}else{
			sum = 0;
			k = 1;
			k3 = 8;
			for (int i = 1; i <= m; i++)
			{
				if (k3 == i){
					k++;
					k3 = (k + 1) * (k + 1) * (k + 1);
				}
				if (i % k == 0)
					sum++;
			}
			//printf("%d\n",sum);
			printf("%.2lf\n",(sum * 5 - (m - sum))*1.0 / m * 100);
		}
	}
	return 0;
}
