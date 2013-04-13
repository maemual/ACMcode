/*************************************************************************
	> File Name: a.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月13日 星期六 15时37分17秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
using namespace std;

char map[10][10];
bool xwon(int px,int py)
{
	map[px][py] = 'X';
	bool flag;
	for (int i = 0; i < 4; i++){
		flag = true;
		for (int j = 0; j < 4; j++){
			if (map[i][j] != 'X')
				flag = false;
		}
		if (flag)
			return true;
	}
	for (int i = 0; i < 4; i++){
		flag = true;
		for (int j = 0; j < 4; j++){
			if (map[j][i] != 'X')
				flag = false;
		}
		if (flag)
			return true;
	}
	flag = true;
	for (int i = 0; i < 4; i++){
		if (map[i][i] != 'X')
			flag = false;
	}
	if (flag)
		return true;
	flag = true;
	for (int i = 0; i < 4; i++){
		if (map[i][4-i] != 'X')
			flag = false;
	}
	if (flag)
		return true;
	return false;
}
bool owon(int px,int py)
{
	map[px][py] = 'O';
	bool flag;
	for (int i = 0; i < 4; i++){
		flag = true;
		for (int j = 0; j < 4; j++){
			if (map[i][j] != 'O')
				flag = false;
		}
		if (flag)
			return true;
	}

	for (int i = 0; i < 4; i++){
		flag = true;
		for (int j = 0; j < 4; j++){
			if (map[j][i] != 'O')
				flag = false;
		}
		if (flag)
			return true;
	}

	flag = true;
	for (int i = 0; i < 4; i++){
		if (map[i][i] != 'O')
			flag = false;
	}
	if (flag)
		return true;

	flag = true;
	for (int i = 0; i < 4; i++){
		if (map[i][3-i] != 'O')
			flag = false;
	}
	if (flag)
		return true;

	return false;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	int posx,posy;
	int cnt;
	getchar();
	for (int k = 1; k <= cas; k++){
		cnt = 0;
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 4; j++){
				scanf("%c",&map[i][j]);
				if (map[i][j] != '.')
					cnt++;
				if (map[i][j] == 'T'){
					posx = i;
					posy = j;
				}
			}
			getchar();
		}
		getchar();
		printf("Case #%d: ",k);
		if (xwon(posx,posy))
			printf("X won\n");
		else if (owon(posx,posy))
			printf("O won\n");
		else if (cnt == 16)
			printf("Draw\n");
		else
			printf("Game has not completed\n");
	}
	return 0;
}
