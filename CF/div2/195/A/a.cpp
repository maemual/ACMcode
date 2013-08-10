#include<cstdio>
#include<cstdlib>
#include<iostream>
using namespace std;

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    int c = abs(x) + abs(y);
    if (x > 0 && y > 0){
        printf("0 %d %d 0\n", c, c);
    }else if (x > 0 && y < 0){
        printf("0 %d %d 0\n", -c, c);
    }else if (x < 0 && y > 0){
        printf("%d 0 0 %d\n", -c, c);
    }else{
        printf("%d 0 0 %d\n", -c, -c);
    }
    return 0;
}
