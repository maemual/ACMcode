/*************************************************************************
	> File Name: zoj1688.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月09日 星期二 14时39分52秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define MAX_LEN 30
#define eps 1e-6

int n;
typedef struct node{
	double x, y, z;
}node;
node point[MAX_LEN + 5];

double getDis(double x, double y, double z, int k){
	return sqrt((x - point[k].x) * (x - point[k].x) + (y - point[k].y) * (y - point[k].y) + (z - point[k].z) * (z - point[k].z));
}
int getDir(double x, double y, double z){
	double mmax = -1;
	int res;
	for (int i = 0; i < n; i++){
		double dis = (x - point[i].x) * (x - point[i].x) + (y - point[i].y) * (y - point[i].y) + (z - point[i].z) * (z - point[i].z);
		if (dis > mmax){
			mmax = dis;
			res = i;
		}
	}
	return res;
}
int main()
{
	while (scanf("%d", &n) && n){
		for (int i = 0; i < n; i++)
			scanf("%lf %lf %lf", &point[i].x, &point[i].y, &point[i].z);
		double delta = 200;
		double x, y, z;
		x = y = z = 0.0;
		double mmin = 1e50;
		while (delta > eps){
			int dir = getDir(x, y, z);
			double dis = getDis(x, y, z, dir);
			if (dis < mmin) mmin = dis;
			x += (point[dir].x - x) / dis * delta;
			y += (point[dir].y - y) / dis * delta;
			z += (point[dir].z - z) / dis * delta;
			delta *= 0.985;
		}
		printf("%.5f\n", mmin);
	}
	return 0;
}
