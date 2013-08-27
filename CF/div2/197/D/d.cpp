#include<cstdio>

int p[20];
int arr[300000];
void dfs(int k, int num){
   if (k == -1)
       return ;
   for (int i = p[k]; i <= p[k+1]-1; i++){
        if (num % 2 == 0){
            arr[i] = arr[i*2] | arr[i * 2 + 1];
        }else{
            arr[i] = arr[i*2] ^ arr[i * 2 + 1];
        }
   }
   dfs(k-1, num+1);
}
int main()
{
    int x = 1;
    for (int i = 0; i <= 18; i++){
        p[i] = x;
        x *= 2;
    }
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = p[n]; i <= p[n+1]-1; i++)
        scanf("%d", &arr[i]);
    dfs(n-1, 0);
    int px, b;
    while (m--){
        scanf("%d %d", &px, &b);
        px = p[n] + px - 1;
        arr[px] = b;
        int layer = 0;
        while (px != 1){
            px /= 2;
            if (layer % 2 == 0){
                arr[px] = arr[px * 2] | arr[px * 2 + 1];
            }else{
                arr[px] = arr[px * 2] ^ arr[px * 2 + 1];
            }
            layer++;
        }
        printf("%d\n", arr[1]);
    }
    return 0;
}
