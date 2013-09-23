#include<cstdio>
#include<string.h>
using namespace std;

#define MAX_LEN 105
int n;
int mmap[MAX_LEN][MAX_LEN];
int leftnode[MAX_LEN], rightnode[MAX_LEN], tmpnode[MAX_LEN];
int leftcnt, rightcnt, tmpcnt;
bool canLeft(int x){
    for (int i = 0; i < leftcnt; i++){
        if (mmap[x][leftnode[i]] == 0)
            return false;
    }
    return true;
}
bool canRight(int x){
    for (int i = 0; i < rightcnt; i++){
        if (mmap[x][rightnode[i]] == 0)
            return false;
    }
    return true;
}
int main()
{
    int x;
    while (scanf("%d", &n) != EOF){
        memset(mmap, 0, sizeof(mmap));
        memset(leftnode, 0, sizeof(leftnode));
        memset(rightnode, 0, sizeof(rightnode));
        memset(tmpnode, 0, sizeof(tmpnode));
        leftcnt = 0, rightcnt = 0, tmpcnt = 0;
        for (int i = 1; i <= n; i++){
           while (1) {
               scanf("%d", &x);
               if (x == 0)
                   break;
               mmap[i][x] = 1;
           }
        }
        //消去单向边
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                if (!(mmap[i][j] == 1 && mmap[j][i] == 1)){
                    mmap[i][j] = mmap[j][i] = 0;
                }
            }
        }
        //for (int i = 1; i <= n; i++){
        //    for (int j = 1; j <= n; j++){
        //        printf("%d  ", mmap[i][j]);
        //    }
        //    printf("\n");
        //}
        //寻找不相邻的两个点
        int s = 0, e = 0;
        for (int i = 1; i <= n; i++){
            for (int j = i + 1; j <= n; j++){
                if (mmap[i][j] == 0 && mmap[j][i] == 0){
                    s = i;
                    e = j;
                    break;
                }
            }
            if (s != 0 && e != 0)
                break;
        }
        if (s == 0 && e == 0){
            printf("YES\n");
            continue;
        }
        leftnode[leftcnt++] = s;
        rightnode[rightcnt++] = e;
        //将只属于一边的点加入到点集中
        for (int i = 1; i <= n; i++){
            if (i == s || i == e) continue;
            if (mmap[s][i] == 1 && mmap[e][i] == 0)
                leftnode[leftcnt++] = i;
            else if (mmap[s][i] == 0 && mmap[e][i] == 1)
                rightnode[rightcnt++] = i;
            else if (mmap[s][i] == 1 && mmap[e][i] == 1)
                tmpnode[tmpcnt++] = i;
        }
        bool flag = true;
        for (int i = 0; i < tmpcnt; i++){
            bool cleft = canLeft(tmpnode[i]), cright = canRight(tmpnode[i]);
            if (cleft && !cright){
                leftnode[leftcnt++] = tmpnode[i];
            }else if (!cleft && cright){
                rightnode[rightcnt++] = tmpnode[i];
            }else if (cleft && cright){
                leftnode[leftcnt++] = tmpnode[i];
            }else{
                flag = false;
                break;
            }
        }
        //for (int i = 0; i < leftcnt; i++)
        //    printf("%d  ", leftnode[i]);
        //printf("\n");
        //for (int i = 0; i < rightcnt; i++)
        //    printf("%d  ", rightnode[i]);
        //printf("\n");
        if (leftcnt + rightcnt != n)
            flag = false;
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
