/*************************************************************************
	> File Name: c.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月02日 星期二 23时47分37秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	if (n < k){
		cout << "-1" << endl;
		return 0;
	}
	if (n != 1 && k == 1){
		cout << "-1" << endl;
		return 0;
	}
	char ch = 'c';
	for (int i = 1; i <= n; i++){
		if (i > n - k + 2){
			printf("%c",ch++);
		}else{
			if (i % 2 == 1)
				printf("a");
			else
				printf("b");
		}
	}
	cout << endl;
	return 0;
}
