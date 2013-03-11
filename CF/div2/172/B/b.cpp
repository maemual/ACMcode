/*************************************************************************
	> File Name: b.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年03月10日 星期日 23时44分33秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int main()
{
	int x,y,n;
	cin >> x >> y >> n;
	double s = x * 1.0 / y;
	double ans = 0;
	double min = 9999999999;
	int ansa,ansb;
	for (int b = n; b >= 1; b--)
	{
		for (int a = (int)(s*b+1); a >= (int)(s*b-1) && a >= 0; a--)
		{
			ans = a*1.0 / b;
			if (fabs(s - ans) <= min)
			{
				min = fabs(s - ans);
				ansa = a;
				ansb = b;
			}
		}
	}
	cout << ansa << '/' << ansb << endl;
	return 0;
}
