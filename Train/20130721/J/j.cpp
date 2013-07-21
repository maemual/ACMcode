/*************************************************************************
	> File Name: j.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年07月21日 星期日 09时22分40秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<string>
#include<string.h>
using namespace std;

#define MAX_LEN 1005
int mk[MAX_LEN][MAX_LEN];
int nm[MAX_LEN][MAX_LEN];
int N[MAX_LEN];
int M[MAX_LEN];
char st1[10], st2[10];
int main()
{
	int n, m, k;
	int p;
	int x, y;
	while (1){
		scanf("%d %d %d", &n, &m, &k);
		if (n == 0 && m == 0 && k == 0)
			break;
		for (int i = 0; i < m; i++)
			M[i] = k;
		memset(N, 0, sizeof(N));
		memset(mk, 0, sizeof(mk));
		memset(nm, 0, sizeof(nm));
		scanf("%d", &p);
		while (p--){
			scanf("%s%d%s%d", st1, &x, st2, &y);
			x--;y--;
			if (!strcmp(st1,"clothes")){
				nm[x][y] = 1;
			}else{
				mk[x][y] = 1;
			}
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < k; j++){
				if (mk[i][j] == 1){
					M[i]--;
				}
			}
		}
		int sum = 0;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < m; j++){
				if (nm[i][j] == 0){
					N[i] += M[j];
				}
			}
			sum += N[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}
