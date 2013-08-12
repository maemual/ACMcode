/*
ID: maemual
PROB: clocks
LANG: C++
*/

#include<cstdio>
#include<cstring>
#include<vector>
#include<set>
using namespace std;

struct node{
    int state;
    int tran;
    int from;
}que[270000], now;
const int move[10] = {0, 18911232, 19136512, 2363904, 16810048, 2134536, 262657, 36936, 73, 4617};
const int clr = 57521883;
set<int> mset;
set<int>::iterator it;
int main()
{
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
    memset(que, 0, sizeof(que));
    int bits = 0;
    int tmp;
    for (int i = 0; i < 9; i++){
        scanf("%d", &tmp);
        bits <<= 3;
        switch(tmp){
            case 12:bits |= 0;break;
            case  3:bits |= 1;break;
            case  6:bits |= 2;break;
            case  9:bits |= 3;break;
        }
    }
    int head = 0, tail = 1;
    que[0].state = bits;
    que[0].from = -1;
    que[0].tran = 0;
    mset.clear();
    mset.insert(que[0].state);
    bool flag = false;
    while (head < tail){
        //now = que[head];
        now.from = head;
        for (int i = 1; i <= 9; i++){
           now.tran = i;
           now.state = (que[head].state + move[i]) & clr;
           it = mset.find(now.state);
           if (it != mset.end()) continue;
           mset.insert(now.state);
           que[tail++] = now;
           if (now.state == 0){
               flag = true;
               break;
           }
        }
        if (flag)
            break;
        head++;
    }
    //printf("%d\n", tail);
    tail--;
    vector<int> vec;
    while (1){
        vec.push_back(que[tail].tran);
        tail = que[tail].from;
        if (tail == -1)
            break;
    }
    for (int i = vec.size() - 2; i >= 1; i--){
        printf("%d ", vec[i]);
    }
    printf("%d\n", vec[0]);
    return 0;
}
