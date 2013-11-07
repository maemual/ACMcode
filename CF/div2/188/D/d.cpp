#include <cstdio>
#include <iostream>
#include <string.h>

using namespace std;

#define MAX_LEN 200

int mmap[MAX_LEN][MAX_LEN];

void dfs(int x, int y){
    if (mmap[x][y] < 3)
        mmap[x][y]++;
    else{
        mmap[x][y] = 0;
        dfs(x + 1, y);
        dfs(x - 1, y);
        dfs(x, y + 1);
        dfs(x, y - 1);
    }
}
int main()
{
    int n, t;
    cin >> n >> t;
    memset(mmap, 0, sizeof(mmap));
    for (int i = 0; i < n; ++i){
        dfs(0 + MAX_LEN / 2, 0 + MAX_LEN / 2);
    }
    int x, y;
    for (int i = 0; i < t; i++){
        cin >> x >> y;
        if (x > 70|| y > 70 || x <= -70 || y <= -70)
            cout << 0 << endl;
        else
            cout << mmap[x + MAX_LEN / 2][y + MAX_LEN / 2] << endl;
    }
    return 0;
}
