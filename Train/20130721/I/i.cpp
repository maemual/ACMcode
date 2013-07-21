/*************************************************************************
	> File Name: i.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月21日 星期日 08时32分50秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n;
	int x, sum;
	while (scanf("%d", &n) && n){
		sum = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &x);
			sum += x * x;
		}
		printf("%d\n", sum);
	}
	return 0;
}
