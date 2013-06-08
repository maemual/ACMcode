/*************************************************************************
	> File Name: h.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月31日 星期日 12时55分21秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,k;
	double w;
	while(scanf("%d%lf%d",&n,&w,&k)!=EOF)
	{
		n=n+2;
		double sum=0;
		sum = (n-(int)(n/k))*w;
		sum *= 1000;
		sum += 5;
		sum /= 1000;
		printf("%.2f\n",sum / 2);
	}
	return 0;
}
