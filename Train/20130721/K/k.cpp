#include<iostream>
#include<cstdio>
using namespace std;

struct node{
    int x, y;
    int dir;
    int speed;
    int turn;
};
node tom, jerry;
int n;
int k;
int dx[] = {0,1, 0,-1};
int dy[] = {1,0,-1, 0};
int main()
{
    while (1){
        scanf("%d", &n);
        getchar();
        if (n == 0)
            break;
        char ch;
        scanf("%c %d %d", &ch, &tom.speed, &tom.turn);
        getchar();
        switch (ch){
            case 'E':tom.dir = 0;break;
            case 'S':tom.dir = 1;break;
            case 'W':tom.dir = 2;break;
            case 'N':tom.dir = 3;break;
            default:break;
        }
        scanf("%c %d %d", &ch, &jerry.speed, &jerry.turn);
        switch (ch){
            case 'E':jerry.dir = 0;break;
            case 'S':jerry.dir = 1;break;
            case 'W':jerry.dir = 2;break;
            case 'N':jerry.dir = 3;break;
            default:break;
        }
        scanf("%d", &k);
        tom.x = tom.y = 1;
        jerry.x = jerry.y = n;
        int nextx, nexty;
        int t;
        bool flag = true;
        for (int i = 0; i < k; ++i)
        {
            if (tom.x == jerry.x && tom.y == jerry.y){
                t = tom.dir;
                tom.dir = jerry.dir;
                jerry.dir = t;
                flag = false;
            }
            if (flag && i > 0 && i % tom.turn == 0){
                tom.dir = (tom.dir + 3) % 4;
            }
            for (int j = 0; j < tom.speed; j++){
                nextx = tom.x + dx[tom.dir];
                nexty = tom.y + dy[tom.dir];
                if (nextx < 1 || nexty < 1 || nextx > n || nexty > n) {
                    tom.dir = (tom.dir + 2) % 4;
                    nextx = tom.x + dx[tom.dir];
                    nexty = tom.y + dy[tom.dir];
                }
                tom.x = nextx;
                tom.y = nexty;
            }
            
            if (flag && i > 0 && i % jerry.turn == 0){
                jerry.dir = (jerry.dir + 3) % 4;
            }
            for (int j = 0; j < jerry.speed; j++){
                nextx = jerry.x + dx[jerry.dir];
                nexty = jerry.y + dy[jerry.dir];
                if (nextx < 1 || nexty < 1 || nextx > n || nexty > n) {
                    jerry.dir = (jerry.dir + 2) % 4;
                    nextx = jerry.x + dx[jerry.dir];
                    nexty = jerry.y + dy[jerry.dir];
                }
                jerry.x = nextx;
                jerry.y = nexty;
            }
            flag = true;            
        }
        printf("%d %d\n", tom.x, tom.y);
        printf("%d %d\n", jerry.x, jerry.y);
    }
    return 0;
}
