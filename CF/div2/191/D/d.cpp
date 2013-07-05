/*************************************************************************
	> File Name: d.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月04日 星期四 21时56分00秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<stdio.h>
#include<string>
using namespace std;
#define MAX_LEN 505
int arr[MAX_LEN][MAX_LEN];
char str[5000];
bool pos(int i, int j){
	if (arr[i-1][j] == 1 || arr[i][j-1] == 1 || arr[i+1][j] == 1 || arr[i][j+1] == 1)
		return true;
	return false;
}
string ans;
int main()
{
	ans = "";
	int n,m;
	scanf("%d %d", &n, &m);
	memset(arr, -1, sizeof(arr));
	char ch;
	int cnt = 0;
	for (int i = 1; i <= n; i++){
		getchar();
		for (int j = 1; j <= m; j++){
			ch = getchar();
			if (ch == '.'){
				arr[i][j] = 0;
				//cnt++;
			}
		}
	}
	//printf("%d\n", 3 * cnt - 1);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (arr[i][j] == 0){
				arr[i][j] = 1;
				sprintf(str, "B %d %d\n", i, j);
				ans += str;
				cnt++;
			}
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (arr[i][j] == 1 && pos(i, j)){
				sprintf(str, "D %d %d\n", i, j);
				ans += str;
				//arr[i][j] = 0;
				cnt++;
				sprintf(str,"R %d %d\n", i, j);
				ans += str;
				arr[i][j] = 2;
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	cout << ans;
	return 0;
}
