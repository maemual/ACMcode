/*************************************************************************
	> File Name: h.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月26日 星期五 15时20分21秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int T;
	int x, y;
	double p, q;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d %lf %lf", &x, &y, &p, &q);
		double tiger = q * p * (x + y) + (1 - q) * x;
		double wolf = (1 - q) * p * (x + y) + q * y;
		if (tiger > wolf)
			printf("tiger %.4lf\n", tiger);
		else
			printf("wolf %.4lf\n", wolf);
	}
	return 0;
}
