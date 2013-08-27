#include<cstdio>

int arr[15];
int ans[1005];
int left, right;
bool flag;
int m;
void dfs(int k, int num){
    if (k == m){
        flag = true;
        printf("YES\n");
        for (int i = 0; i < m - 1; i++){
            printf("%d ", ans[i]);
        }
        printf("%d\n", ans[m-1]);
        return ;
    }
    for (int i = 1; i <= 10; i++){
        if (i == num) continue;
        if (arr[i] == 1){
            if (k % 2 == 0){
                if (left + i > right){
                    left += i;
                    ans[k] = i;
                    dfs(k+1, i);
                    left -= i;
                    if (flag)
                        return ;
                }
            }else{
                if (left < right + i){
                    right += i;
                    ans[k] = i;
                    dfs(k+1, i);
                    right -= i;
                    if (flag)
                        return;
                }
            }
        }
    }
}
int main()
{
    char str[15];
    scanf("%s", str);
    scanf("%d", &m);
    for (int i = 0; i < 10; i++){
        arr[i+1] = str[i] - '0';
    }
    flag = false;
    dfs(0, 0);
    if (flag == false)
        printf("NO\n");
    return 0;
}
