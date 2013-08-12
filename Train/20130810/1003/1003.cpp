#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

#define MAX_LEN 200
char mmap[MAX_LEN+5][MAX_LEN+5];
bool vis[4][1<<7][MAX_LEN+5][MAX_LEN+5];
int dx[] = {-1,1, 0,0};
int dy[] = { 0,0,-1,1};
int id[MAX_LEN+5][MAX_LEN+5];
int n, m;
int keys;
int full;
int start_x, start_y, end_x, end_y;
struct node{
    int step;
    int x, y;
    int dir;
    int key;
    node() {}
    node(int _x, int _y, int _step, int _key):x(_x), y(_y), step(_step), key(_key) {}
}next, now;
queue<node> que;
int next_step(node s, int dir, node &to){
    int next_x = s.x, next_y = s.y;
    to = s;
    to.step++;
    int cnt = 0;
    while (1){
        next_x = to.x + dx[to.dir];
        next_y = to.y + dy[to.dir];
        if (next_x < 0 || next_y < 0 || next_x > n || next_y > m) return -1;
        if (mmap[next_x][next_y] == 'X')
            return -1;
        switch(mmap[next_x][next_y]){
            case 'U':
                to.dir = 0;
                if (mmap[next_x+dx[to.dir]][next_y+dy[to.dir]] == '#')
                    return -1;
                break;
            case 'D':
                to.dir = 1;
                if (mmap[next_x+dx[to.dir]][next_y+dy[to.dir]] == '#')
                    return -1;
                break;
            case 'L':
                to.dir = 2;
                if (mmap[next_x+dx[to.dir]][next_y+dy[to.dir]] == '#')
                    return -1;
                break;
            case 'R':
                to.dir = 3;
                if (mmap[next_x+dx[to.dir]][next_y+dy[to.dir]] == '#')
                    return -1;
                break;
            default:break;
        }
        if (mmap[next_x][next_y] == '#'){
            if (to.x == s.x && to.y == s.y)
                return -1;
            if (vis[to.dir][to.key][to.x][to.y]) return -1;
            vis[to.dir][to.key][to.x][to.y] = true;
            return 0;
        }
        if (mmap[next_x][next_y] == 'E'){
            if (to.key == full)
                return 1;
        }
        if (mmap[next_x][next_y] == 'K'){
            to.key |= id[next_x][next_y];
        }
        to.x = next_x;
        to.y = next_y;
        cnt++;
        if (cnt > m * n)
            return -1;
    }
}
int bfs(){
    full = (1 << keys) - 1;
    int flag;//-1表示此路不通，0表示可以走，1表示到达终点
    now.step = 0;
    now.x = start_x;
    now.y = start_y;
    now.key = 0;
    for (int i = 0; i < 4; i++){
        now.dir = i;
        que.push(now);
        vis[i][0][now.x][now.y] = true;
    }
    while (!que.empty()){
        now = que.front();
        que.pop();
        for (int i = 0; i < 4; i++){
            //if (vis[i][now.key][now.x][now.y]) continue;
            //vis[i][now.key][now.x][now.y] = true;
            now.dir = i;
            flag = next_step(now, i, next);
            if (flag == -1) continue;
            if (flag == 1) return next.step;
            que.push(next);
        }
    }
    return -1;
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF){
        memset(vis, 0, sizeof(vis));
        memset(id, 0, sizeof(id));
        while (!que.empty()) que.pop();
        keys = 0;
        for (int i = 0; i < MAX_LEN; i++)
            for (int j = 0; j < MAX_LEN; j++)
                mmap[i][j] = 'X';
        start_x = start_y = end_x = end_y = 0;
        for (int i = 1; i <= n; i++){
            getchar();
            for (int j = 1; j <= m; j++){
                mmap[i][j] = getchar();
                if(mmap[i][j] == 'S')
                    start_x = i, start_y = j;
                if (mmap[i][j] == 'E')
                    end_x = i, end_y = j;
                if (mmap[i][j] == 'K'){
                    id[i][j] = 1<<keys;
                    keys++;
                }
            }
        }
        if (start_x == 0 || start_y == 0 || end_x == 0 || end_y == 0)
            printf("-1\n");
        else
            printf("%d\n", bfs());
    }
    return 0;
}
