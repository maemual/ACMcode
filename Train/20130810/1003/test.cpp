#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

struct Point {
	int x, y, step, dir, now;
	Point() {}
	Point(int x, int y, int step, int dir, int now) : x(x), y(y), step(step), dir(dir), now(now) {}
}cur;

queue<Point> q;
bool vis[4][1<<7][202][202];
int n, m, key, id[202][202], mp[333];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
char s[202][202];
int full ;

int bfs() {
	full = (1<<key)-1;
	while(!q.empty()) {
		cur = q.front();
		q.pop();
		int x = cur.x, y = cur.y, dir = cur.dir, step = cur.step, now = cur.now;
		int xx = x + dx[dir], yy = y + dy[dir];
		if(xx < 1 || yy < 1 || xx > n || yy > m)	continue;
// 模拟走的路程，细节要注意
		while(s[xx][yy] != '#') {
			x = xx; y = yy;
			if(s[xx][yy] == 'K') {
				now |= id[xx][yy];
			}
			if(s[xx][yy] == 'E') {
				if(now == full)	 return step;
			}
			if(mp[s[xx][yy]] >= 0) {
				dir = mp[s[xx][yy]];
				if(vis[dir][now][xx][yy])   break;
				vis[dir][now][xx][yy] = 1;
			}
			xx += dx[dir]; yy += dy[dir];
			if(xx < 1 || yy < 1 || xx > n || yy > m)	break;
		}
		if(xx < 1 || yy < 1 || xx > n || yy > m)	continue;
		if(s[xx][yy] == '#' && mp[s[x][y]] == -1) {
			for(int i = 0;i < 4; i++) if(i != dir) {
                if(vis[i][now][x][y]) continue;
                vis[i][now][x][y] = 1;
				xx = x+dx[i];yy = y + dy[i];
				if(s[xx][yy] == '#')	continue;
				cur = Point(x, y, step+1, i, now);
				q.push(cur);
			}
		}
	}
	return -1;
}

int main(){
	memset(mp, -1, sizeof(mp));
	mp['D'] = 0; mp['U'] = 1; mp['R'] = 2 ; mp['L'] = 3;
	int i, j, x, y, k, l;
	while(scanf("%d%d", &n, &m) != -1) {
		for(i = 1;i <= n; i++)
			scanf("%s", s[i]+1);
        key = 0;
		for(i = 1;i <= n; i++) {
			for(j = 1;j <= m; j++)
				if(s[i][j] == 'K')	{
					id[i][j] = 1<<key;
					key++;
				}
				else if(s[i][j] == 'S')
					x = i, y = j;
		}
        memset(vis ,0, sizeof(vis));
		while(!q.empty())	q.pop();
		for(i = 0;i < 4; i++) {
			cur = Point(x, y, 1, i, 0);
            vis[i][0][x][y] = 1;
			q.push(cur);
		}
		printf("%d\n", bfs());
	}
	return 0;
}
