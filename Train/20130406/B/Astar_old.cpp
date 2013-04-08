/*************************************************************************
	> File Name: test.cpp
	> Author: maemual
	> Mail: maemual@gmail.com 
	> Created Time: 2013年04月04日 星期四 20时02分43秒
 ************************************************************************/

#include<iostream>
#include<string.h>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;

typedef struct node{
	int step;
	long long state;
	int f;
	bool operator<(const node &n) const{
		return n.f < f;
	}
}node;
bool vis[66666667];
int target[20];
int source[20];
int n,m;
int cnt;
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
priority_queue<node> que;
map<long long,int> mmap;
long long ans;
long long ss[20];
long long pp[20];
long long start;
int Astar()
{
	if (n > 8)
		mmap.clear();
	long long state;
	int tmp[20];
	node tt,tp;
	tt.step = 0;
	tt.f = h(source);
	tt.state = start;
	que.push(tt);
	mmap.insert(pair<long long, int>(start,1));
	map<long long,int>::iterator it;
	while (!que.empty()){
		tt = que.top();
		que.pop();
		for (int i = 1; i <= n; i++){
			state = tt.state + pp[i];
			for (int j = n; j >= 1; j--){
				tmp[j] = state % 10;
				state /= 10;
				if (tmp[j] > 6)
					tmp[j] = 1;
			}
			state = 0;
			for (int j = 1; j <= n; j++)
				state = state * 10 + tmp[j];
			if (state == ans){
				return tt.step + 1;
			}
			if (n > 8){
				it = mmap.find(state);
				if (it == mmap.end()){
					mmap.insert(pair<long long,int>(state,1));
					node ttp;
					ttp.state = state;
					ttp.step = tt.step + 1;
					ttp.f = ttp.step + h(tmp);
					que.push(ttp);
				}
			}else{
				if (!vis[state]){
					vis[state] = true;
					node ttp;
					ttp.state = state;
					ttp.step = tt.step + 1;
					ttp.f = ttp.step + h(tmp);
					que.push(ttp);
				}
			}
		}
	}
	return -1;
}
int main()
{
	int cas;
	scanf("%d",&cas);
	int x,y;
	while (cas--){
		scanf("%d %d",&n,&m);
		start = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d",&source[i]);
			start = start * 10 + source[i];
		}
		ans = 0;
		for (int i = 1; i <= n; i++){
			scanf("%d",&x);
			ans = ans * 10 + x;
		}
		long long xx = ans;
		for (int j = n; j >= 1; j--){
			target[j] = xx % 10;
			xx /= 10;
		}
		xx = 1;
		for (int i = n; i >= 1; i--){
			ss[i] = xx;
			xx *= 10;
		}
		for (int i = 1; i <= n; i++)
			pp[i] = ss[i];
		for (int i = 1; i <= m; i++){
			scanf("%d %d", &x, &y);
			pp[x] += ss[y];
		}
		if (n <=8){
			memset(vis,false,sizeof(vis));
			vis[start] = true;
		}
		while (!que.empty()) que.pop();
		printf("%d\n",Astar());
	}
	return 0;
}
