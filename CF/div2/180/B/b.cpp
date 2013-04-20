/*************************************************************************
	> File Name: b.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月20日 星期六 00时10分56秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int t;
	int sx,sy,ex,ey;
	int east,west,north,south;
	char ch;
	scanf("%d %d %d %d %d",&t, &sx, &sy, &ex, &ey);
	getchar();
	east = west = north = south = 0;
	int ans = 0;
	bool flag = false;
	for (int i = 1; i <= t; i++){
		ch = getchar();
		if (flag)
			continue;
		if (ch == 'E'){
			if (sx < ex)
				sx++;
		}else if (ch == 'S'){
			if (sy > ey)
				sy--;
		}else if (ch == 'W'){
			if (sx > ex)
				sx--;
		}else {
			if (sy < ey)
				sy++;
		}
		if (sx == ex && sy == ey){
			ans = i;
			flag = true;
		}
	}
	if (flag)
		printf("%d\n", ans);
	else
		printf("-1\n");
	return 0;
}
