/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月04日 星期一 23时22分12秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int arr[205][205];
int main()
{
	memset(arr,0,sizeof(arr));
	int x,y;
	scanf("%d %d",&x,&y);

	int px = 101,py = 101;
	arr[100][100] = 0;
	arr[101][100] = 0;
	arr[101][101] = 1;
	int ans = 2;
	int p = 2;
	int flag = 0;
	while (1)
	{
//		ans++;
		for (int i = 0; i < p; i++)
		{
			px--;
			if (px < 0)
			{
				flag = 1;
				break;
			}
			arr[px][py] = ans;
		}
		if (flag)
			break;
		ans++;
		for (int i = 0; i < p; i++)
		{
			py--;
			if (py < 0)
			{
				flag = 1;
				break;
			}
			arr[px][py] = ans;
		}
		if (flag)
			break;
		ans++;
		p++;
		for (int i = 0; i < p; i++)
		{
			px++;
			if (px > 200)
			{
				flag = 1;
				break;
			}
			arr[px][py] = ans;
		}
		if (flag)
			break;
		ans++;
		for (int i = 0; i < p; i++)
		{
			py++;
			if (py > 200)
			{
				flag = 1;
				break;
			}
			arr[px][py] = ans;
		}
		if (flag)
			break;
		ans++;
		p++;
	}
	printf("%d\n",arr[x+100][y+100]);
	return 0;
}
