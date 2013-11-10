#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>

using namespace std;

#define MAX_LEN 105
struct point{
    int x, y;
};
point arr[MAX_LEN], brr[MAX_LEN];
char path[MAX_LEN];
inline int _sign(int x){
    return x > 0 ? 1 : (x == 0 ? 0 : -1);
}
int main()
{
    int da, db;
    scanf("%d %d", &da, &db);
    scanf("%s", path);
    int len = strlen(path);
    arr[0].x = 0, arr[0].y = 0;
    for (int i = 0; i < len; ++i){
        if (arr[i].x == da && arr[i].y == db){
            printf("Yes\n");
            return 0;
        }
        if (path[i] == 'U'){
            arr[i+1].x = arr[i].x;
            arr[i+1].y = arr[i].y + 1;
        }else if (path[i] == 'D'){
            arr[i+1].x = arr[i].x;
            arr[i+1].y = arr[i].y - 1;
        }else if (path[i] == 'L'){
            arr[i+1].x = arr[i].x - 1;
            arr[i+1].y = arr[i].y;
        }else if (path[i] == 'R'){
            arr[i+1].x = arr[i].x + 1;
            arr[i+1].y = arr[i].y;
        }
    }
    brr[0].x = arr[len].x;
    brr[0].y = arr[len].y;
    for (int i = 0; i < len; ++i){
        if (brr[i].x == da && brr[i].y == db){
            printf("Yes\n");
            return 0;
        }
        if (path[i] == 'U'){
            brr[i+1].x = brr[i].x;
            brr[i+1].y = brr[i].y + 1;
        }else if (path[i] == 'D'){
            brr[i+1].x = brr[i].x;
            brr[i+1].y = brr[i].y - 1;
        }else if (path[i] == 'L'){
            brr[i+1].x = brr[i].x - 1;
            brr[i+1].y = brr[i].y;
        }else if (path[i] == 'R'){
            brr[i+1].x = brr[i].x + 1;
            brr[i+1].y = brr[i].y;
        }
    }
    int dx1, dx2, dy1, dy2;
    for (int i = 0; i < len; i++){
        dx1 = brr[i].x - arr[i].x;
        dy1 = brr[i].y - arr[i].y;

        dx2 = da - arr[i].x;
        dy2 = db - arr[i].y;

        if (dx1 == 0){
            if (dx2 == 0){
                if (dy1 == 0){
                    if (dy2 == 0){
                        printf("Yes\n");
                        return 0;
                    }
                }else{
                    if (dy2 % dy1 == 0
                        && _sign(dy2) == _sign(dy1)){
                        printf("Yes\n");
                        return 0;
                    }
                }
            }
        }else{
            if (dx2 % dx1 == 0
                && _sign(dx2) == _sign(dx1)){
                if (dy1 == 0){
                    if (dy2 == 0){
                        printf("Yes\n");
                        return 0;
                    }
                }else{
                    if (dy2 % dy1 == 0 &&
                        _sign(dy2) == _sign(dy1)){
                        if (dx2 / dx1 == dy2 / dy1
                            && _sign(dx2) == _sign(dx1)){
                            printf("Yes\n");
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("No\n");
    return 0;
}
