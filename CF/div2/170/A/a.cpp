/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年02月28日 星期四 23时30分07秒
 ************************************************************************/

#include<iostream>
#include<cstdio> 
using namespace std;

const int MAX_LEN = 100;
int a[MAX_LEN+5];
int main()
{
	int n;
	int sum = 0;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&a[i]);
		sum += a[i];
	}
	int tmp = 0;
	int s,t;
	scanf("%d %d",&s,&t);
	if (t >= s) {
		for (int i = s; i < t; i++)
			tmp += a[i];
		if (tmp > sum - tmp)
			printf("%d\n",sum - tmp);
		else
			printf("%d\n",tmp);
	}else{
		for (int i = t; i < s; i++)
			tmp += a[i];
		if (tmp > sum - tmp)
			printf("%d\n",sum - tmp);
		else
			printf("%d\n",tmp);
	}
	return 0;
}
