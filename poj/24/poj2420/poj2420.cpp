/*************************************************************************
	> File Name: poj2420.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月09日 星期二 11时10分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<time.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

#define MAX_LEN 100
#define MAX_P 30
#define MAX_L 50
#define eps 1e-2
#define PI acos(-1.0)
int N;
typedef struct node{
	int x, y;
}node;
typedef struct Node{
	double dis;
	int x, y;
}Node;

node point[MAX_LEN + 5];
Node ans[MAX_P];

double getDis(double x, double y){
	double res = 0;
	for (int i = 0; i < N; i++){
		res += sqrt((x - point[i].x)*(x - point[i].x) + (y - point[i].y)*(y - point[i].y));
	}
	return res;
}
int main()
{
	while (scanf("%d", &N) != EOF){
		for (int i = 0; i < N; i++)
			scanf("%d %d", &point[i].x, &point[i].y);
		srand((unsigned)time(NULL));
		for (int i = 0; i < MAX_P; i++){
			ans[i].x = rand() % 10000 + 1;
			ans[i].y = rand() % 10000 + 1;
			ans[i].dis = getDis(ans[i].x, ans[i].y);
		}
		double delta = 10000 * 1.0 / sqrt(N*1.0);
		while (delta > eps){
			for (int i = 0; i < MAX_P; i++){
				for (int j = 0; j < MAX_L; j++){
					double rad = rand();
					double next_x = ans[i].x + delta * cos(rad);
					double next_y = ans[i].y + delta * sin(rad);
					if (next_x < 0 || next_y < 0 || next_x > 10000 || next_y > 10000) continue;
					double sumDis = getDis(next_x, next_y);
					if (sumDis < ans[i].dis)
						ans[i].dis = sumDis;
				}
			}
			delta *= 0.9;
		}
		double mmin = ans[0].dis;
		for (int i = 1; i < MAX_P; i++){
			if (mmin > ans[i].dis)
				mmin = ans[i].dis;
		}
		printf("%.0f\n", mmin);
	}
	return 0;
}
