/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月02日 星期二 22时52分27秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	int left,right;
	int ans = 0;
	int num = 0;
	for (int i = 0; i < n; i++){
		scanf("%d %d",&left,&right);
		num += right - left + 1;
	}
	if (num % k != 0){
		ans += (num / k + 1) * k - num;
	}

	printf("%d\n",ans);
	return 0;
}
