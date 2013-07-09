/*************************************************************************
	> File Name: poj1379.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月09日 星期二 08时22分32秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<math.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

#define MAX_LEN 1100
#define MAX_P 30
#define MAX_L 50
#define eps 1e-2
typedef struct node{
	double x,y;
}node;
typedef struct Node{
	double dis, x, y;
}Node;
node hole[MAX_LEN + 5];
Node ans[100];
int m;

double min_dis(double x, double y){
	double mmin = 1e20;
	for (int i = 0; i < m; i++){
		double dis = (x - hole[i].x) * (x - hole[i].x) + (y - hole[i].y) * (y - hole[i].y);
		if (dis < mmin)
			mmin = dis;
	}
	return mmin;
}
int main()
{
	int T;
	int XX, YY;
	scanf("%d", &T);
	while (T--){
		scanf("%d %d %d", &XX, &YY, &m);
		for (int i = 0; i < m; i++)
			scanf("%lf %lf", &hole[i].x, &hole[i].y);
		srand((unsigned)time(NULL));
		for (int i = 0; i < MAX_P; i++){
			ans[i].x = rand() % XX + 1;
			ans[i].y = rand() % YY + 1;
			ans[i].dis = min_dis(ans[i].x, ans[i].y);
		}
		double delta = (XX > YY ? XX : YY) / sqrt(m * 1.0) + 1;
		double PI = asin(1.0)*2.0;
		while (delta > eps){
			for (int i = 0; i < MAX_P; i++){
				for (int j = 0; j < MAX_L; j++){
					double rad = (rand() % 101) / 100.0 * 2.0 * PI;
					double next_x = ans[i].x + delta * cos(rad);
					double next_y = ans[i].y + delta * sin(rad);
					if (next_x < 0 || next_y < 0 || next_x > XX || next_y > YY) continue;
					double mmin = min_dis(next_x, next_y);
					if (mmin > ans[i].dis){
						ans[i].dis = mmin;
						ans[i].x = next_x;
						ans[i].y = next_y;
					}
				}
			}
			delta *= 0.8;
		}
		double mmax = ans[0].dis;
		int k = 0;
		for (int i = 1; i < MAX_P; i++){
			if (ans[i].dis > mmax){
				mmax = ans[i].dis;
				k = i;
			}
		}
		printf("The safest point is (%.1lf, %.1lf).\n", ans[k].x, ans[k].y);
	}
	return 0;
}
