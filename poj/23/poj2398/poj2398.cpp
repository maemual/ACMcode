/*************************************************************************
	> File Name: poj2398.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月14日 星期日 09时42分54秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
using namespace std;

#define MAX_LEN 1005
struct point{
	int x, y;
	point(int _x, int _y):x(_x), y(_y){}
};
struct line{
	int x1, x2;
};
bool cmp(const line &l1, const line &l2){
	if (l1.x2 > l2.x2 || l1.x1 > l2. x1)
		return false;
	return true;
}
int xmult(point p0, point p1, point p2){
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
int main()
{
	int n, m, x1, y1, x2, y2;
	int upper[MAX_LEN], lower[MAX_LEN];
	line ll[MAX_LEN];
	int num[MAX_LEN];
	int ans[MAX_LEN];
	while (scanf("%d", &n) && n){
		scanf("%d %d %d %d %d", &m, &x1, &y1, &x2, &y2);
		for (int i = 0; i < n; i++){
			scanf("%d %d", &ll[i].x1, &ll[i].x2);
		}
		ll[n].x1 = x2;
		ll[n].x2 = x2;
		n++;
		sort(ll, ll + n, cmp);
		//cout << ll[0].x1 << endl;
		memset(num, 0, sizeof(num));
		int x, y;
		for (int i = 0; i < m; i++){
			scanf("%d %d", &x, &y);
			int left = 0, right = n;
			int mid;
			while (left < right){
				mid = (left + right) / 2;
				point p0(x, y), p1(ll[mid].x2, y2), p2(ll[mid].x1, y1);
				if (xmult(p0, p1, p2) > 0)
					right = mid;
				else
					left = mid + 1;
			}
			mid = (left + right) / 2;
			num[mid]++;
		}
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < MAX_LEN; i++){
			if (num[i])
				ans[num[i]]++;
		}
		printf("Box\n");
		for (int i = 0; i < MAX_LEN; i++)
			if (ans[i])
				printf("%d: %d\n", i, ans[i]);
	}
	return 0;
}
