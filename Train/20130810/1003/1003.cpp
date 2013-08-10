#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define MAX_LEN 200
char mmap[MAX_LEN+5][MAX_LEN+5];
int vis[MAX_LEN+5][MAX_LEN+5];
int dx[] = {-1,1, 0,0};
int dy[] = { 0,0,-1,1};
int n, m;
int keys;
int start_x, start_y, end_x, end_y;
struct node{
    int step;
    int x, y;
    int kx[7];
    int ky[7];
    int key;
}que[100000], now;
int next_step(node s, int dir, node &to){
    int next_x = s.x, next_y = s.y;
    to = s;
    to.step++;
    int cnt = 0;
    while (1){
        next_x = to.x + dx[dir];
        next_y = to.y + dy[dir];
        if (mmap[next_x][next_y] == 'X')
            return -1;
        switch(mmap[next_x][next_y]){
            case 'U': dir = 0;break;
            case 'D': dir = 1;break;
            case 'L': dir = 2;break;
            case 'R': dir = 3;break;
            default:break;
        }
        if (mmap[next_x][next_y] == '#'){
            return 0;
        }
        if (mmap[next_x][next_y] == 'E'){
            if (to.key >= keys)
                return 1;
        }
        if (mmap[next_x][next_y] == 'K'){
            int flag = 0;
            for (int i = 0; i < to.key; i++){
                if (to.kx[i] == next_x && to.ky[i] == next_y){
                    flag = 1;
                    break;
                }
            }
            if (flag == 0){
                to.kx[to.key] = next_x;
                to.ky[to.key] = next_y;
                to.key++;
            }
        }
        to.x = next_x;
        to.y = next_y;
        cnt++;
        if (cnt > m * n)
            return -1;
    }
}
int bfs(){
    int head = 0, tail = 0;
    int flag;//-1表示此路不通，0表示可以走，1表示到达终点
    que[head].step = 0;
    que[head].x = start_x;
    que[head].y = start_y;
    que[head].key = 0;
    tail++;
    while (head < tail){
        for (int i = 0; i < 4; i++){
            flag = next_step(que[head], i, now);
            if (flag == -1) continue;
            if (flag == 1) return now.step;
            que[tail++] = now;
        }
        head++;
    }
    return -1;
}
int main()
{
    while (scanf("%d %d", &n, &m) != EOF){
        memset(vis, 0, sizeof(vis));
        memset(que, 0, sizeof(que));
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
                if (mmap[i][j] == 'K')
                    keys++;
            }
        }
        if (start_x == 0 || start_y == 0 || end_x == 0 || end_y == 0)
            printf("-1\n");
        else
            printf("%d\n", bfs());
    }
    return 0;
}
