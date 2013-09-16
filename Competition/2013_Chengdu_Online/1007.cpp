#include<cstdio>
using namespace std;

int fac[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

int f(int x){
    int ans = 0;
    int i = 0;
    while (x){
        ans += (x % 10) * fac[i];
        x /= 10;
        i++;
    }
    return ans;
}
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    int cnt = 0;
    //for (int a = 0; a <= 20; a++){
        int fa = f(a);
    //    for (int b = 0; b <= 20; b++){
            cnt = 0;
            for (int i = 0; i <= b; i++){
                if (f(i) <= fa)
                    cnt++;
            }
            printf("%d\n", cnt);
      //  }
      //  printf("\n");
    //}
    //printf("%d\n", cnt);
    return 0;
}
