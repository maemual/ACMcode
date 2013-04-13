/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月11日 星期四 23时29分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int n;
	int arr[105];
	int vis[1005];
	scanf("%d",&n);
	memset(vis,0,sizeof(vis));
	int x;
	int max = 0;
	for (int i = 0; i < n; i++){
		scanf("%d",&x);
		vis[x]++;
		if (max < vis[x])
			max = vis[x];
	}
	//printf("%d\n",min);
	if (n % 2 == 1){
		if (max > n/2 + 1)
			printf("NO\n");
		else
			printf("YES\n");
	}else{
		if (max > n / 2)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
