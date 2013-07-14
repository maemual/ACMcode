/*************************************************************************
	> File Name: poj2318.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月13日 星期六 16时45分47秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

#define MAX_LEN 5005
struct point{
	int x, y;
	point(int _x, int _y):x(_x), y(_y){}
};
int xmult(point p0, point p1, point p2){
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
int main()
{
	int n,m,x1,x2,y1,y2;
	int upper[MAX_LEN], lower[MAX_LEN];
	int box[MAX_LEN];
	int k = 0;
	while (scanf("%d", &n) && n){
		if (k == 1)
			printf("\n");
		k = 1;
		scanf("%d %d %d %d %d", &m, &x1, &y1, &x2, &y2);
		//upper[0] = lower[0] = x1;
		for (int i = 0; i < n; i++){
			scanf("%d %d", &upper[i], &lower[i]);		
		}
		upper[n] = lower[n] = x2;
		int x,y;
		memset(box, 0, sizeof(box));
		for (int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			int left = 0, right = n;
			int mid;
			while (left < right){
				mid = (left + right) / 2;
				point p0(x, y), p1(upper[mid], y1), p2(lower[mid], y2);
				if (xmult(p0, p2, p1) > 0)
					right = mid;
				else
					left = mid + 1;
			}
			mid = (left + right) / 2;
			box[mid]++;
		}
		for (int i = 0; i <= n; i++)
			printf("%d: %d\n", i, box[i]);
	}
	return 0;
}
