#include <stdio.h>
#include <string.h>
#define MAX_LEN 65
 
int main(){
    int n, i, id, ans;
    char str[MAX_LEN];
    int vis[MAX_LEN], tan[MAX_LEN];
    while(scanf("%d",&n) && n){
        memset(vis, 0, sizeof(vis));
        memset(tan, 0, sizeof(tan));
		scanf("%s",str);
        ans = 0;
		int len = strlen(str);
        for(i = 0; i < len; i ++){
            id = str[i] - 'A';
            if(!vis[id]){
                vis[id] = 1;
                if(n > 0){
                    n --;
                    tan[id] = 1;
                }else ans++;
            }else{
                if(tan[id]) n ++;
            }
        }
        if(ans == 0)
		  printf("All customers tanned successfully.\n");
        else 
		  printf("%d customer(s) walked away.\n", ans);
    }
    return 0;
}
