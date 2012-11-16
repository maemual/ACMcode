#include <queue>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct node
{
    int pre, step, dir, f, pos, id;
    char x[10];
    bool operator <(const node &n) const
    {
        return n.f < f;
    }
    node(){dir = -1;}
    node(int u, int v, int w, int y, char t[])
    {
        pre = u;
        step = v;
        dir = w;
        pos = y;
        strcpy(x, t);
    }
}p[400000];
int fac[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
int dd[] = {-1, -3, 1, 3};
bool vis[400000];
char ans[]= "12345678x";
bool move[][4] = {{0,0,1,1}, {1,0,1,1}, {1,0,0,1}, {0,1,1,1}, {1,1,1,1}, {1,1,0,1}, {0,1,1,0}, {1,1,1,0}, {1,1,0,0}};
int hash(const node &t)  //将全排列转化为数字，序列值为0~n!-1，达到了完美的映射
{
    int h = 0;
    for(int i = 1; i < 9; i++)
    {
        int count = 0;
        for(int j = 0; j <i ; j++)
            if(t.x[j] > t.x[i]) count++;
        h += count * fac[i];
    }
    return h;
}
int h(const node &t)
{
    int sum = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
        {
            int k = i * 3 + j;
            if(t.x[k] == 'x') continue;
            sum += abs(i - (t.x[k] - '1') / 3) + abs(j - (t.x[k] - '1') % 3);
        }
    return sum;
}
void output(const node &n)
{
    char res[5000];
    int cnt = 0;
	node t = n;
    while(t.pre != -1)
    {
        if(t.dir == 0)
        res[cnt++] = 'l';
        else if(t.dir == 1)
        res[cnt++] = 'u';
        else if(t.dir == 2)
        res[cnt++] = 'r';
        else if(t.dir == 3)
        res[cnt++] = 'd';
        t = p[t.pre];
    }
    res[cnt] = '\0';
    reverse(res, res + cnt);
    printf("%s\n", res);
}
priority_queue<node>q;
int main()
{
    node tmp;
    for(int i = 0; i < 9; i++)
    {
        scanf("%s", &tmp.x[i]);
        if(tmp.x[i] == 'x') tmp.pos = i;
    }
    tmp.step = 0;
    tmp.pre = -1;
    tmp.f = tmp.step + h(tmp);
    tmp.id = hash(tmp);
    p[tmp.id] = tmp;
    q.push(tmp);
	memset(vis,0,sizeof(vis));
    vis[tmp.id] = true;
	bool flag = true;
    while(!q.empty())
    {
        node A = q.top();
        q.pop();
        if(strcmp(A.x,"12345678x") == 0) 
		{
			output(A); 
			flag = false;
			break;
		}
        for(int i = 0; i < 4; i++)
        {
            if(move[A.pos][i] == 0) continue;
            int xx = A.pos + dd[i];
            if(xx < 0 || xx >= 9) continue;
            char tx[10];
            strcpy(tx, A.x);
            swap(tx[xx], tx[A.pos]);
            node B(A.id, A.step + 1, i, xx, tx);
            B.id = hash(B);
            if(vis[B.id]) continue;
            vis[B.id] = true;
            B.f = h(B) + B.step;
            p[B.id] = B;
            q.push(B);
        }
    }
	if (flag)
	  printf("unsolvable\n");
    return 0;
}
