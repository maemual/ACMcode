#include<cstdio>
#include<string.h>

using namespace std;

#define MAX_LEN 1005

struct animal{
    int x, y;
    int dir;
    bool still;
}donkey, tiger;

int mmap[MAX_LEN][MAX_LEN];
bool visd[MAX_LEN][MAX_LEN];
bool vist[MAX_LEN][MAX_LEN];

int n;
int dx[] = {0,1, 0,-1};
int dy[] = {1,0,-1, 0};

void init(){
    donkey.x = donkey.y = 0;
    donkey.dir = 0;
    tiger.x = tiger.y = 0;
    tiger.dir = 0;
    donkey.still = false;
    tiger.still = false;
    memset(mmap, 0, sizeof(mmap));
    memset(visd, 0, sizeof(visd));
    memset(vist, 0, sizeof(vist));
}
bool isMeet(){
    if (donkey.x == tiger.x && donkey.y == tiger.y)
        return true;
    return false;
}
bool isStill(){
    if (donkey.still && tiger.still)
        return true;
    return false;
}
bool donkeyCanMove(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    if (visd[x][y])
        return false;
    return true;
}
bool tigerCanMove(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    if (vist[x][y])
        return false;
    return true;
}
void donkey_move(){
    if (donkey.still)
        return ;
    int next_x = donkey.x + dx[donkey.dir];
    int next_y = donkey.y + dy[donkey.dir];
    if (donkeyCanMove(next_x, next_y)){
        donkey.x = next_x;
        donkey.y = next_y;
        visd[donkey.x][donkey.y] = true;
    }else{
        donkey.dir = (donkey.dir + 1) % 4;
        next_x = donkey.x + dx[donkey.dir];
        next_y = donkey.y + dy[donkey.dir];
        if (donkeyCanMove(next_x, next_y)){
            donkey.x = next_x;
            donkey.y = next_y;
            visd[donkey.x][donkey.y] = true;
        }else{
            donkey.still = true;
        }
    }
}
void tiger_move(){
    if (tiger.still)
        return ;
    int next_x = tiger.x + dx[tiger.dir];
    int next_y = tiger.y + dy[tiger.dir];
    if (tigerCanMove(next_x, next_y)){
        tiger.x = next_x;
        tiger.y = next_y;
        vist[tiger.x][tiger.y] = true;
    }else{
        tiger.dir = (tiger.dir + 4 - 1) % 4;
        next_x = tiger.x + dx[tiger.dir];
        next_y = tiger.y + dy[tiger.dir];
        if (tigerCanMove(next_x, next_y)){
            tiger.x = next_x;
            tiger.y = next_y;
            vist[tiger.x][tiger.y] = true;
        }else{
            tiger.still = true;
        }
    }
}
int main()
{
    while (1){
        scanf("%d", &n);
        if (n == 0) break;
        init();
        scanf("%d%d%d", &donkey.x, &donkey.y, &donkey.dir);
        scanf("%d%d%d", &tiger.x, &tiger.y, &tiger.dir);
        visd[donkey.x][donkey.y] = true;
        vist[tiger.x][tiger.y] = true;
        bool meet = false;
        bool still = false;
        while (1){
            if (isMeet()){
                meet = true;
                break;
            }
            if (isStill()){
                still = true;
                break;
            }
            donkey_move();
            tiger_move();
        }
        if (meet){
            printf("%d %d\n", donkey.x, donkey.y);
        }else if (still){
            printf("-1\n");
        }
    }
    return 0;
}
