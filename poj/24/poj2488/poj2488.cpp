#include<iostream>
#include<stdio.h>

using namespace std;
const int Max = 25;

bool visit[Max][Max], output;
int visit_num, p, q;      // visit_num记录要走的点数。
char path[2 * Max];       // path[]记录路径。
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};   // 字典序。

void dfs(int depth, int x, int y){
	if(depth == visit_num){
		for(int i = 0; i < 2 * depth; i ++)
			cout << path[i];
		cout << endl << endl;
		output = true;
		return;
	}
	for(int i = 0; i < 8 && output == false; i ++){
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if(new_x > 0 && new_y > 0 && new_x <= q && new_y <= p && visit[new_y][new_x] == false){
			visit[new_y][new_x] = true;
			path[2 * depth ] = 'A' + new_x - 1;
			path[2 * depth + 1] = '1' + new_y - 1;
			dfs(depth + 1, new_x, new_y);
			visit[new_y][new_x] = false;
		}
	}
}

int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i ++){
		cin >> p >> q;
		cout << "Scenario #" << i << ':' << endl;

		for(int y = 1; y <= p; y ++)
			for(int x = 1; x <= q; x ++)
				visit[y][x] = false;
		visit_num = p * q;
		output = false;   
		visit[1][1] = true;
		path[0] = 'A';
		path[1] = '1';   // 初始化，设A1为首位置（证明如果能走完的话，必存在一条起点为A1的路径）
		dfs(1,1,1);

		if(output == false)
			cout << "impossible" << endl << endl;
	}
	return 0;
}
