/*
ID: maemual
PROB: transform
LANG: C++
*/

#include<iostream>
#include<cstdio>
using namespace std;

#define MAX_LEN 10
int n;
char from[MAX_LEN+5][MAX_LEN+5], to[MAX_LEN+5][MAX_LEN+5], tmp[MAX_LEN+5][MAX_LEN+5], tmp2[MAX_LEN+5][MAX_LEN+5];
bool isOk(){
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (tmp[i][j] != to[i][j])
				return false;
		}
	}
	return true;
}
int main()
{
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			from[i][j] = getchar();
		}
		getchar();
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			to[i][j] = getchar();
		}
		getchar();
	}
	//1
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp[j][n - i - 1] = from[i][j];
		}
	}
	if (isOk()){
		printf("1\n");
		return 0;
	}
	//2
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp[n-i-1][n-j-1] = from[i][j];
		}
	}
	if (isOk()){
		printf("2\n");
		return 0;
	}
	//3
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp[n - j - 1][i] = from[i][j];
		}
	}
	if (isOk()){
		printf("3\n");
		return 0;
	}
	//4
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp[i][n - j - 1] = from[i][j];
		}
	}
	if (isOk()){
		printf("4\n");
		return 0;
	}
	//5
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp2[i][n - j - 1] = from[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp[j][n - i - 1] = tmp2[i][j];
		}
	}	
	if (isOk()){
		printf("5\n");
		return 0;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp[n - i - 1][n-j-1] = tmp2[i][j];
		}
	}
	if (isOk()){
		printf("5\n");
		return 0;
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp[n - j - 1][i] = tmp2[i][j];
		}
	}
	if (isOk()){
		printf("5\n");
		return 0;
	}
	//6
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			tmp[i][j] = from[i][j];
		}
	}
	if (isOk()){
		printf("6\n");
		return 0;
	}
	printf("7\n");
	return 0;
}
