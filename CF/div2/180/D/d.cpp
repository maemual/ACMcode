/*************************************************************************
	> File Name: d.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月20日 星期六 19时27分14秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define MAX_LEN 100005
int a[MAX_LEN],b[MAX_LEN];
int main()
{
	int n,m,x;
	scanf("%d %d %d", &n, &m, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &b[i]);
	sort(a, a + n);
	sort(b, b + m);
	bool flag = true;
	int k = 0;
	for (int i = 0; i < n; i++){
		while (k < m -1 && a[i] > b[k]) ++k;
		if (a[i] > b[k]){
			flag = false;
			break;
		}
		++k;
	}
	if (flag)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
