#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
    int n, k;
    while (1){
        scanf("%d %d", &n, &k);
        if (n == 0 && k == 0) break;
        bool flag = false;
        for (int i = 1; i <= k; i++){
            if ((n - 1 - i) % (k + 1) == 0){
                flag = true;
                break;
            }
        }
        if (flag)
            printf("Tang\n");
        else
            printf("Jiang\n");
    }
    return 0;
}
