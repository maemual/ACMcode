/*************************************************************************
	> File Name: poj1319.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月10日 星期三 10时06分23秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<stdlib.h>
using namespace std;

const double hight = sqrt(3) / 2;
int sp(double x, double y){
	int cnt = 0;
	int xx = (int)x;
	if (y > 1){
		cnt += xx;
		y -= 1;
	}
	if (x - xx >= 0.5){
		cnt += floor(y / hight) * xx; 
	}else{
		int f = floor(y / hight);
		if (f % 2 == 1){
			cnt += f * (xx - 1) + f / 2;
		}else{
			cnt += f / 2 * (2 * xx - 1);
		}
	}
	return cnt;
}
int main()
{
	double x, y;
	while (scanf("%lf %lf", &x, &y) != EOF){
		int grid = (int)x * (int) y;
		int skew = max(sp(x, y), sp(y, x));
		if (grid >= skew)
			printf("%d grid\n", grid);
		else
			printf("%d skew\n", skew);
	}
	return 0;
}
