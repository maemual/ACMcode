#include<cstdio>
using namespace std;

#define MAX_LEN 100005
int n;
int arr[MAX_LEN];
int brr[MAX_LEN];
int main()
{
    int m;
    int x;
    while (scanf("%d", &n) != EOF){
        for (int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        for (int i = 0; i < n; i++)
            scanf("%d", &brr[i]);

        if (n > 2)
            arr[2] = brr[1] - brr[0];
        for (int i = 5; i < n; i += 3){
            arr[i] = brr[i-1] - brr[i-2] - arr[i-3];
        }
        bool flag = false;
        if (arr[0] != -1){
            arr[1] = brr[0] - arr[0];
            for (int i = 2; i < n; i++)
                arr[i] = brr[i-1] - arr[i-1] - arr[i-2];
            flag = true;
        }else if (arr[1] != -1){
            arr[0] = brr[0] - arr[1];
            for (int i = 2; i < n; i++)
                arr[i] = brr[i-1] - arr[i-1] - arr[i-2];
            flag = true;
        }else if (arr[n-1] != -1){
            arr[n-2] = brr[n-1] - arr[n-1];
            for (int i = n - 3; i >= 0; i--)
                arr[i] = brr[i+1] - arr[i+1] - arr[i+2];
            flag = true;
        }else if (arr[n-2] != -1){
            arr[n-1] = brr[n-1] - arr[n-2];
            for (int i = n - 3; i >= 0; i--)
                arr[i] = brr[i+1] - arr[i+1] - arr[i+2];
            flag = true;
        }
        if (flag){
            scanf("%d", &m);
            for (int i = 0; i < m; i++){
                scanf("%d", &x);
                printf("%d\n", arr[x]);
            }
            continue;
        }
        int s = -1;
        for (int i = 0; i < n-1; i++){
            if (arr[i] != -1 && arr[i+1] != -1){
                s = i;
                break;
            }
        }
        if (s != -1){
            for (int i = s + 2; i < n; i++)
                arr[i] = brr[i-1] - arr[i-1] - arr[i-2];
            for (int i = s - 1; i >= 0; i--)
                arr[i] = brr[i+1] - arr[i+1] - arr[i+2];
            flag = true;
        }
        if (flag){
            scanf("%d", &m);
            for (int i = 0; i < m; i++){
                scanf("%d", &x);
                printf("%d\n", arr[x]);
            }
            continue;
        }
        scanf("%d", &m);
        for (int i = 0; i < m; i++){
            scanf("%d", &x);
            if (arr[x] != -1)
                printf("%d\n", arr[x]);
            else{
                int ans = brr[x];
                if (x+1 < n && arr[x+1] != -1)
                    ans -= arr[x+1];
                if (x-1 >= 0 && arr[x-1] != -1)
                    ans -= arr[x-1];
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
