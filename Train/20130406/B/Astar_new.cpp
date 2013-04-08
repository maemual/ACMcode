/*************************************************************************
	> File Name: Astar_new.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月08日 星期一 20时27分29秒
 ************************************************************************/

#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

typedef struct node{
	int step;
	int state;
	int f;
	bool operator<(const node &n) const{
		return n.f < f;
	}
}node;
int n,m;
bool vis[60466177];
int target[20],source[20];
int start,ans;
priority_queue<node> que;
int tra[20][20];
int h(int arr[]){
	int sum = 0;
	for (int i = 1; i <= n; i++){
		if (arr[i] < target[i])
			sum += target[i] - arr[i];
		else if (arr[i] > target[i])
			sum += 6 - arr[i] + target[i];
	}
	return sum;
}
int hashValue(int arr[]){
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum = (sum << 2) + (sum << 1) + arr[i];
	return sum;
}
void hashArr(int val, int arr[]){
	for (int i = 1; i <= n; i++){
		arr[n - i + 1] = val % 6;
		val /= 6;
	}
}
int Astar(){
	int state;
	int tmp[20];
	node tt,tp;
	tt.step = 0;
	tt.f = h(source);
	tt.state = start;
	que.push(tt);

	while (!que.empty()){
		tt = que.top();
		que.pop();
		for (int i = 1; i <= n; i++){
			state = tt.state;
			hashArr(state, tmp);
			for (int j = 1; j <= n; j++){
				tmp[j] += tra[i][j];
				if (tmp[j] == 6)
					tmp[j] = 0;
			}
			state = hashValue(tmp);
			if (state == ans){
				return tt.step + 1;
			}
			if (!vis[state]){
				vis[state] = true;
				tp.state = state;
				tp.step = tt.step + 1;
				tp.f = tp.step + h(tmp);
				que.push(tp);
			}
		}
	}
	return -1;
}
int main()
{
	int cas;
	scanf("%d", &cas);
	int x,y;
	while (cas--){
		scanf("%d %d", &n, &m);
		start = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", &source[i]);
			start = start * 6 + (--source[i]);
		}
		ans = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d", &target[i]);
			ans = ans * 6 + (--target[i]);
		}
		memset(tra, 0, sizeof(tra));
		memset(vis, false, sizeof(vis));
		while(!que.empty()) que.pop();
		for (int i = 1; i <= n; i++)
			tra[i][i] = 1;
		for (int i = 1; i <= m; i++){
			scanf("%d %d", &x, &y);
			tra[x][y] = 1;
		}
		printf("%d\n", Astar());
	}
	return 0;
}
