#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 15

int n, m;
char map[maxn][maxn];
int vis[5];
int dir[4][2] =
{
{ 0, 1 },
{ 1, 0 },
{ 1, 1 },
{ 1, -1 } };

void input()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", map[i]);
}

bool ok(int x, int y)
{
    if (x >= 0 && y >= 0 && y < m && x < n)
        return true;
    return false;
}

int getid(char ch)
{
    if (ch == '-')
        return 0;
    if (ch == '|')
        return 1;
    if (ch == '\\')
        return 2;
    return 3;
}

bool work()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (map[i][j] != '.')
                vis[getid(map[i][j])]++;
    int temp = 0;
    for (int i = 0; i < 4; i++)
        if (vis[i])
            temp++;
    if (temp != 1)
        return false;
    int x = -1, y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (map[i][j] != '.')
            {
                x = i;
                y = j;
                break;
            }
        if (x != -1)
            break;
    }
    int d = getid(map[x][y]);
    char c = map[x][y];
    temp = 0;
    while (ok(x, y) && map[x][y] == c)
    {
        x += dir[d][0];
        y += dir[d][1];
        temp++;
    }
    return temp == vis[d];
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        input();
        if (work())
            printf("CORRECT\n");
        else
            printf("INCORRECT\n");
    }
    return 0;
}
